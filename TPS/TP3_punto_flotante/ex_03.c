#include <stdio.h>
#include <math.h>

int main(void) {
    // Inicialización de valores especiales
    float nan_value = NAN;          // NaN usando la macro NAN
    float pos_inf = INFINITY;       // +Inf usando la macro INFINITY
    float neg_inf = -INFINITY;      // -Inf usando la macro INFINITY

    // Generación de valores especiales mediante operaciones matemáticas
    float nan_op = 0.0 / 0.0;       // NaN
    float pos_inf_op = 1.0 / 0.0;   // +Inf
    float neg_inf_op = -1.0 / 0.0;  // -Inf

    // Imprimir los valores especiales
    printf("Valores especiales inicializados:\n");
    printf("NaN (macro): %f\n", nan_value);
    printf("+Inf (macro): %f\n", pos_inf);
    printf("-Inf (macro): %f\n", neg_inf);

    printf("\nValores especiales generados por operaciones:\n");
    printf("NaN (operación): %f\n", nan_op);
    printf("+Inf (operación): %f\n", pos_inf_op);
    printf("-Inf (operación): %f\n", neg_inf_op);

    // Comprobación de valores especiales
    printf("\nComprobaciones:\n");
    printf("isnan(nan_value): %d\n", isnan(nan_value));
    printf("isinf(pos_inf): %d\n", isinf(pos_inf));
    printf("isinf(neg_inf): %d\n", isinf(neg_inf));

    return 0;
}