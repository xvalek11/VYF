#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RGBtoLab(float R, float G, float B, float &L, float &a, float &b);
void XYZtoLab(float X, float Y, float Z, float &L, float &a, float &b);
void RGBtoXYZ(float R, float G, float B, float &X, float &Y, float &Z);
float F(float input);

