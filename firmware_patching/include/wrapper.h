/***************************************************************************
 *                                                                         *
 *          ###########   ###########   ##########    ##########           *
 *         ############  ############  ############  ############          *
 *         ##            ##            ##   ##   ##  ##        ##          *
 *         ##            ##            ##   ##   ##  ##        ##          *
 *         ###########   ####  ######  ##   ##   ##  ##    ######          *
 *          ###########  ####  #       ##   ##   ##  ##    #    #          *
 *                   ##  ##    ######  ##   ##   ##  ##    #    #          *
 *                   ##  ##    #       ##   ##   ##  ##    #    #          *
 *         ############  ##### ######  ##   ##   ##  ##### ######          *
 *         ###########    ###########  ##   ##   ##   ##########           *
 *                                                                         *
 *            S E C U R E   M O B I L E   N E T W O R K I N G              *
 *                                                                         *
 * Warning:                                                                *
 *                                                                         *
 * Our software may damage your hardware and may void your hardware’s      *
 * warranty! You use our tools at your own risk and responsibility!        *
 *                                                                         *
 * License:                                                                *
 * Copyright (c) 2015 NexMon Team                                          *
 *                                                                         *
 * Permission is hereby granted, free of charge, to any person obtaining   *
 * a copy of this software and associated documentation files (the         *
 * "Software"), to deal in the Software without restriction, including     *
 * without limitation the rights to use, copy, modify, merge, publish,     *
 * distribute copies of the Software, and to permit persons to whom the    *
 * Software is furnished to do so, subject to the following conditions:    *
 *                                                                         *
 * The above copyright notice and this permission notice shall be included *
 * in all copies or substantial portions of the Software.                  *
 *                                                                         *
 * Any use of the Software which results in an academic publication or     *
 * other publication which includes a bibliography must include a citation *
 * to the author's publication "M. Schulz, D. Wegemer and M. Hollick.      *
 * NexMon: A Cookbook for Firmware Modifications on Smartphones to Enable  *
 * Monitor Mode.".                                                         *
 *                                                                         *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS *
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF              *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  *
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY    *
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,    *
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE       *
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                  *
 *                                                                         *
 * About this file:                                                        *
 * This file contains function prototypes for functions that already exist *
 * in the original firmware of the BCM4339 Wifi chip. With this file, we   *
 * intend to build wrapper functions that can be called directly from C    *
 * after including this header file and linking against the resulting      *
 * object file ../wrapper/wrapper.o. The latter is generated using the     *
 * Makefile ../wrapper/Makefile. Besides the object file, it also creates  *
 * the linker file ../wrapper/wrapper.ld which is based on this header     *
 * file. To make this work, the function prototypes have to be written as  *
 * one line per prototype. Each prototype has to start with the word       *
 * "extern" and end with a comment containing the functions location in    *
 * memory as a hex number. Before the address, there has to be a space.    *                                                       *
 **************************************************************************/

#ifndef WRAPPER_H
#define WRAPPER_H
#include "../include/structs.h"

extern void *dma_rx(void *di); // 0x4E44
extern void dma_rxfill(void *di); // 0x5070
extern signed int dngl_sendpkt(void *sdio, void *frame, int chan); // 0x3520
extern void *memset(void *dst, int value, int len); // 0x803B14
extern int printf(const char *format, ...); // 0x803B60
extern void *wlc_bmac_mctrl(void *wlc_hw, int mask_1, int val); // 0x8457F4
extern int wlc_iovar_op(void *wlc, char *varname, void *params, int p_len, void *arg, int len, char set, void *wlcif); // 0x82ABEC
extern void *wlc_recv(void *wlc, void *p); // 0x12A0C

#endif /*WRAPPER_H*/
