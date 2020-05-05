
#include "rgb2lab.h"

float F(float input) // function f(...), which is used for defining L, a and b
{
    if (input > 0.008856)
        return cbrt(input); // maximum 1 --- prefer cbrt to pow for cubic root
    else
        return ((float(841) / 108) * input +
                float(4) / 29); // 841/108 = 29*29/36*16
}

// RGB to XYZ
void RGBtoXYZ( float R, float G, float B, float &X, float &Y, float &Z)
{
    float_t var_R = float_t(R / 255);
    float_t var_G = float_t(G / 255);
    float_t var_B = float_t(B / 255);

    var_R = (var_R > 0.04045) ? std::pow((var_R + 0.055) / 1.055, 2.4)
                              : var_R / 12.92;
    var_G = (var_G > 0.04045) ? std::pow((var_G + 0.055) / 1.055, 2.4)
                              : var_G / 12.92;
    var_B = (var_B > 0.04045) ? std::pow((var_B + 0.055) / 1.055, 2.4)
                              : var_B / 12.92;

    var_R *= 100;
    var_G *= 100;
    var_B *= 100;

    X = var_R * float_t(0.4124) + var_G * float_t(0.3576) + var_B * float_t(0.1805);
    Y = var_R * float_t(0.2126) + var_G * float_t(0.7152) + var_B * float_t(0.0722);
    Z = var_R * float_t(0.0193) + var_G * float_t(0.1192) + var_B * float_t(0.9505);
}

// XYZ to CIELab
void XYZtoLab(float X, float Y, float Z, float &L, float &a, float &b)
{
    float Xo = 95.047;
    float Yo = 100;
    float Zo = 108.883;
    L = 116 * F(Y / Yo) - 16; // maximum L = 100
    a = 500 * (F(X / Xo) - F(Y / Yo)); // maximum
    b = 200 * (F(Y / Yo) - F(Z / Zo));
}

// RGB to CIELab
void RGBtoLab(float R, float G, float B, float &L, float &a, float &b)
{
    float X, Y, Z;
    RGBtoXYZ(R, G, B, X, Y, Z);
    XYZtoLab(X, Y, Z, L, a, b);
}