#include <stdio.h>
#include <math.h>

double Polinomio_Chebyshev(int grado, double x);

int main(){
    int grado;
    double x;

    printf("Ingrese el grado del polinomio: ");
    scanf("%d", &grado);

    printf("Polinomio de Chebyshev de grado %d\n", grado);
    for (x = -1.0; x <= 1.0; x += 0.1)
    {
        printf("T%d(%.1f) = %.4f\n",grado, x, Polinomio_Chebyshev(grado, x));
    }
    

    return 0;
}

double Polinomio_Chebyshev(int grado, double x){
    if(grado == 0){
        return 1.0;
    } else if(grado == 1){
        return x;
    }else{
        int i;
        double tn = 0.0;
        double tn1 = x;
        double tn2 = 1.0;

        for (i = 2; i <= grado; i++)
        {
            tn = 2 * x * tn1 -tn2;
            tn2 = tn1;
            tn1 = tn;
        }

        return tn;
    }
}
