#include <stdio.h>

// Función para calcular la altura de una persona
double CalculaAlt(double long_tibia, char sexo) {
    // Fórmula para hombres
    if (sexo == 'H') {
        return 69.089 + 2.238 * long_tibia;
    } 
    // Fórmula para mujeres
    else if (sexo == 'M') {
        return 61.412 + 2.317 * long_tibia;
    } 
    // Si el sexo no es válido
    else {
        printf("Sexo no válido.\n");
        return -1; // Valor de retorno inválido
    }
}

int main() {
    double long_tibia;
    char sexo;
    char continuar;

    do {
        // Entrada de datos: longitud de la tibia y sexo
        printf("Introduce la longitud de la tibia (en cm): ");
        scanf("%lf", &long_tibia);
        getchar(); // Limpiar el buffer de entrada

        do {
            printf("Introduce el sexo (H/M): ");
            scanf("%c", &sexo);
            sexo = toupper(sexo); // Convertir a mayúscula
            getchar(); // Limpiar el buffer de entrada
        } while (sexo != 'H' && sexo != 'M');

        // Llamada a la función para calcular la altura
        double altura = CalculaAlt(long_tibia, sexo);
        if (altura != -1) {
            printf("La altura de la persona es: %.2lf metros\n", altura / 100); // Convertir a metros
        }

        // Preguntar al usuario si desea introducir datos de otra persona
        printf("¿Desea introducir la longitud de la tibia de otra persona? (S/N): ");
        scanf("%c", &continuar);
        getchar(); // Limpiar el buffer de entrada
    } while (continuar == 'S' || continuar == 's');

    return 0;
}
