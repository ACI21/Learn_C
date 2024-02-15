#include <stdio.h>

// Función para dibujar un triángulo de altura dada
void DibujarTriangulo(int altura) {
    int i, j;
    // Iterar sobre cada fila del triángulo
    for (i = altura; i >= 1; i--) {
        // Imprimir '*' en cada columna de la fila actual
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n"); // Nueva línea para la siguiente fila
    }
}

int main() {
    int altura;

    // Entrada de datos: altura del triángulo
    do {
        printf("Introduce la altura del triángulo (positiva): ");
        scanf("%d", &altura);
    } while (altura <= 0);

    // Llamada a la función para dibujar el triángulo
    DibujarTriangulo(altura);

    return 0;
}
