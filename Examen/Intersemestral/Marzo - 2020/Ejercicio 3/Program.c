#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Constantes
#define N 10 // Tamaño de la matriz
#define MAX_PALABRAS 5 // Máximo número de palabras a ingresar

// Prototipos de funciones
int Verificar_Long_Palabra(int long_palabra, int indices[], int direccion);
int Comprobar_y_Escribir_Palabra(char matriz[][N], char palabra[], int indices[], int direccion, int long_palabra);
void ImprimirMatriz(char matriz[][N]);

int main() {
    // Inicializar la semilla aleatoria para la generación de letras aleatorias
    srand((unsigned)time(NULL));

    // Matriz inicializada con '1' en todas sus posiciones
    char matriz[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = '1';
        }
    }

    // Pedir palabras por terminal
    int num_palabras;
    printf("Ingrese el número de palabras a escribir en la sopa de letras (máximo %d): ", MAX_PALABRAS);
    scanf("%d", &num_palabras);
    if (num_palabras < 0 || num_palabras > MAX_PALABRAS) {
        printf("Número de palabras no válido.\n");
        return 1;
    }

    char palabras[MAX_PALABRAS][N]; // Arreglo para almacenar las palabras
    int indices[MAX_PALABRAS][2]; // Arreglo para almacenar los índices de fila y columna
    int direcciones[MAX_PALABRAS]; // Arreglo para almacenar las direcciones (0 = Horizontal, 1 = Vertical, 2 = Diagonal)
    int longitudes[MAX_PALABRAS]; // Arreglo para almacenar las longitudes de las palabras

    for (int i = 0; i < num_palabras; i++) {
        printf("Ingrese la palabra %d: ", i + 1);
        scanf("%s", palabras[i]);
        printf("Ingrese la fila y columna de inicio para la palabra %d:(1 2) ", i + 1);
        scanf("%d %d", &indices[i][0], &indices[i][1]);
        printf("Ingrese la dirección para la palabra %d (0 = Horizontal, 1 = Vertical, 2 = Diagonal): ", i + 1);
        scanf("%d", &direcciones[i]);
        longitudes[i] = strlen(palabras[i]);
    }

    // Ejemplo de uso de las funciones
    for (int i = 0; i < num_palabras; i++) {
        int resultado_verificacion = Verificar_Long_Palabra(longitudes[i], indices[i], direcciones[i]);
        if (resultado_verificacion == 0) {
            int resultado_escritura = Comprobar_y_Escribir_Palabra(matriz, palabras[i], indices[i], direcciones[i], longitudes[i]);
            if (resultado_escritura == 0) {
                printf("La palabra '%s' se ha escrito correctamente en la matriz.\n", palabras[i]);
            } else {
                printf("No se pudo escribir la palabra '%s' en la matriz.\n", palabras[i]);
            }
        } else {
            printf("La longitud de la palabra '%s' excede los límites de la matriz.\n", palabras[i]);
        }
    }

    // Imprimir la matriz resultante
    printf("Sopa de letras generada:\n");
    ImprimirMatriz(matriz);

    return 0;
}

// Función para verificar que la longitud de la palabra no excede los límites de la matriz
int Verificar_Long_Palabra(int long_palabra, int indices[], int direccion) {
    int fila = indices[0];
    int columna = indices[1];

    // Verificar la longitud de la palabra según la dirección
    if (direccion == 0) { // Horizontal
        if (columna + long_palabra <= N) {
            return 0; // Longitud válida
        }
    } else if (direccion == 1) { // Vertical
        if (fila + long_palabra <= N) {
            return 0; // Longitud válida
        }
    } else if (direccion == 2) { // Diagonal
        if (fila + long_palabra <= N && columna + long_palabra <= N) {
            return 0; // Longitud válida
        }
    }

    return -1; // Longitud inválida
}

// Función para comprobar y escribir la palabra en la matriz
int Comprobar_y_Escribir_Palabra(char matriz[][N], char palabra[], int indices[], int direccion, int long_palabra) {
    int fila = indices[0];
    int columna = indices[1];

    // Comprobar si la palabra puede ser escrita en la matriz
    for (int i = 0; i < long_palabra; i++) {
        if (direccion == 0) { // Horizontal
            if (matriz[fila][columna + i] != '1' && matriz[fila][columna + i] != palabra[i]) {
                return -1; // No se puede escribir la palabra
            }
        } else if (direccion == 1) { // Vertical
            if (matriz[fila + i][columna] != '1' && matriz[fila + i][columna] != palabra[i]) {
                return -1; // No se puede escribir la palabra
            }
        } else if (direccion == 2) { // Diagonal
            if (matriz[fila + i][columna + i] != '1' && matriz[fila + i][columna + i] != palabra[i]) {
                return -1; // No se puede escribir la palabra
            }
        }
    }

    // Escribir la palabra en la matriz
    for (int i = 0; i < long_palabra; i++) {
        if (direccion == 0) { // Horizontal
            matriz[fila][columna + i] = palabra[i];
        } else if (direccion == 1) { // Vertical
            matriz[fila + i][columna] = palabra[i];
        } else if (direccion == 2) { // Diagonal
            matriz[fila + i][columna + i] = palabra[i];
        }
    }

    return 0; // La palabra se escribió correctamente
}

// Función para imprimir la matriz
void ImprimirMatriz(char matriz[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}
