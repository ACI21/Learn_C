#include <stdio.h>

// Prototipo de Serie()
float Serie(float x, int nt);

// Función para calcular el factorial de un número
float Factorial(int n) {
    float resultado = 1;
    int i;
    // Multiplicar todos los números de 1 a n
    for (i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

// Función para calcular el seno de un ángulo utilizando la serie de Taylor
float Seno(float x, int nt) {
    int i;
    float sum = 0;
    // Iterar sobre cada término de la serie
    for (i = 0; i < nt; i++) {
        // Calcular el término utilizando la función Serie() del Programa 3
        sum += (i % 2 == 0 ? 1 : -1) * Serie(x, 2 * i + 1) / Factorial(2 * i + 1);
    }
    return sum;
}

// Función para calcular el coseno de un ángulo utilizando la serie de Taylor
float Coseno(float x, int nt) {
    int i;
    float sum = 0;
    // Iterar sobre cada término de la serie
    for (i = 0; i < nt; i++) {
        // Calcular el término utilizando la función Serie() del Programa 3
        sum += (i % 2 == 0 ? 1 : -1) * Serie(x, 2 * i) / Factorial(2 * i);
    }
    return sum;
}

// Función para calcular la tangente de un ángulo
float Tangente(float x, int nt) {
    // Utilizando las funciones Seno() y Coseno() definidas arriba
    return Seno(x, nt) / Coseno(x, nt);
}

// Función para calcular la serie de Taylor para la función trigonométrica
float Serie(float x, int nt) {
    int i;
    float sum = 1; // Primer término de la serie
    float term = 1; // Almacenar cada término de la serie
    // Iterar sobre cada término de la serie
    for (i = 1; i < nt; i++) {
        // Calcular el término actual
        term *= -1 * x * x / (2 * i * (2 * i + 1));
        // Sumar el término al resultado
        sum += term;
    }
    return sum;
}

int main() {
    float angulo_grados;
    int precision;

    // Entrada de datos: ángulo en grados y precisión
    printf("Introduce el ángulo en grados: ");
    scanf("%f", &angulo_grados);
    printf("Introduce la precisión de los cálculos (número de términos de los desarrollos): ");
    scanf("%d", &precision);

    // Convertir ángulo a radianes
    float angulo_radianes = angulo_grados * 3.14159 / 180;

    int opcion;
    do {
        // Menú para seleccionar la función trigonométrica
        printf("\nMENU\n");
        printf("1-Calcular el seno\n");
        printf("2-Calcular el coseno\n");
        printf("3-Calcular la tangente\n");
        printf("4-Salir\n");
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);

        float resultado;
        switch (opcion) {
            case 1:
                // Calcular y mostrar el seno del ángulo
                resultado = Seno(angulo_radianes, precision);
                printf("El seno de %.2f grados es: %.6f\n", angulo_grados, resultado);
                break;
            case 2:
                // Calcular y mostrar el coseno del ángulo
                resultado = Coseno(angulo_radianes, precision);
                printf("El coseno de %.2f grados es: %.6f\n", angulo_grados, resultado);
                break;
            case 3:
                // Calcular y mostrar la tangente del ángulo
                resultado = Tangente(angulo_radianes, precision);
                printf("La tangente de %.2f grados es: %.6f\n", angulo_grados, resultado);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida\n");
        }
    } while (opcion != 4);

    return 0;
}
