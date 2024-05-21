/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'cpu1' in SOPC Builder design 'MSoC'
 * SOPC Builder design path: E:/Education/Academic/workspaces/CO503-Advanced-Embedded-Systems-Labs/lab04/part01/MSoC.sopcinfo
 *
 * Generated: Tue May 21 19:44:28 IST 2024
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00040820
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x13
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x00020020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x13
#define ALT_CPU_NAME "cpu1"
#define ALT_CPU_RESET_ADDR 0x00020000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00040820
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x13
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x00020020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x13
#define NIOS2_RESET_ADDR 0x00020000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_FIFO
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_QSYS


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart1"
#define ALT_STDERR_BASE 0x410e8
#define ALT_STDERR_DEV jtag_uart1
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart1"
#define ALT_STDIN_BASE 0x410e8
#define ALT_STDIN_DEV jtag_uart1
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart1"
#define ALT_STDOUT_BASE 0x410e8
#define ALT_STDOUT_DEV jtag_uart1
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "MSoC"


/*
 * altera_hostfs configuration
 *
 */

#define ALTERA_HOSTFS_NAME "/mnt/host"


/*
 * fifo1to2A_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo1to2A_in altera_avalon_fifo
#define FIFO1TO2A_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO1TO2A_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO1TO2A_IN_BASE 0x41104
#define FIFO1TO2A_IN_BITS_PER_SYMBOL 16
#define FIFO1TO2A_IN_CHANNEL_WIDTH 8
#define FIFO1TO2A_IN_ERROR_WIDTH 8
#define FIFO1TO2A_IN_FIFO_DEPTH 8
#define FIFO1TO2A_IN_IRQ -1
#define FIFO1TO2A_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO1TO2A_IN_NAME "/dev/fifo1to2A_in"
#define FIFO1TO2A_IN_SINGLE_CLOCK_MODE 1
#define FIFO1TO2A_IN_SPAN 4
#define FIFO1TO2A_IN_SYMBOLS_PER_BEAT 2
#define FIFO1TO2A_IN_TYPE "altera_avalon_fifo"
#define FIFO1TO2A_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO1TO2A_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO1TO2A_IN_USE_AVALONST_SINK 0
#define FIFO1TO2A_IN_USE_AVALONST_SOURCE 0
#define FIFO1TO2A_IN_USE_BACKPRESSURE 1
#define FIFO1TO2A_IN_USE_IRQ 1
#define FIFO1TO2A_IN_USE_PACKET 1
#define FIFO1TO2A_IN_USE_READ_CONTROL 0
#define FIFO1TO2A_IN_USE_REGISTER 0
#define FIFO1TO2A_IN_USE_WRITE_CONTROL 1


/*
 * fifo1to2A_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo1to2A_in_csr altera_avalon_fifo
#define FIFO1TO2A_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO1TO2A_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO1TO2A_IN_CSR_BASE 0x410a0
#define FIFO1TO2A_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO1TO2A_IN_CSR_CHANNEL_WIDTH 8
#define FIFO1TO2A_IN_CSR_ERROR_WIDTH 8
#define FIFO1TO2A_IN_CSR_FIFO_DEPTH 8
#define FIFO1TO2A_IN_CSR_IRQ 2
#define FIFO1TO2A_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define FIFO1TO2A_IN_CSR_NAME "/dev/fifo1to2A_in_csr"
#define FIFO1TO2A_IN_CSR_SINGLE_CLOCK_MODE 1
#define FIFO1TO2A_IN_CSR_SPAN 32
#define FIFO1TO2A_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO1TO2A_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO1TO2A_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO1TO2A_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO1TO2A_IN_CSR_USE_AVALONST_SINK 0
#define FIFO1TO2A_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO1TO2A_IN_CSR_USE_BACKPRESSURE 1
#define FIFO1TO2A_IN_CSR_USE_IRQ 1
#define FIFO1TO2A_IN_CSR_USE_PACKET 1
#define FIFO1TO2A_IN_CSR_USE_READ_CONTROL 0
#define FIFO1TO2A_IN_CSR_USE_REGISTER 0
#define FIFO1TO2A_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo1to2B_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo1to2B_in altera_avalon_fifo
#define FIFO1TO2B_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO1TO2B_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO1TO2B_IN_BASE 0x41100
#define FIFO1TO2B_IN_BITS_PER_SYMBOL 16
#define FIFO1TO2B_IN_CHANNEL_WIDTH 8
#define FIFO1TO2B_IN_ERROR_WIDTH 8
#define FIFO1TO2B_IN_FIFO_DEPTH 8
#define FIFO1TO2B_IN_IRQ -1
#define FIFO1TO2B_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO1TO2B_IN_NAME "/dev/fifo1to2B_in"
#define FIFO1TO2B_IN_SINGLE_CLOCK_MODE 1
#define FIFO1TO2B_IN_SPAN 4
#define FIFO1TO2B_IN_SYMBOLS_PER_BEAT 2
#define FIFO1TO2B_IN_TYPE "altera_avalon_fifo"
#define FIFO1TO2B_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO1TO2B_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO1TO2B_IN_USE_AVALONST_SINK 0
#define FIFO1TO2B_IN_USE_AVALONST_SOURCE 0
#define FIFO1TO2B_IN_USE_BACKPRESSURE 1
#define FIFO1TO2B_IN_USE_IRQ 1
#define FIFO1TO2B_IN_USE_PACKET 1
#define FIFO1TO2B_IN_USE_READ_CONTROL 0
#define FIFO1TO2B_IN_USE_REGISTER 0
#define FIFO1TO2B_IN_USE_WRITE_CONTROL 1


/*
 * fifo1to2B_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo1to2B_in_csr altera_avalon_fifo
#define FIFO1TO2B_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO1TO2B_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO1TO2B_IN_CSR_BASE 0x41080
#define FIFO1TO2B_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO1TO2B_IN_CSR_CHANNEL_WIDTH 8
#define FIFO1TO2B_IN_CSR_ERROR_WIDTH 8
#define FIFO1TO2B_IN_CSR_FIFO_DEPTH 8
#define FIFO1TO2B_IN_CSR_IRQ 3
#define FIFO1TO2B_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define FIFO1TO2B_IN_CSR_NAME "/dev/fifo1to2B_in_csr"
#define FIFO1TO2B_IN_CSR_SINGLE_CLOCK_MODE 1
#define FIFO1TO2B_IN_CSR_SPAN 32
#define FIFO1TO2B_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO1TO2B_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO1TO2B_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO1TO2B_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO1TO2B_IN_CSR_USE_AVALONST_SINK 0
#define FIFO1TO2B_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO1TO2B_IN_CSR_USE_BACKPRESSURE 1
#define FIFO1TO2B_IN_CSR_USE_IRQ 1
#define FIFO1TO2B_IN_CSR_USE_PACKET 1
#define FIFO1TO2B_IN_CSR_USE_READ_CONTROL 0
#define FIFO1TO2B_IN_CSR_USE_REGISTER 0
#define FIFO1TO2B_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo1to2C_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo1to2C_in altera_avalon_fifo
#define FIFO1TO2C_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO1TO2C_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO1TO2C_IN_BASE 0x410fc
#define FIFO1TO2C_IN_BITS_PER_SYMBOL 16
#define FIFO1TO2C_IN_CHANNEL_WIDTH 8
#define FIFO1TO2C_IN_ERROR_WIDTH 8
#define FIFO1TO2C_IN_FIFO_DEPTH 8
#define FIFO1TO2C_IN_IRQ -1
#define FIFO1TO2C_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO1TO2C_IN_NAME "/dev/fifo1to2C_in"
#define FIFO1TO2C_IN_SINGLE_CLOCK_MODE 1
#define FIFO1TO2C_IN_SPAN 4
#define FIFO1TO2C_IN_SYMBOLS_PER_BEAT 2
#define FIFO1TO2C_IN_TYPE "altera_avalon_fifo"
#define FIFO1TO2C_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO1TO2C_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO1TO2C_IN_USE_AVALONST_SINK 0
#define FIFO1TO2C_IN_USE_AVALONST_SOURCE 0
#define FIFO1TO2C_IN_USE_BACKPRESSURE 1
#define FIFO1TO2C_IN_USE_IRQ 1
#define FIFO1TO2C_IN_USE_PACKET 1
#define FIFO1TO2C_IN_USE_READ_CONTROL 0
#define FIFO1TO2C_IN_USE_REGISTER 0
#define FIFO1TO2C_IN_USE_WRITE_CONTROL 1


/*
 * fifo1to2C_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo1to2C_in_csr altera_avalon_fifo
#define FIFO1TO2C_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO1TO2C_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO1TO2C_IN_CSR_BASE 0x41060
#define FIFO1TO2C_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO1TO2C_IN_CSR_CHANNEL_WIDTH 8
#define FIFO1TO2C_IN_CSR_ERROR_WIDTH 8
#define FIFO1TO2C_IN_CSR_FIFO_DEPTH 8
#define FIFO1TO2C_IN_CSR_IRQ 4
#define FIFO1TO2C_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define FIFO1TO2C_IN_CSR_NAME "/dev/fifo1to2C_in_csr"
#define FIFO1TO2C_IN_CSR_SINGLE_CLOCK_MODE 1
#define FIFO1TO2C_IN_CSR_SPAN 32
#define FIFO1TO2C_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO1TO2C_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO1TO2C_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO1TO2C_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO1TO2C_IN_CSR_USE_AVALONST_SINK 0
#define FIFO1TO2C_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO1TO2C_IN_CSR_USE_BACKPRESSURE 1
#define FIFO1TO2C_IN_CSR_USE_IRQ 1
#define FIFO1TO2C_IN_CSR_USE_PACKET 1
#define FIFO1TO2C_IN_CSR_USE_READ_CONTROL 0
#define FIFO1TO2C_IN_CSR_USE_REGISTER 0
#define FIFO1TO2C_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo1to4_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo1to4_in altera_avalon_fifo
#define FIFO1TO4_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO1TO4_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO1TO4_IN_BASE 0x410f8
#define FIFO1TO4_IN_BITS_PER_SYMBOL 16
#define FIFO1TO4_IN_CHANNEL_WIDTH 8
#define FIFO1TO4_IN_ERROR_WIDTH 8
#define FIFO1TO4_IN_FIFO_DEPTH 8
#define FIFO1TO4_IN_IRQ -1
#define FIFO1TO4_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO1TO4_IN_NAME "/dev/fifo1to4_in"
#define FIFO1TO4_IN_SINGLE_CLOCK_MODE 1
#define FIFO1TO4_IN_SPAN 4
#define FIFO1TO4_IN_SYMBOLS_PER_BEAT 2
#define FIFO1TO4_IN_TYPE "altera_avalon_fifo"
#define FIFO1TO4_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO1TO4_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO1TO4_IN_USE_AVALONST_SINK 0
#define FIFO1TO4_IN_USE_AVALONST_SOURCE 0
#define FIFO1TO4_IN_USE_BACKPRESSURE 1
#define FIFO1TO4_IN_USE_IRQ 1
#define FIFO1TO4_IN_USE_PACKET 1
#define FIFO1TO4_IN_USE_READ_CONTROL 0
#define FIFO1TO4_IN_USE_REGISTER 0
#define FIFO1TO4_IN_USE_WRITE_CONTROL 1


/*
 * fifo1to4_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo1to4_in_csr altera_avalon_fifo
#define FIFO1TO4_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO1TO4_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO1TO4_IN_CSR_BASE 0x41040
#define FIFO1TO4_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO1TO4_IN_CSR_CHANNEL_WIDTH 8
#define FIFO1TO4_IN_CSR_ERROR_WIDTH 8
#define FIFO1TO4_IN_CSR_FIFO_DEPTH 8
#define FIFO1TO4_IN_CSR_IRQ 5
#define FIFO1TO4_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define FIFO1TO4_IN_CSR_NAME "/dev/fifo1to4_in_csr"
#define FIFO1TO4_IN_CSR_SINGLE_CLOCK_MODE 1
#define FIFO1TO4_IN_CSR_SPAN 32
#define FIFO1TO4_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO1TO4_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO1TO4_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO1TO4_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO1TO4_IN_CSR_USE_AVALONST_SINK 0
#define FIFO1TO4_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO1TO4_IN_CSR_USE_BACKPRESSURE 1
#define FIFO1TO4_IN_CSR_USE_IRQ 1
#define FIFO1TO4_IN_CSR_USE_PACKET 1
#define FIFO1TO4_IN_CSR_USE_READ_CONTROL 0
#define FIFO1TO4_IN_CSR_USE_REGISTER 0
#define FIFO1TO4_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo1to5_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo1to5_in altera_avalon_fifo
#define FIFO1TO5_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO1TO5_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO1TO5_IN_BASE 0x410f4
#define FIFO1TO5_IN_BITS_PER_SYMBOL 16
#define FIFO1TO5_IN_CHANNEL_WIDTH 8
#define FIFO1TO5_IN_ERROR_WIDTH 8
#define FIFO1TO5_IN_FIFO_DEPTH 8
#define FIFO1TO5_IN_IRQ -1
#define FIFO1TO5_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO1TO5_IN_NAME "/dev/fifo1to5_in"
#define FIFO1TO5_IN_SINGLE_CLOCK_MODE 1
#define FIFO1TO5_IN_SPAN 4
#define FIFO1TO5_IN_SYMBOLS_PER_BEAT 2
#define FIFO1TO5_IN_TYPE "altera_avalon_fifo"
#define FIFO1TO5_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO1TO5_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO1TO5_IN_USE_AVALONST_SINK 0
#define FIFO1TO5_IN_USE_AVALONST_SOURCE 0
#define FIFO1TO5_IN_USE_BACKPRESSURE 1
#define FIFO1TO5_IN_USE_IRQ 1
#define FIFO1TO5_IN_USE_PACKET 1
#define FIFO1TO5_IN_USE_READ_CONTROL 0
#define FIFO1TO5_IN_USE_REGISTER 0
#define FIFO1TO5_IN_USE_WRITE_CONTROL 1


/*
 * fifo1to5_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo1to5_in_csr altera_avalon_fifo
#define FIFO1TO5_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO1TO5_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO1TO5_IN_CSR_BASE 0x41020
#define FIFO1TO5_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO1TO5_IN_CSR_CHANNEL_WIDTH 8
#define FIFO1TO5_IN_CSR_ERROR_WIDTH 8
#define FIFO1TO5_IN_CSR_FIFO_DEPTH 8
#define FIFO1TO5_IN_CSR_IRQ 6
#define FIFO1TO5_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define FIFO1TO5_IN_CSR_NAME "/dev/fifo1to5_in_csr"
#define FIFO1TO5_IN_CSR_SINGLE_CLOCK_MODE 1
#define FIFO1TO5_IN_CSR_SPAN 32
#define FIFO1TO5_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO1TO5_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO1TO5_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO1TO5_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO1TO5_IN_CSR_USE_AVALONST_SINK 0
#define FIFO1TO5_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO1TO5_IN_CSR_USE_BACKPRESSURE 1
#define FIFO1TO5_IN_CSR_USE_IRQ 1
#define FIFO1TO5_IN_CSR_USE_PACKET 1
#define FIFO1TO5_IN_CSR_USE_READ_CONTROL 0
#define FIFO1TO5_IN_CSR_USE_REGISTER 0
#define FIFO1TO5_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo1to6_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo1to6_in altera_avalon_fifo
#define FIFO1TO6_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO1TO6_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO1TO6_IN_BASE 0x410f0
#define FIFO1TO6_IN_BITS_PER_SYMBOL 16
#define FIFO1TO6_IN_CHANNEL_WIDTH 8
#define FIFO1TO6_IN_ERROR_WIDTH 8
#define FIFO1TO6_IN_FIFO_DEPTH 8
#define FIFO1TO6_IN_IRQ -1
#define FIFO1TO6_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO1TO6_IN_NAME "/dev/fifo1to6_in"
#define FIFO1TO6_IN_SINGLE_CLOCK_MODE 1
#define FIFO1TO6_IN_SPAN 4
#define FIFO1TO6_IN_SYMBOLS_PER_BEAT 2
#define FIFO1TO6_IN_TYPE "altera_avalon_fifo"
#define FIFO1TO6_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO1TO6_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO1TO6_IN_USE_AVALONST_SINK 0
#define FIFO1TO6_IN_USE_AVALONST_SOURCE 0
#define FIFO1TO6_IN_USE_BACKPRESSURE 1
#define FIFO1TO6_IN_USE_IRQ 1
#define FIFO1TO6_IN_USE_PACKET 1
#define FIFO1TO6_IN_USE_READ_CONTROL 0
#define FIFO1TO6_IN_USE_REGISTER 0
#define FIFO1TO6_IN_USE_WRITE_CONTROL 1


/*
 * fifo1to6_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo1to6_in_csr altera_avalon_fifo
#define FIFO1TO6_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO1TO6_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO1TO6_IN_CSR_BASE 0x41000
#define FIFO1TO6_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO1TO6_IN_CSR_CHANNEL_WIDTH 8
#define FIFO1TO6_IN_CSR_ERROR_WIDTH 8
#define FIFO1TO6_IN_CSR_FIFO_DEPTH 8
#define FIFO1TO6_IN_CSR_IRQ 7
#define FIFO1TO6_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define FIFO1TO6_IN_CSR_NAME "/dev/fifo1to6_in_csr"
#define FIFO1TO6_IN_CSR_SINGLE_CLOCK_MODE 1
#define FIFO1TO6_IN_CSR_SPAN 32
#define FIFO1TO6_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO1TO6_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO1TO6_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO1TO6_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO1TO6_IN_CSR_USE_AVALONST_SINK 0
#define FIFO1TO6_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO1TO6_IN_CSR_USE_BACKPRESSURE 1
#define FIFO1TO6_IN_CSR_USE_IRQ 1
#define FIFO1TO6_IN_CSR_USE_PACKET 1
#define FIFO1TO6_IN_CSR_USE_READ_CONTROL 0
#define FIFO1TO6_IN_CSR_USE_REGISTER 0
#define FIFO1TO6_IN_CSR_USE_WRITE_CONTROL 1


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER1
#define ALT_TIMESTAMP_CLK TIMER1


/*
 * jtag_uart1 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart1 altera_avalon_jtag_uart
#define JTAG_UART1_BASE 0x410e8
#define JTAG_UART1_IRQ 16
#define JTAG_UART1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART1_NAME "/dev/jtag_uart1"
#define JTAG_UART1_READ_DEPTH 64
#define JTAG_UART1_READ_THRESHOLD 8
#define JTAG_UART1_SPAN 8
#define JTAG_UART1_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART1_WRITE_DEPTH 64
#define JTAG_UART1_WRITE_THRESHOLD 8


/*
 * mem1 configuration
 *
 */

