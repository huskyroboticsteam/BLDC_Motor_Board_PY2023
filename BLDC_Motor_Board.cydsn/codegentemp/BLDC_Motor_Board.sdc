# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\M4rz4n\Desktop\Husky Robotics\Firmware\BLDC\BLDC_Motor_Board_PY2023\BLDC_Motor_Board.cydsn\BLDC_Motor_Board.cyprj
# Date: Sat, 06 Apr 2024 20:49:05 GMT
#set_units -time ns
create_clock -name {UART_SCBCLK(FFB)} -period 725 -waveform {0 362.5} [list [get_pins {ClockBlock/ff_div_2}]]
create_clock -name {TMC6100_SCBCLK(FFB)} -period 50 -waveform {0 25} [list [get_pins {ClockBlock/ff_div_3}]]
create_clock -name {Current_Sensor_I2C_SCBCLK(FFB)} -period 625 -waveform {0 312.5} [list [get_pins {ClockBlock/ff_div_4}]]
create_clock -name {CyRouted1} -period 25 -waveform {0 12.5} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyExtClk} -period 25 -waveform {0 12.5} [list [get_pins {ClockBlock/ext}]]
create_clock -name {CyIMO} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 25 -waveform {0 12.5} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 25 -waveform {0 12.5} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {UART_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 29 59} [list]
create_generated_clock -name {TMC6100_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 3 5} [list]
create_generated_clock -name {Current_Sensor_I2C_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 25 51} [list]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/hfclk}] -edges {1 400001 800001} [list [get_pins {ClockBlock/udb_div_0}]]


# Component constraints for C:\Users\M4rz4n\Desktop\Husky Robotics\Firmware\BLDC\BLDC_Motor_Board_PY2023\BLDC_Motor_Board.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\M4rz4n\Desktop\Husky Robotics\Firmware\BLDC\BLDC_Motor_Board_PY2023\BLDC_Motor_Board.cydsn\BLDC_Motor_Board.cyprj
# Date: Sat, 06 Apr 2024 20:48:59 GMT
