EESchema Schematic File Version 4
EELAYER 30 0
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
L Sensor_Optical_Navigation:PMW3360 U2
U 1 1 5D601417
P 4750 4200
F 0 "U2" H 4750 4965 50  0000 C CNN
F 1 "PMW3360" H 4750 4874 50  0000 C CNN
F 2 "pmw3389:PMW3389" H 4750 4900 50  0001 C CNN
F 3 "" H 4750 4900 50  0001 C CNN
	1    4750 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 3900 3800 3900
Wire Wire Line
	3350 3600 3800 3600
Wire Wire Line
	3800 3900 4250 3900
Connection ~ 3800 3900
$Comp
L Regulator_Linear:TLV70019_SOT23-5 U1
U 1 1 5D60A58A
P 4700 2500
F 0 "U1" H 4700 2842 50  0000 C CNN
F 1 "TLV70019_SOT23-5" H 4700 2751 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 4700 2825 50  0001 C CIN
F 3 "http://www.ti.com/lit/ds/symlink/tlv700.pdf" H 4700 2550 50  0001 C CNN
	1    4700 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 2400 4200 2400
Wire Wire Line
	4400 2500 4300 2500
Wire Wire Line
	4300 2500 4300 2400
Connection ~ 4300 2400
Wire Wire Line
	4300 2400 4400 2400
$Comp
L Device:C C3
U 1 1 5D60C7EB
P 4200 2650
F 0 "C3" H 4315 2696 50  0000 L CNN
F 1 "1uF" H 4315 2605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4238 2500 50  0001 C CNN
F 3 "~" H 4200 2650 50  0001 C CNN
	1    4200 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 2800 4700 2800
Wire Wire Line
	4200 2500 4200 2400
Connection ~ 4200 2400
Wire Wire Line
	4200 2400 4300 2400
Text GLabel 5150 2400 2    50   Input ~ 0
VDD
Wire Wire Line
	5000 2400 5100 2400
$Comp
L Device:C C4
U 1 1 5D60E424
P 5100 2650
F 0 "C4" H 5215 2696 50  0000 L CNN
F 1 "1uF" H 5215 2605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5138 2500 50  0001 C CNN
F 3 "~" H 5100 2650 50  0001 C CNN
	1    5100 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 2800 4700 2800
Connection ~ 4700 2800
Wire Wire Line
	5100 2500 5100 2400
Connection ~ 5100 2400
Wire Wire Line
	5100 2400 5150 2400
Text GLabel 4000 4000 0    50   Input ~ 0
VDD
Wire Wire Line
	4000 4000 4100 4000
Wire Wire Line
	4250 4100 4100 4100
Wire Wire Line
	4100 4100 4100 4000
Connection ~ 4100 4000
Wire Wire Line
	4100 4000 4250 4000
Text Notes 5200 2300 0    50   ~ 0
VDD = 1.9V
Text GLabel 3450 4300 0    50   Input ~ 0
VDD
$Comp
L Device:R R1
U 1 1 5D610921
P 3600 4300
F 0 "R1" V 3393 4300 50  0000 C CNN
F 1 "10K" V 3484 4300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3530 4300 50  0001 C CNN
F 3 "~" H 3600 4300 50  0001 C CNN
	1    3600 4300
	0    1    1    0   
$EndComp
Text GLabel 3750 4450 0    50   Input ~ 0
RESET
Wire Wire Line
	3750 4300 3850 4300
Wire Wire Line
	3750 4450 3850 4450
Wire Wire Line
	3850 4450 3850 4300
Connection ~ 3850 4300
Wire Wire Line
	3850 4300 4250 4300
Text GLabel 5550 3800 2    50   Input ~ 0
VDD
$Comp
L Device:R R2
U 1 1 5D61281E
P 5400 3800
F 0 "R2" V 5193 3800 50  0000 C CNN
F 1 "39" V 5284 3800 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5330 3800 50  0001 C CNN
F 3 "~" H 5400 3800 50  0001 C CNN
	1    5400 3800
	0    1    1    0   
