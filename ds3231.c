#include "ds3231.h"

/**
*
*Lee los 7 registros del chip RTC
*
**/
void read_rtc(rtcdata *now){
	i2c_start();
	i2c_write(0xD0);
	i2c_write(0x00);
	i2c_start();
	i2c_write(0xD1);
	now->rtcsec = i2c_read(1);
	now->rtcmin = i2c_read(1);
	now->rtchor = i2c_read(1);
	now->rtcdia = i2c_read(1);
	now->rtcfec = i2c_read(1);
	now->rtcmes = i2c_read(1);
	now->rtcyear= i2c_read(0);
	i2c_stop();
}
