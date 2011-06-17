/************************************************************
 *
 * File mfixed.h
 *
 * Simple Fixed point math
 *
 * 16 bis.16bits
 *
 ************************************************************/

#ifndef _MFIXED
#define _MFIXED

// fixed point taype definition
// This works only for big endian
typedef union {
    struct {
        short h;
        unsigned short l;
    } ;
    int all;
}mfixed;


// fixed point multiplication
mfixed fx_mul  (mfixed A, mfixed B);

// fixed point addition
mfixed fx_add (mfixed A, mfixed B);

#endif
