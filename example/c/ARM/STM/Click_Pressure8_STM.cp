#line 1 "D:/Clicks_git/P/Pressure_8_click/SW/example/c/ARM/STM/Click_Pressure8_STM.c"
#line 1 "d:/clicks_git/p/pressure_8_click/sw/example/c/arm/stm/click_pressure8_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "d:/clicks_git/p/pressure_8_click/sw/example/c/arm/stm/click_pressure8_config.h"
#line 1 "d:/clicks_git/p/pressure_8_click/sw/example/c/arm/stm/click_pressure8_types.h"
#line 19 "d:/clicks_git/p/pressure_8_click/sw/example/c/arm/stm/click_pressure8_config.h"
const uint32_t _PRESSURE8_I2C_CFG[ 1 ] =
{
 100000
};
#line 1 "d:/clicks_git/p/pressure_8_click/sw/library/__pressure8_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 57 "d:/clicks_git/p/pressure_8_click/sw/library/__pressure8_driver.h"
extern uint8_t _PRESSURE8_DATA_IN_mBar ;
extern uint8_t _PRESSURE8_DATA_IN_hPa ;
extern uint8_t _PRESSURE8_DATA_IN_kPa ;
extern uint8_t _PRESSURE8_DATA_IN_Torr ;
extern uint8_t _PRESSURE8_DATA_IN_mmHg ;
#line 79 "d:/clicks_git/p/pressure_8_click/sw/library/__pressure8_driver.h"
void pressure8_i2cDriverInit( const uint8_t*  gpioObj,  const uint8_t*  i2cObj, uint8_t slave);
#line 86 "d:/clicks_git/p/pressure_8_click/sw/library/__pressure8_driver.h"
void pressure8_gpioDriverInit( const uint8_t*  gpioObj);
#line 96 "d:/clicks_git/p/pressure_8_click/sw/library/__pressure8_driver.h"
void pressure8_readData(uint8_t *outData, uint8_t nData);
#line 104 "d:/clicks_git/p/pressure_8_click/sw/library/__pressure8_driver.h"
float pressure8_getPressure(uint8_t pressureIn);
#line 109 "d:/clicks_git/p/pressure_8_click/sw/library/__pressure8_driver.h"
void pressure8_reset();
#line 116 "d:/clicks_git/p/pressure_8_click/sw/library/__pressure8_driver.h"
uint8_t pressure8_getInterruptState();
#line 123 "d:/clicks_git/p/pressure_8_click/sw/library/__pressure8_driver.h"
uint8_t pressure8_getStatus();
#line 135 "d:/clicks_git/p/pressure_8_click/sw/library/__pressure8_driver.h"
void pressure8_setPSIRange(float PSI_min, float PSI_max);
#line 30 "D:/Clicks_git/P/Pressure_8_click/SW/example/c/ARM/STM/Click_Pressure8_STM.c"
void systemInit()
{
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
 mikrobus_i2cInit( _MIKROBUS1, &_PRESSURE8_I2C_CFG[0] );
 mikrobus_logInit( _LOG_USBUART_A, 9600 );
 mikrobus_logWrite("--- System Init ---", _LOG_LINE);
 Delay_ms( 100 );
}

void applicationInit()
{
 pressure8_i2cDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_I2C, 0x18 );
 pressure8_reset();
 pressure8_setPSIRange(0, 25);
}

void applicationTask()
{
 float PressureData;
 char demoText[ 50 ];

 PressureData = pressure8_getPressure(_PRESSURE8_DATA_IN_mBar);
 FloatToStr(pressureData, demoText);
 mikrobus_logWrite(" Pressure data : ", _LOG_TEXT);
 mikrobus_logWrite(demoText, _LOG_TEXT);
 mikrobus_logWrite(" mBar", _LOG_LINE);
 Delay_ms( 1000 );
}

void main()
{
 systemInit();
 applicationInit();

 while (1)
 {
 applicationTask();
 }
}
