/*
Example for Pressure8 Click

    Date          : nov 2018.
    Author        : Katarina Perendic

Test configuration PIC :
    
    MCU             : P18F87K22
    Dev. Board      : EasyPIC PRO v7
    PIC Compiler ver : v7.2.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes I2C module and sets INT pin as INPUT and RST pin as OUTPUT
- Application Initialization - Initialization driver init, reset device and set PSI range.
- Application Task - (code snippet) - Reads Pressure data and this data logs to USBUART every 1 sec.

*/

#include "Click_Pressure8_types.h"
#include "Click_Pressure8_config.h"

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_i2cInit( _MIKROBUS1, &_PRESSURE8_I2C_CFG[0] );
    mikrobus_logInit( _LOG_USBUART, 9600 );
    mikrobus_logWrite("--- System Init ---", _LOG_LINE);
    Delay_ms( 100 );
}

void applicationInit()
{
    pressure8_i2cDriverInit( (T_PRESSURE8_P)&_MIKROBUS1_GPIO, (T_PRESSURE8_P)&_MIKROBUS1_I2C, 0x18 );
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