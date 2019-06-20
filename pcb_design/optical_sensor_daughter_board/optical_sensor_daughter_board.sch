EESchema Schematic File Version 4
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L pmw3389:PMW3389 U1
U 1 1 5D08B8B6
P 4950 3800
F 0 "U1" H 4950 4265 50  0000 C CNN
F 1 "PMW3389" H 4950 4174 50  0000 C CNN
F 2 "pmw3389:PMW3389" H 4950 4150 50  0001 C CNN
F 3 "http://www.pixart.com/products-detail/4/PMW3389DM-T3QU" H 4950 4150 50  0001 C CNN
	1    4950 3800
	1    0    0    -1  
$EndComp
Text GLabel 4500 4200 0    50   Input ~ 0
LED_P
Text GLabel 4500 4000 0    50   Input ~ 0
NCS
Text GLabel 4500 3900 0    50   Input ~ 0
MISO
Text GLabel 4500 3800 0    50   Input ~ 0
MOSI
Text GLabel 4500 3700 0    50   Input ~ 0
SCLK
Text GLabel 4500 3600 0    50   Input ~ 0
MOTION
Text GLabel 5400 4200 2    50   Input ~ 0
NRESET
Text GLabel 5400 4100 2    50   Input ~ 0
GPO
Text GLabel 5400 4000 2    50   Input ~ 0
VDDIO
Text GLabel 5400 3900 2    50   Input ~ 0
VDD
Text GLabel 5400 3800 2    50   Input ~ 0
VDCPIX
Text GLabel 5400 4300 2    50   Input ~ 0
GND
Text GLabel 6850 3850 2    50   Input ~ 0
VDCPIX
Text GLabel 6850 4050 2    50   Input ~ 0
VDD
Text GLabel 6850 4250 2    50   Input ~ 0
VDDIO
Text GLabel 6350 4150 0    50   Input ~ 0
GPO
Text GLabel 6350 3950 0    50   Input ~ 0
NRESET
Text GLabel 6350 3750 0    50   Input ~ 0
GND
$Comp
L Connector_Generic:Conn_02x06_Counter_Clockwise J1
U 1 1 5D09CEA6
P 6550 3950
F 0 "J1" H 6600 4367 50  0000 C CNN
F 1 "Conn_02x06_Counter_Clockwise" H 6600 4276 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x06_P2.54mm_Vertical" H 6550 3950 50  0001 C CNN
F 3 "~" H 6550 3950 50  0001 C CNN
	1    6550 3950
	1    0    0    -1  
$EndComp
Text GLabel 6850 4150 2    50   Input ~ 0
MISO
Text GLabel 6350 4250 0    50   Input ~ 0
MOSI
Text GLabel 6850 3950 2    50   Input ~ 0
NCS
Text GLabel 6350 4050 0    50   Input ~ 0
SCLK
Text GLabel 6850 3750 2    50   Input ~ 0
LED_P
Text GLabel 6350 3850 0    50   Input ~ 0
MOTION
$EndSCHEMATC
