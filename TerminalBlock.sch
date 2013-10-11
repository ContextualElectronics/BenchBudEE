EESchema Schematic File Version 2  date 10/11/2013 1:04:35 AM
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:BenchBuddy
LIBS:BenchBuddy-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 8 9
Title ""
Date "11 oct 2013"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 1850 2000 0    60   Input ~ 0
V+_ADJ
Text HLabel 1850 2200 0    60   Input ~ 0
V-_ADJ
Text HLabel 1850 2700 0    60   Output ~ 0
FAN_OUT+
Text HLabel 1850 2950 0    60   Output ~ 0
FAN_OUT-
Text HLabel 1900 3400 0    60   Input ~ 0
TACH_IN
Text HLabel 1900 3800 0    60   Output ~ 0
LED_STRING+
Text HLabel 1900 3950 0    60   Output ~ 0
LED_STRING-
Text HLabel 1900 4400 0    60   Input ~ 0
TC_IN+
Text HLabel 1900 4550 0    60   Input ~ 0
TC_IN-
Text HLabel 2000 6650 0    60   BiDi ~ 0
RELAY_COM
Text HLabel 2000 6900 0    60   BiDi ~ 0
RELAY_NO
Text HLabel 2000 7150 0    60   BiDi ~ 0
RELAY_NC
$Comp
L +3.3V #PWR058
U 1 1 523FFDA7
P 1750 950
F 0 "#PWR058" H 1750 910 30  0001 C CNN
F 1 "+3.3V" H 1750 1060 30  0000 C CNN
F 2 "~" H 1750 950 60  0000 C CNN
F 3 "~" H 1750 950 60  0000 C CNN
	1    1750 950 
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR059
U 1 1 523FFDB6
P 1750 1250
F 0 "#PWR059" H 1750 1340 20  0001 C CNN
F 1 "+5V" H 1750 1340 30  0000 C CNN
F 2 "~" H 1750 1250 60  0000 C CNN
F 3 "~" H 1750 1250 60  0000 C CNN
	1    1750 1250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR060
U 1 1 523FFDC5
P 1750 1550
F 0 "#PWR060" H 1750 1550 30  0001 C CNN
F 1 "GND" H 1750 1480 30  0001 C CNN
F 2 "~" H 1750 1550 60  0000 C CNN
F 3 "~" H 1750 1550 60  0000 C CNN
	1    1750 1550
	1    0    0    -1  
$EndComp
$EndSCHEMATC
