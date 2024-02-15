#include <stdio.h>

// Función iterativa para sumar las cifras de un número
int Suma_cifras_iterativa(int n) {
    int suma = 0;
    // Mientras haya cifras en el número
    while (n > 0) {
        // Obtener la última cifra y sumarla a la suma total
        suma += n % 10;
        // Eliminar la última cifra del número
        n /= 10;
    }
    return suma;
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
    printf("Suma de las cifras (iterativa): %d\n", Suma_cifras_iterativa(numero));

    return 0;
}
