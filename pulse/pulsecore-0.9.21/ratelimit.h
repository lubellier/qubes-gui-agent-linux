#ifndef foopulsecoreratelimithfoo
#define foopulsecoreratelimithfoo

/***
  This file is part of PulseAudio.

  Copyright 2009 Lennart Poettering

  PulseAudio is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as
  published by the Free Software Foundation; either version 2.1 of the
  License, or (at your option) any later version.

  PulseAudio is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with PulseAudio; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
  USA.
***/

#include <pulse/sample.h>
#include <pulsecore/macro.h>

typedef struct pa_ratelimit {
    pa_usec_t interval;
    unsigned burst;
    unsigned n_printed, n_missed;
    pa_usec_t begin;
} pa_ratelimit;

#define PA_DEFINE_RATELIMIT(_name, _interval, _burst)   \
    pa_ratelimit _name = {                              \
        .interval = (_interval),                        \
        .burst = (_burst),                              \
        .n_printed = 0,                                 \
        .n_missed = 0,                                  \
        .begin = 0                                      \
    }

#define PA_INIT_RATELIMIT(v, _interval, _burst)         \
    do {                                                \
        pa_ratelimit *r = &(v);                         \
        r->interval = (_interval);                      \
        r->burst = (_burst);                            \
        r->n_printed = 0;                               \
        r->n_missed = 0;                                \
        r->begin = 0;                                   \
    } while (FALSE);

pa_bool_t pa_ratelimit_test(pa_ratelimit *r);

#endif
