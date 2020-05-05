/***********************************************************
* Smithsonian Astrophysical Observatory
* Submillimeter Receiver Laboratory
* am
*
* transform.h                   S. Paine rev. 2014 August 26
*
* Declarations for transform.c
************************************************************/

#ifndef AM_TRANSFORM_H
#define AM_TRANSFORM_H

void fft_dif(float*, unsigned long);
void ifft_dit(float*, unsigned long);
void fht_dif(float*, unsigned long);
void fht_dit(float*, unsigned long);
void hilbert(float*, unsigned long);
void bitrev_permute(float*, unsigned long);
void bitrev_permute_real(float*, unsigned long);
void ft_benchmarks(void);

#endif /* AM_TRANSFORM_H */
