// Version: 002
// Date:    2022/04/05
// Author:  Rodrigo Gonzalez <rodralez@frm.utn.edu.ar>

#include <stdio.h>
#include <float.h>
#include <math.h>
#include <fenv.h>

// Compile usando el siguiente comando
// compile: gcc -Wall -O3 -std=c99 ex_04.c -o ex_04 -lm -march=corei7 -frounding-math -fsignaling-nans

#define _GNU_SOURCE 1
#define _ISOC99_SOURCE

void show_fe_exceptions(void)
{
    printf("current exceptions raised: ");
    if (fetestexcept(FE_DIVBYZERO))     printf(" FE_DIVBYZERO");
    if (fetestexcept(FE_INEXACT))       printf(" FE_INEXACT");
    if (fetestexcept(FE_INVALID))       printf(" FE_INVALID");
    if (fetestexcept(FE_OVERFLOW))      printf(" FE_OVERFLOW");
    if (fetestexcept(FE_UNDERFLOW))     printf(" FE_UNDERFLOW");
    if (fetestexcept(FE_ALL_EXCEPT) == 0) printf(" none");
    printf("\n");
}

int main(void)
{
    feclearexcept(FE_ALL_EXCEPT); // Limpiar todas las excepciones

    // Generar FE_DIVBYZERO (División por cero)
    printf("Generando FE_DIVBYZERO...\n");
    volatile float div_by_zero = 1.0 / 0.0; // División por cero
    printf("Resultado: %f\n", div_by_zero); // Usar la variable
    show_fe_exceptions();

    // Generar FE_INVALID (Operación inválida)
    feclearexcept(FE_ALL_EXCEPT);
    printf("Generando FE_INVALID...\n");
    volatile float invalid_op = sqrt(-1.0); // Raíz cuadrada de un número negativo
    printf("Resultado: %f\n", invalid_op); // Usar la variable
    show_fe_exceptions();

    // Generar FE_OVERFLOW (Desbordamiento)
    feclearexcept(FE_ALL_EXCEPT);
    printf("Generando FE_OVERFLOW...\n");
    volatile float overflow = FLT_MAX * 2.0; // Multiplicación que excede el rango de float
    printf("Resultado: %f\n", overflow); // Usar la variable
    show_fe_exceptions();

    // Generar FE_UNDERFLOW (Subdesbordamiento)
    feclearexcept(FE_ALL_EXCEPT);
    printf("Generando FE_UNDERFLOW...\n");
    volatile float underflow = FLT_MIN / 2.0; // División que produce un número muy pequeño
    printf("Resultado: %e\n", underflow); // Usar la variable
    show_fe_exceptions();

    // Generar FE_INEXACT (Resultado inexacto)
    feclearexcept(FE_ALL_EXCEPT);
    printf("Generando FE_INEXACT...\n");
    volatile float inexact = 1.0 / 3.0; // Operación que no puede representarse exactamente
    printf("Resultado: %f\n", inexact); // Usar la variable
    show_fe_exceptions();

    return 0;
}
