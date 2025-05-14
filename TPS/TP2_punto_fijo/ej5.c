#include <stdio.h>
#include <stdint.h>

// Constante para Q21.10
#define FRAC_BITS 10
#define FIXED_FACTOR (1 << FRAC_BITS)

// Convierte de float a Q21.10
int32_t float_to_fixed(float num) {
    return (int32_t)(num * FIXED_FACTOR);
}

// Convierte de Q21.10 a float
float fixed_to_float(int32_t fixed) {
    return (float)fixed / FIXED_FACTOR;
}

// Función de redondeo por truncación
int32_t truncation(int64_t X) {
    return (int32_t)(X >> FRAC_BITS);
}

int main() {
    // Vectores en punto flotante
    float X_float[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    float Y_float[5] = {6.6, 7.7, 8.8, 9.9, 10.10};
    
    // Convertir a Q21.10
    int32_t X_fixed[5], Y_fixed[5];
    for (int i = 0; i < 5; i++) {
        X_fixed[i] = float_to_fixed(X_float[i]);
        Y_fixed[i] = float_to_fixed(Y_fixed[i]);
    }
    
    // Imprimir valores convertidos a Q21.10
    printf("Vectores en formato Q21.10:\n");
    printf("X_fixed: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", X_fixed[i]);
    }
    printf("\nY_fixed: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", Y_fixed[i]);
    }
    printf("\n\n");
    
    // Enfoque 1: Multiplicar y redondear antes de acumular
    int32_t acum_32a = 0;
    for (int i = 0; i < 5; i++) {
        int32_t product_truncated = truncation((int64_t)X_fixed[i] * Y_fixed[i]);
        acum_32a += product_truncated;
        printf("Producto %d (truncado): %d, Acumulado: %d\n", i, product_truncated, acum_32a);
    }
    
    // Enfoque 2: Multiplicar en 64 bits y redondear después de acumular
    int64_t acum_64 = 0;
    for (int i = 0; i < 5; i++) {
        int64_t product = (int64_t)X_fixed[i] * Y_fixed[i];
        acum_64 += product;
        printf("Producto %d (64bits): %lld, Acumulado: %lld\n", i, product, acum_64);
    }
    int32_t acum_32b = truncation(acum_64);
    
    // Operación MAC en double
    double X_double[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double Y_double[5] = {6.6, 7.7, 8.8, 9.9, 10.10};
    double acum_db = 0;
    for (int i = 0; i < 5; i++) {
        acum_db += X_double[i] * Y_double[i];
    }
    
    // Convertir resultados a punto flotante para comparación
    float result_32a = fixed_to_float(acum_32a);
    float result_32b = fixed_to_float(acum_32b);
    
    // Resultados finales
    printf("\nResultados de la operación MAC:\n");
    printf("1. acum_32a (truncar antes de acumular):\n");
    printf("   - Valor en Q21.10: %d\n", acum_32a);
    printf("   - Valor convertido a float: %f\n", result_32a);
    
    printf("\n2. acum_32b (truncar después de acumular):\n");
    printf("   - Valor en Q21.10: %d\n", acum_32b);
    printf("   - Valor convertido a float: %f\n", result_32b);
    
    printf("\n3. acum_db (operación en double): %lf\n", acum_db);
    
    // Comparación de errores
    printf("\nComparación de errores:\n");
    printf("Error de acum_32a: %f\n", acum_db - result_32a);
    printf("Error de acum_32b: %f\n", acum_db - result_32b);
    
    return 0;
}