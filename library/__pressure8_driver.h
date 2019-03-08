/*
    __pressure8_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __pressure8_driver.h
@brief    Pressure8 Driver
@mainpage Pressure8 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   PRESSURE8
@brief      Pressure8 Click Driver
@{

| Global Library Prefix | **PRESSURE8** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **nov 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _PRESSURE8_H_
#define _PRESSURE8_H_

/** 
 * @macro T_PRESSURE8_P
 * @brief Driver Abstract type 
 */
#define T_PRESSURE8_P    const uint8_t*

/** @defgroup PRESSURE8_COMPILE Compilation Config */              /** @{ */

//  #define   __PRESSURE8_DRV_SPI__                            /**<     @macro __PRESSURE8_DRV_SPI__  @brief SPI driver selector */
   #define   __PRESSURE8_DRV_I2C__                            /**<     @macro __PRESSURE8_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __PRESSURE8_DRV_UART__                           /**<     @macro __PRESSURE8_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup PRESSURE8_VAR Variables */                           /** @{ */

extern uint8_t _PRESSURE8_DATA_IN_mBar ;
extern uint8_t _PRESSURE8_DATA_IN_hPa  ;
extern uint8_t _PRESSURE8_DATA_IN_kPa  ;
extern uint8_t _PRESSURE8_DATA_IN_Torr ;
extern uint8_t _PRESSURE8_DATA_IN_mmHg ;

                                                                       /** @} */
/** @defgroup PRESSURE8_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup PRESSURE8_INIT Driver Initialization */              /** @{ */

#ifdef   __PRESSURE8_DRV_SPI__
void pressure8_spiDriverInit(T_PRESSURE8_P gpioObj, T_PRESSURE8_P spiObj);
#endif
#ifdef   __PRESSURE8_DRV_I2C__
void pressure8_i2cDriverInit(T_PRESSURE8_P gpioObj, T_PRESSURE8_P i2cObj, uint8_t slave);
#endif
#ifdef   __PRESSURE8_DRV_UART__
void pressure8_uartDriverInit(T_PRESSURE8_P gpioObj, T_PRESSURE8_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void pressure8_gpioDriverInit(T_PRESSURE8_P gpioObj);
                                                                       /** @} */
/** @defgroup PRESSURE8_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Functions for read data
 *
 * @param[out] outData    Output data buffer
 * @param[in] nData       Number of Bytes
 */
void pressure8_readData(uint8_t *outData, uint8_t nData);

/**
 * @brief Functions for get Pressure data
 *
 * @param[out] pressureIn    Pressure data in ... (mBar, hPa, kPa, mmHg and Torr)
 * @return Pressure data
 */
float pressure8_getPressure(uint8_t pressureIn);

/**
 * @brief Functions for reset device
 */
void pressure8_reset();

/**
 * @brief Functions for get Interrupt pin state
 *
 * @return Interrupt pin state
 */
uint8_t pressure8_getInterruptState();

/**
 * @brief Functions for get read Status
 *
 * @return Status
 */
uint8_t pressure8_getStatus();

/**
 * @brief Functions for set PSI range
 *
 * @param[in] PSI_min    PSI min range
 * @param[in] PSI_max    PSI max range
 *
 * Options:
     - Absolute (0psi to 15psi, 0psi to 25psi(def) and 0psi to 30psi)
     - Gage ( 0psi to 1psi, 0psi to 5pis, 0psi to 15psi and 0psi to 30psi)
 */
void pressure8_setPSIRange(float PSI_min, float PSI_max);




                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Pressure8_STM.c
    @example Click_Pressure8_TIVA.c
    @example Click_Pressure8_CEC.c
    @example Click_Pressure8_KINETIS.c
    @example Click_Pressure8_MSP.c
    @example Click_Pressure8_PIC.c
    @example Click_Pressure8_PIC32.c
    @example Click_Pressure8_DSPIC.c
    @example Click_Pressure8_AVR.c
    @example Click_Pressure8_FT90x.c
    @example Click_Pressure8_STM.mbas
    @example Click_Pressure8_TIVA.mbas
    @example Click_Pressure8_CEC.mbas
    @example Click_Pressure8_KINETIS.mbas
    @example Click_Pressure8_MSP.mbas
    @example Click_Pressure8_PIC.mbas
    @example Click_Pressure8_PIC32.mbas
    @example Click_Pressure8_DSPIC.mbas
    @example Click_Pressure8_AVR.mbas
    @example Click_Pressure8_FT90x.mbas
    @example Click_Pressure8_STM.mpas
    @example Click_Pressure8_TIVA.mpas
    @example Click_Pressure8_CEC.mpas
    @example Click_Pressure8_KINETIS.mpas
    @example Click_Pressure8_MSP.mpas
    @example Click_Pressure8_PIC.mpas
    @example Click_Pressure8_PIC32.mpas
    @example Click_Pressure8_DSPIC.mpas
    @example Click_Pressure8_AVR.mpas
    @example Click_Pressure8_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __pressure8_driver.h

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