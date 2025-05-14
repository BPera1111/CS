#include <stdio.h>
#include <stdint.h>

// Convierte número flotante a formato Q21.10
int32_t double_to_q21_10(double num) {
    return (int32_t)(num * (1 << 10));
}

// Convierte de Q21.10 a flotante
double q21_10_to_double(int32_t fixed) {
    return (double)fixed / (1 << 10);
}

// Función de redondeo por truncación
int32_t truncation(int64_t X) {
    // Simplemente desplaza 10 bits a la derecha para obtener el resultado en Q21.10
    int32_t result = (int32_t)(X >> 10);
    return result;
}

// Función de redondeo al valor más cercano
int32_t rounding(int64_t X) {
    // Verificamos el bit justo antes de truncar para decidir si redondeamos
    int64_t mask = (int64_t)1 << 9; // Bit de posición 9 (justo antes del bit 10)
    int64_t truncated = X >> 10;
    
    // Si el bit es 1, redondeamos hacia arriba
    if ((X & mask) != 0) {
        truncated += 1;
    }
    
    return (int32_t)truncated;
}

// Multiplica dos números en formato Q21.10
int64_t multiply_q21_10(int32_t a, int32_t b) {
    // Multiplicar dos números Q21.10 da como resultado Q42.20
    return (int64_t)a * (int64_t)b;
}

int main() {
    double num1 = 562.7589078899;
    double num2 = 387.2567898650;
    double expected_result = num1 * num2;
    
    // Convertir a Q21.10
    int32_t a = double_to_q21_10(num1);
    int32_t b = double_to_q21_10(num2);
    
    // Multiplicar en Q21.10 (resultado en Q42.20)
    int64_t product = multiply_q21_10(a, b);
    
    // Aplicar esquemas de redondeo
    int32_t truncated = truncation(product);
    int32_t rounded = rounding(product);
    
    // Convertir resultados a double para comparación
    double truncated_result = q21_10_to_double(truncated);
    double rounded_result = q21_10_to_double(rounded);
    
    // Mostrar resultados
    printf("Valores originales:\n");
    printf("  Número 1 (double): %f\n", num1);
    printf("  Número 2 (double): %f\n", num2);
    
    printf("\nValores en Q21.10:\n");
    printf("  Número 1 (Q21.10): %d\n", a);
    printf("  Número 2 (Q21.10): %d\n", b);
    
    printf("\nResultados:\n");
    printf("  Resultado esperado (double): %f\n", expected_result);
    printf("  Resultado con truncación: %f\n", truncated_result);
    printf("  Resultado con redondeo: %f\n", rounded_result);
    
    printf("\nError de redondeo:\n");
    printf("  Error con truncación: %f\n", expected_result - truncated_result);
    printf("  Error con redondeo: %f\n", expected_result - rounded_result);
    
    return 0;
}