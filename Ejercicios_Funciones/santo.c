#include <stdio.h>
#include <string.h>

int buscar_santo(char nombre[]) {
    char santos[][20] = {"Alexander", "Alejandro"}; 

    for (int i = 0; i < sizeof(santos) / sizeof(santos[0]); ++i) {
        if (strcmp(nombre, santos[i]) == 0) {
            return 1; 
        }
    }

    return 0; 
}

int main() {
    char nombre[20];

    printf("Ingrese su nombre: ");
    scanf("%s", nombre);

    if (buscar_santo(nombre)) {
        printf("¡Feliz día de tu santo, %s!\n", nombre);
    } else {
        printf("Hoy no es tu santo, %s.\n", nombre);
    }

    return 0;
}
