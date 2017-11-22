/*
 * Copyright (C) 2007-2015 FAUmachine Team <info@faumachine.org>.
 * This program is free software. You can redistribute it and/or modify it
 * under the terms of the GNU General Public License, either version 2 of
 * the License, or (at your option) any later version. See COPYING.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sig_std_logic.h"

unsigned int
sig_std_logic_resolve(unsigned int val0, unsigned int val1)
{
	int16_t mv0;
	uint16_t s0;
	int16_t mv1;
	uint16_t s1;
	unsigned int res;

	mv0 = SIG_mV(val0);
	s0 = SIG_mA(val0);
	mv1 = SIG_mV(val1);
	s1 = SIG_mA(val1);

	if (val0 == SIG_STD_LOGIC_U
	 || val1 == SIG_STD_LOGIC_U) {
		res = SIG_STD_LOGIC_U;
	} else if (s0 < s1) {
		res = SIG_COMB(mv1, s1);
	} else if (s1 < s0) {
		res = SIG_COMB(mv0, s0);
	} else if (mv0 == mv1) {
		res = SIG_COMB(mv0, s0);
	} else {
		res = SIG_COMB(-1, s0);
	}
#if 0
	assert(res == SIG_STD_LOGIC_U
	    || res == SIG_STD_LOGIC_X
	    || res == SIG_STD_LOGIC_0
	    || res == SIG_STD_LOGIC_1
	    || res == SIG_STD_LOGIC_Z
	    || res == SIG_STD_LOGIC_W
	    || res == SIG_STD_LOGIC_L
	    || res == SIG_STD_LOGIC_H);
#endif

	return res;
}

static unsigned int
sig_std_logic_or(unsigned int val)
{
	if (val == SIG_STD_LOGIC_U
	 || val == SIG_STD_LOGIC_X) {
		return -1;
	} else if (val == SIG_STD_LOGIC_Z) {
		return 0;
	} else {
		val = SIG_mV(val);
		return 1000 <= val;
	}
}

static void
sig_std_logic_flush(struct sig_std_logic *b)
{
	unsigned int i;
	unsigned int nr;

	for (i = 0; i < b->in_count; i++) {
		void (*func)(void *, unsigned int);
		void (*funcN)(void *, int, unsigned int);
		void (*func_boolean)(void *, unsigned int);
		unsigned int new_val;

		new_val = SIG_STD_LOGIC_Z;

		for (nr = 0; nr < b->out_count; nr++) {
			if (b->out[nr].s == b->in[i].s) continue;

			new_val = sig_std_logic_resolve(new_val, b->out[nr].out);
		}

		func = b->in[i].f->set_ext;
		if (func
		 && b->in[i].in != new_val) {
			b->in[i].in = new_val;
			func(b->in[i].s, new_val);
		}
		funcN = b->in[i].f->set_extN;
		if (funcN
		 && b->in[i].in != new_val) {
			b->in[i].in = new_val;
			funcN(b->in[i].s, b->in[i].n, new_val);
		}

		for (nr = 0; nr < b->out_count; nr++) {
			if (b->out[nr].s != b->in[i].s) continue;

			new_val = sig_std_logic_resolve(new_val, b->out[nr].out);
		}

		func = b->in[i].f->std_logic_set;
		if (func
		 && b->in[i].in != new_val) {
			b->in[i].in = new_val;
			func(b->in[i].s, new_val);
		}

		funcN = b->in[i].f->std_logic_setN;
		if (funcN
		 && b->in[i].in != new_val) {
			b->in[i].in = new_val;
			funcN(b->in[i].s, b->in[i].n, new_val);
		}

		func_boolean = b->in[i].f->boolean_or_set;
		if (func_boolean
		 && sig_std_logic_or(b->in[i].in)
				!= sig_std_logic_or(new_val)) {
			b->in[i].in = new_val;
			func_boolean(b->in[i].s, sig_std_logic_or(new_val));
		}
	}
}

void
sig_std_logic_set(struct sig_std_logic *b, void *s, unsigned int val)
{
	unsigned int nr;

	for (nr = 0; ; nr++) {
		if (nr == b->out_count) {
			assert(0);
			break;
		}
		if (b->out[nr].s == s) {
			b->out[nr].out = val;
			break;
		}
	}

	sig_std_logic_flush(b);
}

void
sig_std_logic_or_set(struct sig_std_logic *b, void *s, unsigned int val)
{
	switch (val) {
	case 0: val = SIG_STD_LOGIC_L; break;
	case 1: val = SIG_STD_LOGIC_1; break;
	default: assert(0);
	}
	sig_std_logic_set(b, s, val);
}

void
sig_std_logic_connect_inN(
	struct sig_std_logic *b,
	void *s,
	int n,
	const struct sig_std_logic_funcs *f
)
{
	assert(b);
	assert(b->in_count < sizeof(b->in) / sizeof(b->in[0]));
	assert(s);
	assert(f);
	assert(f->std_logic_set
	    || f->std_logic_setN
	    || f->boolean_or_set
	    || f->set_ext
	    || f->set_extN);

	b->in[b->in_count].s = s;
	b->in[b->in_count].f = f;
	b->in[b->in_count].n = n;
	b->in[b->in_count].in = SIG_STD_LOGIC_U;
	b->in_count++;

	sig_std_logic_flush(b);
}

void
sig_std_logic_connect_in(
	struct sig_std_logic *b,
	void *s,
	const struct sig_std_logic_funcs *f
)
{
	sig_std_logic_connect_inN(b, s, 0, f);
}

void
sig_std_logic_connect_out(
	struct sig_std_logic *b,
	void *s,
	unsigned int val
)
{
	assert(b);
	assert(b->out_count < sizeof(b->out) / sizeof(b->out[0]));
	assert(s);
#if 0
	assert(val == SIG_STD_LOGIC_U
	    || val == SIG_STD_LOGIC_X
	    || val == SIG_STD_LOGIC_0
	    || val == SIG_STD_LOGIC_1
	    || val == SIG_STD_LOGIC_W
	    || val == SIG_STD_LOGIC_L
	    || val == SIG_STD_LOGIC_H
	    || val == SIG_STD_LOGIC_Z);
#endif

	b->out[b->out_count].s = s;
	b->out[b->out_count].out = val;
	b->out_count++;

	sig_std_logic_flush(b);
}

struct sig_std_logic *
sig_std_logic_create(const char *name)
{
	struct sig_std_logic *b;

	b = malloc(sizeof(*b));
	assert(b);
	memset(b, 0, sizeof(*b));

	b->name = strdup(name);
	assert(b->name);
	b->out_count = 0;
	b->in_count = 0;

	return b;
}

void
sig_std_logic_destroy(struct sig_std_logic *b)
{
	assert(b);

	free(b);
}
