![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Pressure8 Click

---

- **CIC Prefix**  : PRESSURE8
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : nov 2018.

---


### Software Support

We provide a library for the Pressure8 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2647/pressure-8-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library initializes and defines the I2C bus driver and drivers that offer a choice for writing data in register and reads data form register.
The library includes function for read Pressure data in mBar/hPa/kPa/Torr or mmHg.
The user also has the function for set PSI Range, function for reset device, function for get read Satatus and function for read interrupt state.

Key functions :

- ``` float pressure8_getPressure(uint8_t pressureIn) ``` - Functions for get Pressure data
- ``` void pressure8_reset() ``` - Functions for reset device
- ``` void pressure8_setPSIRange(float PSI_min, float PSI_max) ``` - Functions for set PSI range

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes I2C module and sets INT pin as INPUT and RST pin as OUTPUT
- Application Initialization - Initialization driver init, reset device and set PSI range.
- Application Task - (code snippet) - Reads Pressure data and this data logs to USBUART every 1 sec.


```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2647/pressure-8-click) page.

Other mikroE Libraries used in the example:

- I2C

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.


---
---