$EndComp
Text GLabel 5250 4000 2    50   Input ~ 0
SS
Text GLabel 5250 4100 2    50   Input ~ 0
MISO
Text GLabel 5250 4200 2    50   Input ~ 0
MOSI
Text GLabel 5250 4300 2    50   Input ~ 0
SCLK
Text GLabel 5250 4400 2    50   Input ~ 0
MOTION
$Comp
L Logic_LevelTranslator:SN74LVC1T45DBV U3
U 1 1 5D618C4E
P 7150 2650
F 0 "U3" H 7450 2500 50  0000 L CNN
F 1 "SN74LVC1T45DBV" H 7450 2400 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 7150 2200 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1t45.pdf" H 6250 2000 50  0001 C CNN
	1    7150 2650
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x08_Male J1
U 1 1 5D61EC1C
P 2050 4100
F 0 "J1" H 2022 3982 50  0000 R CNN
F 1 "Conn_01x08_Male" H 2022 4073 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 2050 4100 50  0001 C CNN
F 3 "~" H 2050 4100 50  0001 C CNN
	1    2050 4100
	-1   0    0    1   
$EndComp
Text GLabel 1850 3700 0    50   Input ~ 0
RESET
Text GLabel 3200 3600 0    50   Input ~ 0
GND
Text GLabel 4250 4400 0    50   Input ~ 0
GND
Wire Wire Line
	3200 3600 3350 3600
Connection ~ 3350 3600
Text GLabel 1100 3800 0    50   Input ~ 0
GND
Text GLabel 1850 3900 0    50   Input ~ 0
MOTION_3.3V
Text GLabel 1850 4000 0    50   Input ~ 0
SS_3.3V
Text GLabel 1850 4100 0    50   Input ~ 0
SLCK_3.3V
Text GLabel 1850 4200 0    50   Input ~ 0
MOIS_3.3V
Text GLabel 1850 4300 0    50   Input ~ 0
MISO_3.3V
Text GLabel 1600 4400 0    50   Input ~ 0
VIN
Text GLabel 6750 2650 0    50   Input ~ 0
MOTION_3.3V
Text GLabel 7550 2650 2    50   Input ~ 0
MOTION
Text GLabel 7000 2200 0    50   Input ~ 0
VIN
Text GLabel 7300 2200 2    50   Input ~ 0
VDD
Wire Wire Line
	7050 2200 7000 2200
Wire Wire Line
	7050 2200 7050 2250
Wire Wire Line
	7250 2250 7250 2200
Wire Wire Line
	7250 2200 7300 2200
Text GLabel 7200 3100 2    50   Input ~ 0
GND
Wire Wire Line
	7150 3050 7150 3100
Wire Wire Line
	7150 3100 7200 3100
Text GLabel 6750 2850 0    50   Input ~ 0
VIN
$Comp
L Logic_LevelTranslator:SN74LVC1T45DBV U6
U 1 1 5D64E165
P 9150 2650
F 0 "U6" H 9450 2500 50  0000 L CNN
F 1 "SN74LVC1T45DBV" H 9450 2400 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 9150 2200 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1t45.pdf" H 8250 2000 50  0001 C CNN
	1    9150 2650
	1    0    0    -1  
$EndComp
$Comp
L Logic_LevelTranslator:SN74LVC1T45DBV U4
U 1 1 5D64FCE5
P 7150 4100
F 0 "U4" H 7450 3950 50  0000 L CNN
F 1 "SN74LVC1T45DBV" H 7450 3850 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 7150 3650 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1t45.pdf" H 6250 3450 50  0001 C CNN
	1    7150 4100
	1    0    0    -1  
$EndComp
$Comp
L Logic_LevelTranslator:SN74LVC1T45DBV U7
U 1 1 5D65085A
P 9150 4150
F 0 "U7" H 9450 4000 50  0000 L CNN
F 1 "SN74LVC1T45DBV" H 9450 3900 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 9150 3700 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1t45.pdf" H 8250 3500 50  0001 C CNN
	1    9150 4150
	1    0    0    -1  
$EndComp
$Comp
L Logic_LevelTranslator:SN74LVC1T45DBV U5
U 1 1 5D65104E
P 8200 5400
F 0 "U5" H 8500 5250 50  0000 L CNN
F 1 "SN74LVC1T45DBV" H 8500 5150 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 8200 4950 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1t45.pdf" H 7300 4750 50  0001 C CNN
	1    8200 5400
	1    0    0    -1  
$EndComp
Text GLabel 9300 2200 2    50   Input ~ 0
VDD
Text GLabel 9300 3700 2    50   Input ~ 0
VDD
Text GLabel 8350 4950 2    50   Input ~ 0
VDD
Text GLabel 8050 4950 0    50   Input ~ 0
VIN
Text GLabel 9000 3700 0    50   Input ~ 0
VIN
Text GLabel 9000 2200 0    50   Input ~ 0
VIN
Text GLabel 8750 2850 0    50   Input ~ 0
VIN
Text GLabel 8750 4350 0    50   Input ~ 0
VIN
Text GLabel 7800 5600 0    50   Input ~ 0
VIN
Text GLabel 9200 3100 2    50   Input ~ 0
GND
Text GLabel 9200 4600 2    50   Input ~ 0
GND
Text GLabel 8250 5850 2    50   Input ~ 0
GND
Wire Wire Line
	8350 4950 8300 4950
