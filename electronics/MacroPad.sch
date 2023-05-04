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
L MacroPad-rescue:ProMicro-Arduino_Pro_Micro U1
U 1 1 60E0C627
P 2450 2750
F 0 "U1" H 2450 3787 60  0000 C CNN
F 1 "ProMicro" H 2450 3681 60  0000 C CNN
F 2 "Arduino_Pro_Micro:ProMicro" H 2550 1700 60  0001 C CNN
F 3 "" H 2550 1700 60  0000 C CNN
	1    2450 2750
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 60E0E5E9
P 5550 2300
F 0 "SW3" H 5550 2585 50  0000 C CNN
F 1 "SW_Push" H 5550 2494 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 5550 2500 50  0001 C CNN
F 3 "~" H 5550 2500 50  0001 C CNN
	1    5550 2300
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW4
U 1 1 60E0FD3D
P 6400 2300
F 0 "SW4" H 6400 2585 50  0000 C CNN
F 1 "SW_Push" H 6400 2494 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 6400 2500 50  0001 C CNN
F 3 "~" H 6400 2500 50  0001 C CNN
	1    6400 2300
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW5
U 1 1 60E10960
P 7400 2300
F 0 "SW5" H 7400 2585 50  0000 C CNN
F 1 "SW_Push" H 7400 2494 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 7400 2500 50  0001 C CNN
F 3 "~" H 7400 2500 50  0001 C CNN
	1    7400 2300
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Coded SW2
U 1 1 60E12352
P 4900 3900
F 0 "SW2" H 4620 3883 50  0000 R CNN
F 1 "SW_Coded" H 4620 3974 50  0000 R CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x05_P2.00mm_Vertical" H 4875 3925 50  0001 C CNN
F 3 "~" H 4875 3925 50  0001 C CNN
	1    4900 3900
	-1   0    0    1   
$EndComp
Wire Wire Line
	3850 1800 3350 1800
Wire Wire Line
	3350 1800 3350 2100
Wire Wire Line
	3350 2100 3150 2100
Wire Wire Line
	4900 1800 4900 2300
Connection ~ 3850 1800
Wire Wire Line
	4900 1800 5750 1800
Wire Wire Line
	5750 1800 5750 2300
Wire Wire Line
	5750 1800 6600 1800
Wire Wire Line
	6600 1800 6600 2300
Connection ~ 5750 1800
Wire Wire Line
	6600 1800 7600 1800
Wire Wire Line
	7600 1800 7600 2300
Connection ~ 6600 1800
Wire Wire Line
	4400 3700 1550 3700
Wire Wire Line
	1550 3700 1550 1700
Wire Wire Line
	1550 1700 3850 1700
Wire Wire Line
	3850 1700 3850 1800
Wire Wire Line
	4400 3800 3850 3800
Wire Wire Line
	3850 3800 3850 2300
Connection ~ 4900 1800
Wire Wire Line
	3850 1800 4900 1800
$Comp
L Switch:SW_Push SW1
U 1 1 60E0D9B2
P 4700 2300
F 0 "SW1" H 4700 2585 50  0000 C CNN
F 1 "SW_Push" H 4700 2494 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 4700 2500 50  0001 C CNN
F 3 "~" H 4700 2500 50  0001 C CNN
	1    4700 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 3000 1200 3000
Wire Wire Line
	1200 3000 1200 4150
Wire Wire Line
	1200 4150 4400 4150
Wire Wire Line
	4400 4000 1350 4000
Wire Wire Line
	1350 4000 1350 2900
Wire Wire Line
	1350 2900 1750 2900
Wire Wire Line
	1750 2800 1450 2800
Wire Wire Line
	1450 2800 1450 3900
Wire Wire Line
	1450 3900 4400 3900
Wire Wire Line
	4500 2300 4500 3350
Wire Wire Line
	4500 3350 6050 3350
Wire Wire Line
	6050 3350 6050 4750
Wire Wire Line
	6050 4750 1050 4750
Wire Wire Line
	1050 4750 1050 2700
Wire Wire Line
	1050 2700 1750 2700
Wire Wire Line
	950  2600 950  4850
Wire Wire Line
	950  4850 6200 4850
Wire Wire Line
	6200 4850 6200 3200
Wire Wire Line
	6200 3200 5350 3200
Wire Wire Line
	5350 3200 5350 2300
Wire Wire Line
	6200 2300 6200 3100
Wire Wire Line
	6200 3100 6350 3100
Wire Wire Line
	6350 3100 6350 5000
Wire Wire Line
	6350 5000 850  5000
Wire Wire Line
	850  5000 850  2500
Wire Wire Line
	850  2500 1750 2500
Wire Wire Line
	950  2600 1750 2600
Wire Wire Line
	1750 2400 750  2400
Wire Wire Line
	750  2400 750  5100
Wire Wire Line
	750  5100 7200 5100
Wire Wire Line
	7200 5100 7200 2300
Wire Wire Line
	3850 1800 3850 1850
NoConn ~ 1750 2000
NoConn ~ 1750 2100
NoConn ~ 1750 2200
NoConn ~ 1750 2300
NoConn ~ 1750 3100
NoConn ~ 3150 3100
NoConn ~ 3150 3000
NoConn ~ 3150 2900
NoConn ~ 3150 2800
NoConn ~ 3150 2700
NoConn ~ 3150 2600
NoConn ~ 3150 2500
NoConn ~ 3150 2400
NoConn ~ 3150 2200
NoConn ~ 3150 2000
$Comp
L power:+5V #PWR02
U 1 1 60E445DA
P 3850 2300
F 0 "#PWR02" H 3850 2150 50  0001 C CNN
F 1 "+5V" H 3865 2473 50  0000 C CNN
F 2 "" H 3850 2300 50  0001 C CNN
F 3 "" H 3850 2300 50  0001 C CNN
	1    3850 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 60E45F5B
P 3850 1850
F 0 "#PWR01" H 3850 1600 50  0001 C CNN
F 1 "GND" H 3855 1677 50  0000 C CNN
F 2 "" H 3850 1850 50  0001 C CNN
F 3 "" H 3850 1850 50  0001 C CNN
	1    3850 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 2300 3150 2300
Connection ~ 3850 2300
$EndSCHEMATC
