/*
 * valveEnv.h
 * author : SHW
 */

#ifndef MAIN_VALVEENV_H
#define MAIN_VALVEENV_H
 
// information of arduino pins and i2c address.
#define LCD_ADDR 0x27

// information of sensor number.
#define LEFTSENSOR 10
#define RIGHTSENSOR 20
#define MIDSENSOR 30

// information of servo number.
#define LEFTVALVE 100
#define RIGHTVALVE 200

void LCDClear(void);

#endif
