#ifdef __cplusplus
extern "C" {
#endif
    void BMP085Init(float press);
    void BMP085Read(float* values);
#ifdef __cplusplus
}
#endif