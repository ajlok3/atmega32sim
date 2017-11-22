/*
 * Copyright (C) 2007-2015 FAUmachine Team <info@faumachine.org>.
 * This program is free software. You can redistribute it and/or modify it
 * under the terms of the GNU General Public License, either version 2 of
 * the License, or (at your option) any later version. See COPYING.
 */

#ifndef __SIG_STD_LOGIC_H_INCLUDED
#define __SIG_STD_LOGIC_H_INCLUDED

#include <inttypes.h>

#define SIG_COMB(mV, mA)	((((mV) & 0xffff) << 0) | (((mA) & 0xffff) << 16))
#define SIG_mV(val)		((int16_t) ((val) >> 0))
#define SIG_mA(val)		((uint16_t) ((val) >> 16))

#define SIG_STD_LOGIC_U	SIG_COMB(   0,  0)
#define SIG_STD_LOGIC_X	SIG_COMB(  -1, -1)
#define SIG_STD_LOGIC_0	SIG_COMB(   0, -1)
#define SIG_STD_LOGIC_1	SIG_COMB(5000, -1)
#define SIG_STD_LOGIC_Z	SIG_COMB(  -1,  0)
#define SIG_STD_LOGIC_W	SIG_COMB(  -1,  1)
#define SIG_STD_LOGIC_L	SIG_COMB(   0,  1)
#define SIG_STD_LOGIC_H	SIG_COMB(5000,  1)

struct sig_std_logic_funcs {
	void (*boolean_or_set)(void *_cpssp, unsigned int val);
	void (*std_logic_set)(void *_cpssp, unsigned int val);
	void (*std_logic_setN)(void *_cpssp, int n, unsigned int val);
	void (*set_ext)(void *_cpssp, unsigned int val);
	void (*set_extN)(void *_cpssp, int n, unsigned int val);
};

struct sig_std_logic {
	char *name;

	struct {
		void *s;
		const struct sig_std_logic_funcs *f;
		int n;
		unsigned int in;
	} in[32];
	unsigned int in_count;

	struct {
		void *s;
		unsigned int out;
	} out[32];
	unsigned int out_count;
};

extern unsigned int __attribute__((__const__))
sig_std_logic_resolve(unsigned int val0, unsigned int val1);

extern void
sig_std_logic_set(struct sig_std_logic *b, void *s, unsigned int val);
extern void
sig_std_logic_or_set(struct sig_std_logic *b, void *s, unsigned int val);

extern void
sig_std_logic_connect_in(struct sig_std_logic *b,
		void *s, const struct sig_std_logic_funcs *f);
extern void
sig_std_logic_connect_inN(struct sig_std_logic *b,
		void *s, int n, const struct sig_std_logic_funcs *f);
extern void
sig_std_logic_connect_out(struct sig_std_logic *b,
		void *s, unsigned int val);

extern struct sig_std_logic *
sig_std_logic_create(const char *name);
extern void
sig_std_logic_destroy(struct sig_std_logic *sig);

#endif /* __SIG_STD_LOGIC_H_INCLUDED */
