#ifdef __cplusplus
extern "C" {
#endif
    void SDLoggerInit();
    void SDLoggerLog(float data[], int size);
    void SDLoggerDestroy();
#ifdef __cplusplus
}
#endif