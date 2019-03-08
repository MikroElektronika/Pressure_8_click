/*
    __pressure8_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__pressure8_driver.h"
#include "__pressure8_hal.c"

/* ------------------------------------------------------------------- MACROS */

uint8_t _PRESSURE8_DATA_IN_mBar = 1;
uint8_t _PRESSURE8_DATA_IN_hPa  = 2;
uint8_t _PRESSURE8_DATA_IN_kPa  = 3;
uint8_t _PRESSURE8_DATA_IN_Torr = 4;
uint8_t _PRESSURE8_DATA_IN_mmHg = 5;

/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __PRESSURE8_DRV_I2C__
static uint8_t _slaveAddress;
#endif

static uint8_t _Status;

static uint32_t _OUTPUT_MAX  = 0xE66666;
static uint32_t _OUTPUT_MIN  = 0x19999A;
static float _P_MAX  = 0;
static float _P_MIN  = 25;

float _DATA_IN_mBar = 68.9475729;
float _DATA_IN_hPa  = 68.9475729;
float _DATA_IN_kPa  = 6.89475729;
float _DATA_IN_Torr = 51.7150754;
float _DATA_IN_mmHg = 51.7150754;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __PRESSURE8_DRV_SPI__

void pressure8_spiDriverInit(T_PRESSURE8_P gpioObj, T_PRESSURE8_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __PRESSURE8_DRV_I2C__

void pressure8_i2cDriverInit(T_PRESSURE8_P gpioObj, T_PRESSURE8_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
    
    hal_gpio_rstSet( 1 );
}

#endif
#ifdef   __PRESSURE8_DRV_UART__

void pressure8_uartDriverInit(T_PRESSURE8_P gpioObj, T_PRESSURE8_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

void pressure8_readData(uint8_t *outData, uint8_t nData)
{
    uint8_t writeReg[ 3 ];

    writeReg[ 0 ] = 0xAA;
    writeReg[ 1 ] = 0x00;
    writeReg[ 2 ] = 0x00;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 3, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, outData, nData, END_MODE_STOP);
}

float pressure8_getPressure(uint8_t pressureIn)
{
    volatile uint32_t pressureData;
    volatile uint32_t outCalculate;
    volatile float Pressure;
    uint8_t readData[ 4 ];

    pressure8_readData(readData, 4);

    pressureData = (readData[ 1 ]);
    pressureData <<= 16;
    pressureData |= (readData[ 2 ] << 8);
    pressureData |= readData[ 3 ];
    _Status = readData[ 0 ];
    
    pressureData = (pressureData - _OUTPUT_MIN)*(_P_MAX - _P_MIN);
    outCalculate = _OUTPUT_MAX - _OUTPUT_MIN ;
    
    Pressure = ((double)pressureData / (double)outCalculate) + _P_MIN ;
    
    if((pressureIn == _PRESSURE8_DATA_IN_mBar) || (pressureIn == _PRESSURE8_DATA_IN_hPa))
    {
        Pressure *= _DATA_IN_mBar;
    }
    else if((pressureIn == _PRESSURE8_DATA_IN_Torr) || (pressureIn == _PRESSURE8_DATA_IN_mmHg))
    {
        Pressure *= _DATA_IN_Torr;
    }
    else
    {
        Pressure *= _DATA_IN_kPa;
    }
    
    return pressure;
}

void pressure8_reset()
{
    hal_gpio_rstSet( 0 );
    Delay_100ms();
    hal_gpio_rstSet( 1 );
    Delay_10ms();
}

uint8_t pressure8_getInterruptState()
{
    return hal_gpio_intGet();
}

uint8_t pressure8_getStatus()
{
    return _Status;
}

void pressure8_setPSIRange(float PSI_min, float PSI_max)
{
   _P_MAX = PSI_max;
   _P_MIN = PSI_min;
}

/* -------------------------------------------------------------------------- */
/*
  __pressure8_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */