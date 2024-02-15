#include <stdio.h>

// Prototipo de Serie()
float Serie(float x, int nt);

// Función para calcular la serie
float Serie(float x, int nt) {
    int i;
    float sum = 0;
    // Iterar sobre cada término de la serie
    for (i = 0; i < nt; i++) {
        // Calcular el término utilizando la función MiPotencia() del Programa 2
        sum += MiPotencia(-1, i) * MiPotencia(x, i+1);
    }
    return sum;
}

int main() {
    float x;
    int nt;

    // Entrada de datos: valor de x y número de términos de la serie
    printf("Introduce el valor de x: ");
    scanf("%f", &x);
    printf("Introduce el número de términos a sumar de la serie (positivo): ");
    scanf("%d", &nt);

    // Validar el número de términos
    while (nt < 0) {
        printf("El número de términos debe ser positivo. Introduce otro valor: ");
        scanf("%d", &nt);
    }

    // Llamada a la función Serie() y mostrar resultado
    float resultado = Serie(x, nt);
    printf("El resultado de la serie es: %.2f\n", resultado);

    return 0;
}
