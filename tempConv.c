#include <stdio.h>

float toCelsius(int F)
{
    return (5.0 * (F - 32.0) / 9.0);
}

void main(void)
{

    float Ftemp = 0;
    float *p = &Ftemp;

    while (Ftemp < 300)
    {
        printf("F: %3.1f \t\t C: %.1f\n", Ftemp, toCelsius(Ftemp));
        *p += 20;
    }
}
