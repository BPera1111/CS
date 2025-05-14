#include <stdio.h>

// Convierte de punto fijo a punto flotante
float fx2fp(int fixed, int frac_bits) {
    return fixed / (float)(1 << frac_bits);
}

// Convierte de punto flotante a punto fijo
int fp2fx(float floating, int frac_bits) {
    return (int)(floating * (1 << frac_bits));
}

int main() {
    float original = 2.4515; // Valor original en punto flotante
    float b_q23_8, b_q21_10;

    // Q23.8
    int frac_bits_q23_8 = 8;
    b_q23_8 = fx2fp(fp2fx(original, frac_bits_q23_8), frac_bits_q23_8);

    // Q21.10
    int frac_bits_q21_10 = 10;
    b_q21_10 = fx2fp(fp2fx(original, frac_bits_q21_10), frac_bits_q21_10);

    // Comparación
    printf("Original: %f\n", original);
    printf("Q23.8: %f\n", b_q23_8);
    printf("Q21.10: %f\n", b_q21_10);

    return 0;
}