Wire Wire Line
	8300 4950 8300 5000
Wire Wire Line
	8200 5800 8200 5850
Wire Wire Line
	8200 5850 8250 5850
Wire Wire Line
	9150 4550 9150 4600
Wire Wire Line
	9150 4600 9200 4600
Wire Wire Line
	9000 3700 9050 3700
Wire Wire Line
	9050 3700 9050 3750
Wire Wire Line
	9300 3700 9250 3700
Wire Wire Line
	9250 3700 9250 3750
Wire Wire Line
	9150 3050 9150 3100
Wire Wire Line
	9150 3100 9200 3100
Wire Wire Line
	9000 2200 9050 2200
Wire Wire Line
	9050 2200 9050 2250
Wire Wire Line
	9300 2200 9250 2200
Wire Wire Line
	9250 2200 9250 2250
Text GLabel 8750 2650 0    50   Input ~ 0
SS_3.3V
Text GLabel 8750 4150 0    50   Input ~ 0
SLCK_3.3V
Text GLabel 6750 4100 0    50   Input ~ 0
MOIS_3.3V
Text GLabel 7800 5400 0    50   Input ~ 0
MISO_3.3V
Text GLabel 6750 4300 0    50   Input ~ 0
VIN
Text GLabel 8600 5400 2    50   Input ~ 0
MISO
Text GLabel 7550 4100 2    50   Input ~ 0
MOSI
Text GLabel 9550 4150 2    50   Input ~ 0
SCLK
Text GLabel 9550 2650 2    50   Input ~ 0
SS
Text GLabel 7200 4550 2    50   Input ~ 0
GND
Text GLabel 7300 3650 2    50   Input ~ 0
VDD
Text GLabel 7000 3650 0    50   Input ~ 0
VIN
Wire Wire Line
	7000 3650 7050 3650
Wire Wire Line
	7050 3650 7050 3700
Wire Wire Line
	7250 3700 7250 3650
Wire Wire Line
	7250 3650 7300 3650
Wire Wire Line
	7150 4500 7150 4550
Wire Wire Line
	7150 4550 7200 4550
$Comp
L power:+3.3V #PWR0101
U 1 1 5D6E368D
P 1750 4700
F 0 "#PWR0101" H 1750 4550 50  0001 C CNN
F 1 "+3.3V" H 1765 4873 50  0000 C CNN
F 2 "" H 1750 4700 50  0001 C CNN
F 3 "" H 1750 4700 50  0001 C CNN
	1    1750 4700
	-1   0    0    1   
$EndComp
Wire Wire Line
	1850 4400 1750 4400
$Comp
L power:GND #PWR0102
U 1 1 5D6E67C3
P 1200 4700
F 0 "#PWR0102" H 1200 4450 50  0001 C CNN
F 1 "GND" H 1205 4527 50  0000 C CNN
F 2 "" H 1200 4700 50  0001 C CNN
F 3 "" H 1200 4700 50  0001 C CNN
	1    1200 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 4700 1750 4400
Connection ~ 1750 4400
Wire Wire Line
	1750 4400 1600 4400
Wire Wire Line
	1100 3800 1200 3800
Wire Wire Line
	1200 4700 1200 3800
Connection ~ 1200 3800
Wire Wire Line
	1200 3800 1850 3800
Wire Wire Line
	8050 4950 8100 4950
Wire Wire Line
	8100 4950 8100 5000
Text GLabel 4100 2400 0    50   Input ~ 0
VIN
$Comp
L Device:C C2
U 1 1 5D6030A6
P 3800 3750
F 0 "C2" H 3915 3796 50  0000 L CNN
F 1 "4.7uF" H 3915 3705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3838 3600 50  0001 C CNN
F 3 "~" H 3800 3750 50  0001 C CNN
	1    3800 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5D602D14
P 3350 3750
F 0 "C1" H 3465 3796 50  0000 L CNN
F 1 "0.1uF" H 3465 3705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3388 3600 50  0001 C CNN
F 3 "~" H 3350 3750 50  0001 C CNN
	1    3350 3750
	1    0    0    -1  
$EndComp
$EndSCHEMATC
