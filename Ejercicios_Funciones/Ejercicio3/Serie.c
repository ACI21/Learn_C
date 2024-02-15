#include <stdio.h>

// Prototipo de Serie()
float Serie(float x, int nt);
float MiPotencia(float base, int e);

// Función para calcular la serie
float Serie(float x, int nt) {
    int i;
    float sum = 0;
    // Iterar sobre cada término de la serie
    for (i = 1; i <= nt; i++) {
        // Calcular el término utilizando la función MiPotencia() del Programa 2
        sum += MiPotencia(x, i) * MiPotencia(-1, i+1);
    }
    return sum;
}

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
