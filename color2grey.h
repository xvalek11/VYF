#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void color2grey(  float **fpI,          // Input
                  float **fpO,          // Output
                  int d_c, int d_w,int d_h);

struct complex_vec{
    float real_x;
    float real_y;
    float imag_x;
    float imag_y;
};

float vc(float val);
float vl(float val);
float uc(float val);
float ul(float val);

float calculate_D(float** fpI,int w,int h ,int index, int d_w, int d_h);
void amplitude_mod(float *imaginery_part, int w, int h, int chanel);
float frekv_mod(float ** Lab_origin,int pos, int chanel);