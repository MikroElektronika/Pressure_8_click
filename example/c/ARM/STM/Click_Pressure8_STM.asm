_systemInit:
;Click_Pressure8_STM.c,30 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Pressure8_STM.c,32 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
MOVS	R2, #1
MOVS	R1, #7
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_Pressure8_STM.c,33 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #1
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_Pressure8_STM.c,34 :: 		mikrobus_i2cInit( _MIKROBUS1, &_PRESSURE8_I2C_CFG[0] );
MOVW	R0, #lo_addr(__PRESSURE8_I2C_CFG+0)
MOVT	R0, #hi_addr(__PRESSURE8_I2C_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_i2cInit+0
;Click_Pressure8_STM.c,35 :: 		mikrobus_logInit( _LOG_USBUART_A, 9600 );
MOVW	R1, #9600
MOVS	R0, #32
BL	_mikrobus_logInit+0
;Click_Pressure8_STM.c,36 :: 		mikrobus_logWrite("--- System Init ---", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr1_Click_Pressure8_STM+0)
MOVT	R0, #hi_addr(?lstr1_Click_Pressure8_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Pressure8_STM.c,37 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_Pressure8_STM.c,38 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_Pressure8_STM.c,40 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Pressure8_STM.c,42 :: 		pressure8_i2cDriverInit( (T_PRESSURE8_P)&_MIKROBUS1_GPIO, (T_PRESSURE8_P)&_MIKROBUS1_I2C, 0x18 );
MOVS	R2, #24
MOVW	R1, #lo_addr(__MIKROBUS1_I2C+0)
MOVT	R1, #hi_addr(__MIKROBUS1_I2C+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_pressure8_i2cDriverInit+0
;Click_Pressure8_STM.c,43 :: 		pressure8_reset();
BL	_pressure8_reset+0
;Click_Pressure8_STM.c,44 :: 		pressure8_setPSIRange(0, 25);
MOVW	R1, #0
MOVT	R1, #16840
MOV	R0, #0
BL	_pressure8_setPSIRange+0
;Click_Pressure8_STM.c,45 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_Pressure8_STM.c,47 :: 		void applicationTask()
SUB	SP, SP, #56
STR	LR, [SP, #0]
;Click_Pressure8_STM.c,52 :: 		PressureData = pressure8_getPressure(_PRESSURE8_DATA_IN_mBar);
MOVW	R0, #lo_addr(__PRESSURE8_DATA_IN_mBar+0)
MOVT	R0, #hi_addr(__PRESSURE8_DATA_IN_mBar+0)
LDRB	R0, [R0, #0]
BL	_pressure8_getPressure+0
;Click_Pressure8_STM.c,53 :: 		FloatToStr(pressureData, demoText);
ADD	R1, SP, #4
BL	_FloatToStr+0
;Click_Pressure8_STM.c,54 :: 		mikrobus_logWrite(" Pressure data : ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr2_Click_Pressure8_STM+0)
MOVT	R0, #hi_addr(?lstr2_Click_Pressure8_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Pressure8_STM.c,55 :: 		mikrobus_logWrite(demoText, _LOG_TEXT);
ADD	R0, SP, #4
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Pressure8_STM.c,56 :: 		mikrobus_logWrite(" mBar", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr3_Click_Pressure8_STM+0)
MOVT	R0, #hi_addr(?lstr3_Click_Pressure8_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Pressure8_STM.c,57 :: 		Delay_ms( 1000 );
MOVW	R7, #6911
MOVT	R7, #183
NOP
NOP
L_applicationTask2:
SUBS	R7, R7, #1
BNE	L_applicationTask2
NOP
NOP
NOP
;Click_Pressure8_STM.c,58 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #56
BX	LR
; end of _applicationTask
_main:
;Click_Pressure8_STM.c,60 :: 		void main()
SUB	SP, SP, #4
;Click_Pressure8_STM.c,62 :: 		systemInit();
BL	_systemInit+0
;Click_Pressure8_STM.c,63 :: 		applicationInit();
BL	_applicationInit+0
;Click_Pressure8_STM.c,65 :: 		while (1)
L_main4:
;Click_Pressure8_STM.c,67 :: 		applicationTask();
BL	_applicationTask+0
;Click_Pressure8_STM.c,68 :: 		}
IT	AL
BAL	L_main4
;Click_Pressure8_STM.c,69 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
