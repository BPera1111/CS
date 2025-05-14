#include <math.h>
#include <stdio.h>
int main(void)
{
    int a, b, c, d; // Cambiar signed char a int
    int s1, s2;     // Cambiar signed char a int para consistencia
    a = 127;
    b = 127;
    c = a + b;      // No habrá desbordamiento
    d = a * b;      // No habrá desbordamiento
    s1 = (-8) >> 2;
    s2 = (-1) >> 5;
    printf("c = %d \n", c );
    printf("d = %d \n", d );
    printf("s1 = %d \n", s1 );
    printf("s2 = %d \n", s2 );
    return 0;
}
