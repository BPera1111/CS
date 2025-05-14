#include <stdio.h>
#include <limits.h>
#include <stdint.h>

// Función de suma con aritmética de saturación
int32_t saturation(int32_t a, int32_t b) {
    // Verificar desbordamiento antes de realizar la suma
    if (b > 0 && a > INT_MAX - b) {
        // Desbordamiento positivo
        return INT_MAX;
    } else if (b < 0 && a < INT_MIN - b) {
        // Desbordamiento negativo
        return INT_MIN;
    } else {
        // Sin desbordamiento, realizar la suma normal
        return a + b;
    }
}

int main() {
    // Casos de prueba para verificar la función
    printf("Límites del tipo int32_t:\n");
    printf("INT_MAX = %d\n", INT_MAX);
    printf("INT_MIN = %d\n\n", INT_MIN);
    
    // Caso 1: Suma normal sin desbordamiento
    int32_t a1 = 100, b1 = 200;
    printf("Caso 1: %d + %d = %d (sin saturación)\n", 
           a1, b1, saturation(a1, b1));
    
    // Caso 2: Desbordamiento positivo
    int32_t a2 = INT_MAX, b2 = 10;
    printf("Caso 2: %d + %d = %d (saturación a INT_MAX)\n", 
           a2, b2, saturation(a2, b2));
    
    // Caso 3: Otro desbordamiento positivo
    int32_t a3 = INT_MAX - 5, b3 = 10;
    printf("Caso 3: %d + %d = %d (saturación a INT_MAX)\n", 
           a3, b3, saturation(a3, b3));
    
    // Caso 4: Desbordamiento negativo
    int32_t a4 = INT_MIN, b4 = -5;
    printf("Caso 4: %d + (%d) = %d (saturación a INT_MIN)\n", 
           a4, b4, saturation(a4, b4));
    
    // Caso 5: Otro desbordamiento negativo
    int32_t a5 = INT_MIN + 3, b5 = -10;
    printf("Caso 5: %d + (%d) = %d (saturación a INT_MIN)\n", 
           a5, b5, saturation(a5, b5));
    
    // Caso 6: Números de signos opuestos (sin saturación)
    int32_t a6 = -2000000000, b6 = 1000000000;
    printf("Caso 6: %d + %d = %d (sin saturación)\n", 
           a6, b6, saturation(a6, b6));
    
    return 0;
}