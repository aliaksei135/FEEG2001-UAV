#ifdef __cplusplus
extern "C" {
#endif
    void GPSInit();
//     void GPSRead(float* values);
    void GPSUpdate();
    float getLat();
    float getLng();
    float getSpeed();
    float getCourse();
    float getAlt();
#ifdef __cplusplus
}
#endif