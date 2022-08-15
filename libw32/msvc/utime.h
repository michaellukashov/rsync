#ifndef LIBW32_MSVC_UTIME_H_INCLUDED
#define LIBW32_MSVC_UTIME_H_INCLUDED
#include <edidentifier.h>

__CPRAGMA_ONCE

/* -*- mode: c; indent-width: 4; -*- */

#if (_MSC_VER >= 1800)
#include <sys/utime.h>
#endif

#endif /*LIBW32_MSVC_UTIME_H_INCLUDED*/
