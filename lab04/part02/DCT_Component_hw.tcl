# TCL File Generated by Component Editor 13.1
# Thu Jun 13 11:39:08 IST 2024
# DO NOT MODIFY


# 
# DCT_Component "DCT_Component" v1.0
#  2024.06.13.11:39:07
# 
# 

# 
# request TCL package from ACDS 13.1
# 
package require -exact qsys 13.1


# 
# module DCT_Component
# 
set_module_property DESCRIPTION ""
set_module_property NAME DCT_Component
set_module_property VERSION 1.0
set_module_property INTERNAL false
set_module_property OPAQUE_ADDRESS_MAP true
set_module_property AUTHOR ""
set_module_property DISPLAY_NAME DCT_Component
set_module_property INSTANTIATE_IN_SYSTEM_MODULE true
set_module_property EDITABLE true
set_module_property ANALYZE_HDL AUTO
set_module_property REPORT_TO_TALKBACK false
set_module_property ALLOW_GREYBOX_GENERATION false


# 
# file sets
# 
add_fileset QUARTUS_SYNTH QUARTUS_SYNTH "" ""
set_fileset_property QUARTUS_SYNTH TOP_LEVEL DCT_Custom_Instruction
set_fileset_property QUARTUS_SYNTH ENABLE_RELATIVE_INCLUDE_PATHS false
add_fileset_file DCT_COMPONENT.v VERILOG PATH dct/DCT_COMPONENT.v
add_fileset_file DCT_Custom_Instruction.v VERILOG PATH dct/DCT_Custom_Instruction.v TOP_LEVEL_FILE

add_fileset SIM_VERILOG SIM_VERILOG "" ""
set_fileset_property SIM_VERILOG TOP_LEVEL DCT_Custom_Instruction
set_fileset_property SIM_VERILOG ENABLE_RELATIVE_INCLUDE_PATHS false
add_fileset_file DCT_COMPONENT.v VERILOG PATH dct/DCT_COMPONENT.v
add_fileset_file DCT_Custom_Instruction.v VERILOG PATH dct/DCT_Custom_Instruction.v

add_fileset SIM_VHDL SIM_VHDL "" ""
set_fileset_property SIM_VHDL TOP_LEVEL DCT_Custom_Instruction
set_fileset_property SIM_VHDL ENABLE_RELATIVE_INCLUDE_PATHS false
add_fileset_file DCT_COMPONENT.v VERILOG PATH dct/DCT_COMPONENT.v
add_fileset_file DCT_Custom_Instruction.v VERILOG PATH dct/DCT_Custom_Instruction.v


# 
# parameters
# 
add_parameter c1 INTEGER 1420
set_parameter_property c1 DEFAULT_VALUE 1420
set_parameter_property c1 DISPLAY_NAME c1
set_parameter_property c1 TYPE INTEGER
set_parameter_property c1 UNITS None
set_parameter_property c1 HDL_PARAMETER true
add_parameter c2 INTEGER 1338
set_parameter_property c2 DEFAULT_VALUE 1338
set_parameter_property c2 DISPLAY_NAME c2
set_parameter_property c2 TYPE INTEGER
set_parameter_property c2 UNITS None
set_parameter_property c2 HDL_PARAMETER true
add_parameter c3 INTEGER 1204
set_parameter_property c3 DEFAULT_VALUE 1204
set_parameter_property c3 DISPLAY_NAME c3
set_parameter_property c3 TYPE INTEGER
set_parameter_property c3 UNITS None
set_parameter_property c3 HDL_PARAMETER true
add_parameter c5 INTEGER 805
set_parameter_property c5 DEFAULT_VALUE 805
set_parameter_property c5 DISPLAY_NAME c5
set_parameter_property c5 TYPE INTEGER
set_parameter_property c5 UNITS None
set_parameter_property c5 HDL_PARAMETER true
add_parameter c6 INTEGER 554
set_parameter_property c6 DEFAULT_VALUE 554
set_parameter_property c6 DISPLAY_NAME c6
set_parameter_property c6 TYPE INTEGER
set_parameter_property c6 UNITS None
set_parameter_property c6 HDL_PARAMETER true
add_parameter c7 INTEGER 283
set_parameter_property c7 DEFAULT_VALUE 283
set_parameter_property c7 DISPLAY_NAME c7
set_parameter_property c7 TYPE INTEGER
set_parameter_property c7 UNITS None
set_parameter_property c7 HDL_PARAMETER true
add_parameter s1 INTEGER 3
set_parameter_property s1 DEFAULT_VALUE 3
set_parameter_property s1 DISPLAY_NAME s1
set_parameter_property s1 TYPE INTEGER
set_parameter_property s1 UNITS None
set_parameter_property s1 HDL_PARAMETER true
add_parameter s2 INTEGER 10
set_parameter_property s2 DEFAULT_VALUE 10
set_parameter_property s2 DISPLAY_NAME s2
set_parameter_property s2 TYPE INTEGER
set_parameter_property s2 UNITS None
set_parameter_property s2 HDL_PARAMETER true
add_parameter s3 INTEGER 13
set_parameter_property s3 DEFAULT_VALUE 13
set_parameter_property s3 DISPLAY_NAME s3
set_parameter_property s3 TYPE INTEGER
set_parameter_property s3 UNITS None
set_parameter_property s3 HDL_PARAMETER true


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

add_interface_port nios_custom_instruction_slave clk clk Input 1
add_interface_port nios_custom_instruction_slave reset reset Input 1
add_interface_port nios_custom_instruction_slave dataa dataa Input 32
add_interface_port nios_custom_instruction_slave n n Input 5
add_interface_port nios_custom_instruction_slave clk_en clk_en Input 1
add_interface_port nios_custom_instruction_slave start start Input 1
add_interface_port nios_custom_instruction_slave done done Output 1
add_interface_port nios_custom_instruction_slave result result Output 32

