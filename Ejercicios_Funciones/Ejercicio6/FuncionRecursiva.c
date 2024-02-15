#include <stdio.h>

// Función recursiva para sumar las cifras de un número
int Suma_cifras_recursiva(int n) {
    // Caso base: número de una sola cifra
    if (n < 10) {
        return n;
    } 
    // Caso general: sumar la última cifra con la suma de las demás cifras
    else {
        return n % 10 + Suma_cifras_recursiva(n / 10);
    }
}

int main() {
    int numero;

    // Entrada de datos: número entero y positivo
    printf("Introduce un número entero y positivo: ");
    scanf("%d", &numero);

    // Validación de número positivo
    while (numero <= 0) {
        printf("Por favor, introduce un número entero y positivo: ");
        scanf("%d", &numero);
    }

    // Llamada a la funcion para sumar las cifras y mostrar el resultado
    printf("Suma de las cifras (recursiva): %d\n", Suma_cifras_recursiva(numero));

    return 0;
}
