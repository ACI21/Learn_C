#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 120
#define NUM_TIPO 5

void CargarVector(int vector_codigos[]);

int main(){
    srand((unsigned)time(NULL));
    int vector_codigo[N];

    CargarVector(vector_codigo);
    
    printf("Vector cargado: \n");
    for (int i = 0; i < N; i++)
    {
        
        printf("%d\n", vector_codigo[i]);
    }

    for (int tipo = 1; tipo <= NUM_TIPO; tipo++)
    {
        while (1) // bucle infinito
        {
            int indice = rand() % N; // numero aleatorio de 0 a N(120)
            if(vector_codigo[indice] /100 == tipo){ // comprobamos que el vector[random] sea del tipo 
                int aux = vector_codigo[tipo-1];
                vector_codigo[tipo-1] = vector_codigo[indice];
                vector_codigo[indice] = aux;
                break;
            }
        }
    }
    
    for (int i = 0; i < NUM_TIPO; i++)
    {
        printf("Codigo encontrado: %d\n", vector_codigo[i]);
    }

    return 0;
}

void CargarVector(int vector_codigos[]){
    for (int i = 0; i < N; i++)
    {
        int indice = rand() % 500;
        indice += 100;
        vector_codigos[i] = indice;
    }
}