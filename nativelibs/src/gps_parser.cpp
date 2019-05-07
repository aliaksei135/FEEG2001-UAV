/* GPS parser to parse GPGGA and GPRMC sentences received from GPS module.
 * It is based on a generic parser that parses data from a Start character
 * to an End Character.
 * Message format considered here is:
 * StartChar|Data|CheckChar|Checksum|EndChar
 * The 'Data' field is separated by a parameter called 'separator'
 * The checksum is calculated for the Data field, i.e., for all characters
 * between Start Character and End Character*/

#include <Arduino.h>
#include "gps_parser.h"
#include <string.h>

uint8_T* dataBuffer = NULL;                                              // Declare the buffer

extern "C" void initialSetup(uint8_T bufferSize)
{    
    dataBuffer = (uint8_T*)calloc(bufferSize,sizeof(uint8_T));           // Allocate memory to the buffer
  
    if(NULL == dataBuffer){                                              // Check if memory is allocated to the buffer
        Serial.println("Failed to allocate memory to the buffer");
        printf("Memory not allocated");
        exit(0);
    }
}

extern "C" void releaseBuffer(){
    free(dataBuffer);                                                    // Free the allocated memory
    dataBuffer = NULL;
}

void parseData(uint8_T *rawStream
        , uint32_T *time
        , float *latitude
        , float *longitude
        , uint8_T *noSat
        , double *hdop
        , double *alti
        , double *msl
        , double *speed
        , double *tckAngle
        , uint32_T *date
        , uint8_T bufferSize
        , uint8_T separator
        , int8_T *statusOut){
    
    uint8_T *commaPtr = NULL;                                            // Pointer to present comma
    uint8_T *nextCommaPtr = NULL;                                        // Pointer to next comma
    uint8_T *lastCommaPtr =  NULL;                                       // Pointer to last comma
    
    uint8_T *placeholder = NULL;                                         // Temporary value holder
    int lengthField = 0;                                                   // Length of the temporary holder
    
    int isGPGGA = 0;                                                       // Flag to check if the sentence is GPGGA
    int isGPRMC = 0;                                                       // Flag to check if the sentence is GPRMC
    
    int commaCount = 0;                                                    // Counter for the number of commas encountered
    
    *statusOut = 0;
    
    isGPGGA = strncmp(rawStream, "GPGGA", 5);                            // Is sentence GPGGA?
    isGPRMC = strncmp(rawStream, "GPRMC", 5);                            // Is sentence GPRMC?
    
    int state = -1;                                                      // State variable
    
    // State 1: GPGGA sentence
    // State 2: GPRMC sentence
    
    if (!isGPGGA)                                                        // GPGGA state
        state = 1;
    else if (!isGPRMC)                                                   // GPRMC state
        state = 2;
    else
        state = -1;                                                      // Default state
    
    if (!isGPGGA | !isGPRMC) {
        
        lastCommaPtr = rawStream;                                        // Store the pointer to the last comma
        while(lastCommaPtr != NULL){                                     // Continue until the end of the sentence
            commaPtr = strchr(lastCommaPtr + 1, separator);              // Pointer to the present comma (+1 to avoid the present comma being accounted for)
            nextCommaPtr = strchr(commaPtr + 1, separator);              // Pointer to the next comma
            lengthField = (nextCommaPtr - 1)- (commaPtr + 1) + 1;        // Length of the temporaty placeholder buffer
            
            placeholder = (uint8_T*)calloc(lengthField, sizeof(uint8_T));// Allocate memory to the temporary buffer
                
            if(lengthField > 0 & NULL == placeholder){                   // Check if memory is allocated to the buffer
                                                                         // The placeholder can be NULL if there are no characters between two commas
                
                *statusOut = -4;
                exit(0);
            }
            
            for(int i = 0; i < lengthField; i++){                        // Add the elements to the temporary placeholder buffer
                placeholder[i] = commaPtr[i+1];
            }
            placeholder[lengthField] = '\0';                             // Append a null character at the end
            
            switch(state){
                case 1:
                    //-------------------GPGGA state-----------------------
                    switch(commaCount){                                  // Assign the output elements depending on the number of commas read
                        case 0:
                            *time = (uint32_T)strtol(placeholder, NULL, 10); // TIME
                            break;
                            
                        case 1:
                            *latitude = atof(placeholder);                   // LATITUDE
                            lastCommaPtr = commaPtr;
                            commaPtr = strchr(lastCommaPtr + 1, separator);  // Account for the direction of Latitude
                            // If 'S' then the value is negative
                            // If 'N' then positive
                            commaCount++;
                            if (*(commaPtr + 1) == 83 ){                     // If the character is an 'S'
                                (*latitude) = (*latitude)*(-1);              // Multiply by -1
                            }
                            break;
                            
                        case 3:
                            *longitude = atof(placeholder);                  // LONGITUDE
                            lastCommaPtr = commaPtr;
                            commaPtr = strchr(lastCommaPtr + 1, separator);  // Account for the direction of the longitude
                            // If 'W' the value is negative
                            // If 'E' the value is positive
                            commaCount++;
                            if (*(commaPtr + 1) == 87 ){                     // If the character is 'W'
                                (*longitude) = (*longitude)*(-1);            // Multiply by -1
                            }
                            break;
                            
                        case 5:
                            
                            if (*(commaPtr + 1) == '1'){
                                *statusOut = 1;
                            }
                            else{
                                *time = 0;
                                *latitude = 0;
                                *longitude = 0;
                            }
                            break;
                            
                        case 6:
                            *noSat = (uint8_T)strtoul(placeholder, NULL, 10);// NUMBER OF SATELLITES
                            break;
                            
                        case 7:
                            *hdop = strtod(placeholder, NULL);               // HORIZONTAL DILUTION OF POSITION
                            break;
                            
                        case 8:
                            *alti = strtod(placeholder, NULL);               // ALTITUDE
                            break;
                            
                        case 10:
                            *msl = strtod(placeholder, NULL);                // MEAN SEA LEVEL
                            break;
                            
                        default:
                            break;
                    }
                    break;
                    
                case 2:
                    //------------------GPRMC state------------------------
                    switch(commaCount){                                      // Assign the output elements depending on the number of commas read
                        case 0:                                              // TIME
                            *time = (uint32_T)strtol(placeholder, NULL, 10);
                            break;
                            
                        case 1:
                            if (*(commaPtr + 1) == 'A'){
                                *statusOut = 1;
                            }
                            break;
                            
                        case 2:
                            *latitude = atof(placeholder);                   // LATITUDE
                            lastCommaPtr = commaPtr;
                            commaPtr = strchr(lastCommaPtr + 1, separator);    // Account for the direction of Latitude
                            
                            // If 'S' then the value is negative
                            // If 'N' then positive
                            commaCount++;
                            if (*(commaPtr + 1) == 83 ){                     // If the character is 'S'
                                (*latitude) = (*latitude)*(-1);              // Multiply by -1
                            }
                            break;
                            
                        case 4:
                            *longitude = atof(placeholder);                  // LONGITUDE
                            lastCommaPtr = commaPtr;
                            commaPtr = strchr(lastCommaPtr + 1, separator);  // Account for the direction of Longitude
                            // If 'W' then the value is negative
                            // If 'E' then positive
                            commaCount++;
                            if (*(commaPtr + 1) == 87 ){                     // If the character is 'W'
                                (*longitude) = (*longitude)*(-1);            // Multiply by -1
                            }
                            break;
                            
                        case 6:
                            *speed = strtod(placeholder, NULL);              // SPEED
                            break;
                            
                        case 7:
                            *tckAngle = strtod(placeholder, NULL);           // TRACK ANGLE
                            break;
                            
                        case 8:
                            *date = (uint32_T)strtol(placeholder, NULL, 10);  // DATE
                            break;
                            
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
            free(placeholder);                                           // Free the pointer
            placeholder = NULL;
            
            commaCount++;
            lastCommaPtr = commaPtr;
        }
    }
}

uint8_T fetchChecksum(uint8_T *pointToCheckChar, uint8_T endChar, int8_T *status){
    
    uint8_T *pointToEndChar = NULL;                                      // Location to the end character
    uint8_T *checksumString = NULL;                                      // Checksum ASCII values
    uint8_T checksum = 0;                                                // Value to be returned
    uint8_T checksumLength = 0;                                          // Length between checkChar and endChar
    
    pointToEndChar = strchr(pointToCheckChar, endChar);
    
    checksumLength = (pointToEndChar - 1) - (pointToCheckChar + 1) + 1;  /* The checksum string starts one after the Check Character and ends
     * one character before the End Character.
     * Additional 1 for the '\0' character.*/
    
    checksumString = (uint8_T*)calloc(checksumLength+1, sizeof(uint8_T));  // Allocate the memory to store checksum ASCII characters
    
    if (checksumString == NULL){                                         // If memory not allocated
        *status = -3;                                                    // Indicate on the status output
        printf("Memory not allocated");                                  // Throw an error
        exit(0);                                                         // Exit the program
    }
    
    for(int i = 0; i < checksumLength; i++){                             // Loop over length of checksum received
        
        checksumString[i] = pointToCheckChar[i+1];                       /*  Append to the checksum array.
         * The +1 on RHS is because the characters after checkChar until
         * EndChar is the checksum value*/
    }
    
    checksumString[checksumLength] = '\0';                               // Append NULL charcater at the end of the array
    checksum = (uint8_T)strtoul(checksumString, NULL, 16);               // Convert the received ASCII checksum HEX value to a uint8
    
    free(checksumString);                                                // Free the allocated memory
    checksumString = NULL;
    
    return checksum;                                                     // Return the calculated checksum
}

extern "C" void readData(uint8_T *inData
        , uint8_T dataLength
        , const uint8_T startChar
        , const uint8_T endChar
        , const uint8_T separator
        , const uint8_T checkChar
        , uint8_T *retString
        , const uint8_T bufferSize
        , int8_T *status){
    
    uint8_T presentChar = 0;                                             // Present character
    uint8_T checksum = 0;                                                // Checksum value
    uint8_T *pointToCheckChar = NULL;                                    // Pointer to the check character
    
    static bool storeData = false;                                       // Flag to start storing to an array
    static bool storeChecksum = false;                                   // Flag to start storing checksum
    static int index = 0;                                                // Index of the Data field
    static uint8_T parity = 0;                                           // Parity to be calculated
    
    *status = 0;                                                         // Reset status at every time step
    
    for(int i = 0; i < dataLength; i++){                                 // For each of the element of the string received
        
        presentChar = inData[i];                                         // Present character read from the input string
        
        if (index == bufferSize)                                         // If the buffer is overfull
        {
            memset(dataBuffer,0, bufferSize);                            // Reset the buffer
            parity = 0;                                                  // Reset the parity
            index = 0;                                                   // Reset the index
            
            storeData = false;                                           // Disable storing Data Buffer
            storeChecksum = false;                                       // Disable storing checksum
            
            *status = -2;                                                // Indicate overfull on the status flag
            
            continue;                                                    // Go to waiting for start character state
        }
        
        if (!storeData){                                                 // Waiting for start character
            
            if(presentChar == startChar){                                // If start character is located
                
                storeData = true;                                        // Enable flag to store the values in the Data Buffer
                memset(dataBuffer, 0, bufferSize);                       // Reset the buffer
                parity = 0;                                              // Reset the parity
                continue;                                                // Go to the next character in the for loop
            }
        }
        else{
            /* If another start character is received
             * (as an unexpected behaviour)*/
            if(presentChar == startChar){
                
                // Reset the buffer
                memset(dataBuffer,0, bufferSize);
                // Reset the parity
                parity = 0;
                // Reset the index
                index = 0;
                // Continue to the next character in the for loop
                continue;
            }
            
            /* If the character is the check character, indicate that the
             * next characters will be checksum values*/
            else if(presentChar == checkChar){
                
                // Flag to indicate checksum is to be read
                storeChecksum = true;
            }
            
            /* If the character is the end character then:
             * 1. Stop storing in the Data Buffer
             * 2. Fetch the checksum value from the string
             * 3. Reset the Data buffer and Flags*/
            else if(presentChar == endChar){
                
                // Append to the Data Buffer
                dataBuffer[index] = presentChar;
                // Pointer to the check character
                pointToCheckChar = strchr(dataBuffer, checkChar);
                
                // Fetch the checksum value received from the sentence
                checksum = fetchChecksum(pointToCheckChar, endChar, *status);
                
                // If calculated parity and checksum matches
                if (parity == checksum){
                    
                    // Reset the string to be returned
                    memset(retString, 0, bufferSize);
                    
                    /* Copy the characters between startChar and checkChar
                     * to the output */
                    strncpy(retString, dataBuffer,
                            (pointToCheckChar - dataBuffer));
                    retString[(pointToCheckChar - dataBuffer) +1] = '\0';
                    
                    *status = 1;

                }
                else{
                    
                    // Reset the output
                    memset(retString, 0, bufferSize);
                }
                
                // Reset the buffer
                memset(dataBuffer, 0, bufferSize);
                // Reset the parity
                parity = 0;
                // Reset the index
                index = 0;
                
                // Disable storing of the Data Buffer
                storeData = false;
                // Disable storing checksum
                storeChecksum = false;
                
                continue;
            }
            
            /* If the character is between startChar and checkChar
             * calculate the parity*/
            if (!storeChecksum){
                parity = parity^presentChar;
            }
            
            /* Append the present character to the DataBuffer
             * Appends the characters between startChar and endChar
             * excluding the two*/
            dataBuffer[index++] = presentChar;
        }
    }
}