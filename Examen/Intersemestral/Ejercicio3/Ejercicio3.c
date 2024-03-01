#include <stdio.h>

int Rellenar(int vector[]);
void Rotar(int vector[], char direccion, int dimension);
void Mostrar(int vector[], int dimension);

int main(){
    int vector[50];
    int dimension;
    char direccion;
    int posiciones;

    // Rellenar el vector y obtener su dimension
    dimension = Rellenar(vector);

    printf("¿Desea rotar hacia la derecha (D) o hacia la izquierda (I): ?\n");
    fflush(stdin);
    scanf("%c", &direccion);

    if(direccion != 'I' && direccion != 'D'){
        printf("Direccion no valida. Saliendo del programa.....");
        return 1;
    }

    printf("¿Cuantas posiciones desea rotar: ?\n");
    fflush(stdin);
    scanf("%d", &posiciones);

    if(posiciones < 0 || posiciones >= dimension){
        printf("Posicion no valida. Saliendo del programa.....");
        return 1;
    }

    for (int i = 0; i < posiciones; i++)
    {
        Rotar(vector, direccion, dimension);
        printf("Vector rotado %d posición. \n", i+1);
        printf("==================================\n");
        Mostrar(vector, dimension);
    }
    
    return 0;
}


int Rellenar(int vector[]){
    int i = 0;
    int max = 0;

    printf("¿cuantos numeros vas a introducir?: \n");
    scanf("%d", &max);

    if(max <= 0){ // Validacion para evitar negativos y ceros
        max = 1;
    }else if (max > 50){
        max = 50;
    }

    for (i = 0; i < max; i++)
    {
        printf("\nIntroduce el numero (llevas %d): \n", i);
        scanf("%d", &vector[i]);
    }

    return i;
}

void Rotar(int vector[], char direccion, int dimension){
    int aux;
    if(direccion == 'D'){
        aux = vector[dimension-1];
        for (int i = dimension -1; i > 0; i--)
        {
            vector[i] = vector[i-1];
        }
        vector[0] = aux;
    }else if(direccion == 'I'){
        aux = vector[0];
        for (int i = 0; i < dimension -1; i++)
        {
            vector[i] = vector[i+1];
        }
        vector[dimension-1] = aux;
    }
}

void Mostrar(int vector[], int dimension){
    for (int i = 0; i < dimension; i++)
    {
        printf("%d", vector[i]);
    }
    printf("\n");
}