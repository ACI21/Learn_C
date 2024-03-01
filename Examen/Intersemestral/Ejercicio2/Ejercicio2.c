#include <stdio.h>

float CalPuntos (int minutos, int segundos);

int main(){
    int minutos, segundos;
    float puntuacion, primero = 0, segundo = 0, tercero = 0;

    printf("Introduce los minutos y segundos del corredor (o -1 para terminar): ");

    while (1)
    {
        printf("Minutos: ");
        scanf("%d", &minutos);
        if (minutos == -1)
        {
            break;
        }

        printf("Segundos: ");
        scanf("%d", &segundos);

        puntuacion = CalPuntos(minutos, segundos);
        
        if(puntuacion > primero){
            tercero = segundo;
            segundo = primero;
            primero = puntuacion;
        } else if(puntuacion > segundo){
            tercero = segundo;
            segundo = puntuacion;
        } else if(puntuacion > tercero){
            tercero = puntuacion;
        }
    }
    
    printf("Puntuacion primero: %.2f puntos\n", primero);
    printf("Puntuacion segundo: %.2f puntos\n", segundo);
    printf("Puntuacion tercero: %.2f puntos\n", tercero);

    return 0;
}

float CalPuntos (int minutos, int segundos){
    return 1000.0 / (minutos*100 + segundos);
}
