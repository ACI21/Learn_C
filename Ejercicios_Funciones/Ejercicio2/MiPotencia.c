#include <stdio.h>

// Función para calcular la potencia de un número real elevado a un número entero positivo
float MiPotencia(float base, int e) {
    float result = 1; // Inicializar el resultado como 1
    int i;
    // Multiplicar la base 'e' veces
    for (i = 0; i < e; i++) {
        result *= base;
    }
    return result;
}

int main() {
    float base;
    int exponente;

    // Entrada de datos: base y exponente
    printf("Introduce la base: ");
    scanf("%f", &base);
    printf("Introduce el exponente (positivo): ");
    scanf("%d", &exponente);

    // Validar el exponente
    while (exponente < 0) {
        printf("El exponente debe ser positivo. Introduce otro valor: ");
        scanf("%d", &exponente);
    }

    // Llamada a la función MiPotencia() y mostrar resultado
    float resultado = MiPotencia(base, exponente);
    printf("%.2f elevado a %d es %.2f\n", base, exponente, resultado);

    return 0;
}
