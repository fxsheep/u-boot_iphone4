/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (c) 2009 Samsung Electronics.
 * Minkyu Kang <mk7.kang@samsung.com>
 */

#include <asm/arch/cpu.h>
#include <linux/linkage.h>


ENTRY(reset_cpu)
	ldr		r1, =0xBF10202C
	ldr		r3, =0xBF102024
	movs	r0, #0
	movs	r2, #1
	str		r0, [r1]
	str		r2, [r3]
	ldr		r2, =0xBF102020
	mov		r3, #0x80000000
	str		r3, [r2]
	mov		r3, #4
	str		r3, [r1]
	str		r0, [r2]
_loop_forever:
	b	_loop_forever
ENDPROC(reset_cpu)