#define ALT_MODULE_CLASS_mem1 altera_avalon_onchip_memory2
#define MEM1_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define MEM1_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define MEM1_BASE 0x20000
#define MEM1_CONTENTS_INFO ""
#define MEM1_DUAL_PORT 0
#define MEM1_GUI_RAM_BLOCK_TYPE "AUTO"
#define MEM1_INIT_CONTENTS_FILE "MSoC_mem1"
#define MEM1_INIT_MEM_CONTENT 1
#define MEM1_INSTANCE_ID "NONE"
#define MEM1_IRQ -1
#define MEM1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MEM1_NAME "/dev/mem1"
#define MEM1_NON_DEFAULT_INIT_FILE_ENABLED 0
#define MEM1_RAM_BLOCK_TYPE "AUTO"
#define MEM1_READ_DURING_WRITE_MODE "DONT_CARE"
#define MEM1_SINGLE_CLOCK_OP 0
#define MEM1_SIZE_MULTIPLE 1
#define MEM1_SIZE_VALUE 131072
#define MEM1_SPAN 131072
#define MEM1_TYPE "altera_avalon_onchip_memory2"
#define MEM1_WRITABLE 1


/*
 * sysid configuration
 *
 */

#define ALT_MODULE_CLASS_sysid altera_avalon_sysid_qsys
#define SYSID_BASE 0x410e0
#define SYSID_ID 4
#define SYSID_IRQ -1
#define SYSID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_NAME "/dev/sysid"
#define SYSID_SPAN 8
#define SYSID_TIMESTAMP 1716300600
#define SYSID_TYPE "altera_avalon_sysid_qsys"


/*
 * timer1 configuration
 *
 */

#define ALT_MODULE_CLASS_timer1 altera_avalon_timer
#define TIMER1_ALWAYS_RUN 0
#define TIMER1_BASE 0x410c0
#define TIMER1_COUNTER_SIZE 32
#define TIMER1_FIXED_PERIOD 0
#define TIMER1_FREQ 50000000
#define TIMER1_IRQ 1
#define TIMER1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER1_LOAD_VALUE 49999
#define TIMER1_MULT 0.0010
#define TIMER1_NAME "/dev/timer1"
#define TIMER1_PERIOD 1
#define TIMER1_PERIOD_UNITS "ms"
#define TIMER1_RESET_OUTPUT 0
#define TIMER1_SNAPSHOT 1
#define TIMER1_SPAN 32
#define TIMER1_TICKS_PER_SEC 1000.0
#define TIMER1_TIMEOUT_PULSE_OUTPUT 0
#define TIMER1_TYPE "altera_avalon_timer"

#endif /* __SYSTEM_H_ */
