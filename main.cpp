#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io_png.h"
#include "color2grey.h"


int main(int argc, char **argv) {


    if (argc != 3) {
        printf("usage: c2g color_image grayscale_image \n");
        exit(-1);
    }

    // read input
    size_t nx,ny,nc;
    float *d_v = NULL;
    d_v = io_png_read_f32(argv[1], &nx, &ny, &nc);
    if (!d_v) {
        printf("error :: %s not found  or not a correct png image \n", argv[1]);
        exit(-1);
    }

    const int d_w = (int) nx;
    const int d_h = (int) ny;
    int d_c = (int) nc;
    if (d_c == 2) {
        d_c = 1;    // we do not use the alpha channel
    }
    if (d_c > 3) {
        d_c = 3;    // we do not use the alpha channel
    }

    int d_wh = d_w * d_h;
    int d_whc = d_c * d_w * d_h;



    // test if image is really a color image even if it has more than one channel
    if (d_c > 1) {

        // dc equals 3
        int i=0;
        while (i < d_wh && d_v[i] == d_v[d_wh + i] && d_v[i] == d_v[2 * d_wh + i ])  {
            i++;
        }

        if (i == d_wh) d_c = 1;

    }

    printf("width: %d, height: %d, chanel: %d\n",d_w,d_h,d_c);

    float **fpI = new float*[d_c];
    float **fpO = new float*[d_c];
    float *greyscale = new float[d_whc];

    for (int ii=0; ii < d_c; ii++) {
        fpI[ii] = &d_v[ii * d_wh];
        fpO[ii] = &greyscale[ii * d_wh];
    }

    color2grey(fpI, fpO, d_c, d_w, d_h);

    if (io_png_write_f32(argv[2], greyscale, (size_t) d_w, (size_t) d_h, (size_t) d_c) != 0) {
        printf("... failed to save png image %s", argv[4]);
    }
}