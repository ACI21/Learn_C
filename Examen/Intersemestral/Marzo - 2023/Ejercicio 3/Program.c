#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10000

double EstimarPI(double vector[]);

int main(){
    srand((unsigned)time(NULL));
    long tamanyo_vector = 2*N;

    double vec_curso[tamanyo_vector];
    double vec_optimo[tamanyo_vector];

    double error_minimo = -1;
    int simulacion_optima = -1;

    // Da 10 simulaciones
    for (int i = 1; i <= 10; i++)
    {
        double error = EstimarPI(vec_curso);

        if(error_minimo == -1 || error < error_minimo){
            error_minimo = error;
            simulacion_optima = i;

            for (int j = 0; j < tamanyo_vector; j++)
            {
                printf( "\n------->");
                printf( "curso: %f ", vec_curso[j]);
                printf( "\n------->");
                printf( "optimo: %f ", vec_optimo[j]);
                 printf( "\n------->");

                vec_optimo[j] = vec_curso[j]; 
            }
        }
    }
    
    printf("Simulacion optima: %d\nError minimo: %f\n",simulacion_optima, error_minimo);
    return 0;
}

double EstimarPI(double vector[]){
    int i, count = 0;
    double x, y;

    for (i = 0; i < N; i++)
    {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        if (x*x + y*y <= 1)
        {
            count++;
        }

        vector[2*i] = x;
        vector[2*i+1] = y;
    }

    double pi = 4.0 * count / N;
    double error = fabs(pi - M_PI);

    return error;
}