#ifndef __R8025T_H__
#define __R8025T_H__

//void setupOscillators(void);
//void drv_I2C_init(void);
//uint8_t drv_R8025T_read(uint8_t addr, uint8_t* data, uint8_t len);
//uint8_t drv_R8025T_write(uint8_t addr, uint8_t* data, uint8_t len);
//void drv_R8025T_init(void);
//uint8_t drv_R8025T_check_read(uint8_t* buffer);
void get_rtc_time(INT8U * datetime);
void set_rtc_time(INT8U *new_time);


#endif
