# TCL File Generated by Component Editor 13.1
# Fri Apr 19 07:50:22 IST 2024
# DO NOT MODIFY


# 
# CRC_Custom "CRC_Custom" v1.0
#  2024.04.19.07:50:22
# 
# 

# 
# request TCL package from ACDS 13.1
# 
package require -exact qsys 13.1


# 
# module CRC_Custom
# 
set_module_property DESCRIPTION ""
set_module_property NAME CRC_Custom
set_module_property VERSION 1.0
set_module_property INTERNAL false
set_module_property OPAQUE_ADDRESS_MAP true
set_module_property AUTHOR ""
set_module_property DISPLAY_NAME CRC_Custom
set_module_property INSTANTIATE_IN_SYSTEM_MODULE true
set_module_property EDITABLE true
set_module_property ANALYZE_HDL AUTO
set_module_property REPORT_TO_TALKBACK false
set_module_property ALLOW_GREYBOX_GENERATION false


# 
# file sets
# 
add_fileset QUARTUS_SYNTH QUARTUS_SYNTH "" ""
set_fileset_property QUARTUS_SYNTH TOP_LEVEL CRC_Custom_Instruction
set_fileset_property QUARTUS_SYNTH ENABLE_RELATIVE_INCLUDE_PATHS false
add_fileset_file CRC_Component.v VERILOG PATH C:/Users/ajani/Downloads/CRC_Custom_Instruction_Hardware/CRC_Component.v
add_fileset_file CRC_Custom_Instruction.v VERILOG PATH C:/Users/ajani/Downloads/CRC_Custom_Instruction_Hardware/CRC_Custom_Instruction.v TOP_LEVEL_FILE

add_fileset SIM_VERILOG SIM_VERILOG "" ""
set_fileset_property SIM_VERILOG TOP_LEVEL CRC_Custom_Instruction
set_fileset_property SIM_VERILOG ENABLE_RELATIVE_INCLUDE_PATHS false
add_fileset_file CRC_Component.v VERILOG PATH C:/Users/ajani/Downloads/CRC_Custom_Instruction_Hardware/CRC_Component.v
add_fileset_file CRC_Custom_Instruction.v VERILOG PATH C:/Users/ajani/Downloads/CRC_Custom_Instruction_Hardware/CRC_Custom_Instruction.v

add_fileset SIM_VHDL SIM_VHDL "" ""
set_fileset_property SIM_VHDL TOP_LEVEL CRC_Custom_Instruction
set_fileset_property SIM_VHDL ENABLE_RELATIVE_INCLUDE_PATHS false
add_fileset_file CRC_Component.v VERILOG PATH C:/Users/ajani/Downloads/CRC_Custom_Instruction_Hardware/CRC_Component.v
add_fileset_file CRC_Custom_Instruction.v VERILOG PATH C:/Users/ajani/Downloads/CRC_Custom_Instruction_Hardware/CRC_Custom_Instruction.v


# 
# parameters
# 
add_parameter crc_width INTEGER 32
set_parameter_property crc_width DEFAULT_VALUE 32
set_parameter_property crc_width DISPLAY_NAME crc_width
set_parameter_property crc_width TYPE INTEGER
set_parameter_property crc_width UNITS None
set_parameter_property crc_width HDL_PARAMETER true
add_parameter polynomial_inital STD_LOGIC_VECTOR 4294967295
set_parameter_property polynomial_inital DEFAULT_VALUE 4294967295
set_parameter_property polynomial_inital DISPLAY_NAME polynomial_inital
set_parameter_property polynomial_inital TYPE STD_LOGIC_VECTOR
set_parameter_property polynomial_inital UNITS None
set_parameter_property polynomial_inital ALLOWED_RANGES 0:17179869183
set_parameter_property polynomial_inital HDL_PARAMETER true
add_parameter polynomial STD_LOGIC_VECTOR 79764919
set_parameter_property polynomial DEFAULT_VALUE 79764919
set_parameter_property polynomial DISPLAY_NAME polynomial
set_parameter_property polynomial TYPE STD_LOGIC_VECTOR
set_parameter_property polynomial UNITS None
set_parameter_property polynomial ALLOWED_RANGES 0:17179869183
set_parameter_property polynomial HDL_PARAMETER true
add_parameter reflected_input INTEGER 1
set_parameter_property reflected_input DEFAULT_VALUE 1
set_parameter_property reflected_input DISPLAY_NAME reflected_input
set_parameter_property reflected_input TYPE INTEGER
set_parameter_property reflected_input UNITS None
set_parameter_property reflected_input HDL_PARAMETER true
add_parameter reflected_output INTEGER 1
set_parameter_property reflected_output DEFAULT_VALUE 1
set_parameter_property reflected_output DISPLAY_NAME reflected_output
set_parameter_property reflected_output TYPE INTEGER
set_parameter_property reflected_output UNITS None
set_parameter_property reflected_output HDL_PARAMETER true
add_parameter xor_output STD_LOGIC_VECTOR 4294967295
set_parameter_property xor_output DEFAULT_VALUE 4294967295
set_parameter_property xor_output DISPLAY_NAME xor_output
set_parameter_property xor_output TYPE STD_LOGIC_VECTOR
set_parameter_property xor_output UNITS None
set_parameter_property xor_output ALLOWED_RANGES 0:17179869183
set_parameter_property xor_output HDL_PARAMETER true


# 
# display items
# 


# 
# connection point nios_custom_instruction_slave
# 
add_interface nios_custom_instruction_slave nios_custom_instruction end
set_interface_property nios_custom_instruction_slave clockCycle 0
set_interface_property nios_custom_instruction_slave operands 2
set_interface_property nios_custom_instruction_slave ENABLED true
set_interface_property nios_custom_instruction_slave EXPORT_OF ""
set_interface_property nios_custom_instruction_slave PORT_NAME_MAP ""
set_interface_property nios_custom_instruction_slave CMSIS_SVD_VARIABLES ""
set_interface_property nios_custom_instruction_slave SVD_ADDRESS_GROUP ""

add_interface_port nios_custom_instruction_slave dataa dataa Input 32
add_interface_port nios_custom_instruction_slave n n Input 3
add_interface_port nios_custom_instruction_slave clk_en clk_en Input 1
add_interface_port nios_custom_instruction_slave start start Input 1
add_interface_port nios_custom_instruction_slave done done Output 1
add_interface_port nios_custom_instruction_slave result result Output 32
add_interface_port nios_custom_instruction_slave clk clk Input 1
add_interface_port nios_custom_instruction_slave reset reset Input 1

