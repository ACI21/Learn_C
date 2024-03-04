#include <stdio.h>
#include <math.h>

// Función principal
int main() {
    int num_legionarios, escudos = 0;
    int esquinas;
    int borde_menos_esquinas;
    int interior;

    // Solicitar al usuario el número de legionarios
    printf("Ingrese el número de legionarios:");
    scanf("%d", &num_legionarios);
    
    // Validar que el número de legionarios esté dentro del rango permitido
    if (num_legionarios < 0 || num_legionarios > 1000) {
        printf("Error: El número de legionarios debe estar entre 0 y 1000.\n");
        return 1; // Salir del programa con código de error
    }
    
    int count = 0;
    // Calcular el número de formaciones cuadradas y los escudos necesarios
    while (num_legionarios > 0) {
        printf("-----Inicio vuelta %d--------\n", ++count);
        // Se crea la variable aux
        double aux = num_legionarios;
        // Calculamos la raíz cuadrada de "aux" para obtener el numero máximo de formacion posible
        aux = sqrt(aux);
        // Redondeamos a la baja
        int aux_copy = floor(aux); 
        // Calculamos cuantos soldados se usan
        int num_legionarios_usados = aux_copy*aux_copy;
        // Se restan del global
        num_legionarios -= num_legionarios_usados;

        // Ahora que sabemos la matriz, contamos escudos
        if(num_legionarios_usados > 4){//Si la matriz es mayor a 2x2...
            printf("Matriz de legionarios usados > 2x2\n");
            esquinas = 4; // esquinas 4
            borde_menos_esquinas = (aux_copy-2)*4; // En cada fila se le quitan esquinas y tenemos los de en medio
            interior = num_legionarios_usados - esquinas -borde_menos_esquinas; // Si quitan los bordes
            
            escudos += 3 * esquinas; // 3 escudos * 4 esquinas de la formacion
            escudos += 2 * borde_menos_esquinas; // 2 escudos * (personas en linea - esquinas) 
            escudos += 1 * interior;
        }else{
            printf("Matriz de legionarios usados <= 2x2\n");
            esquinas = num_legionarios_usados;
            borde_menos_esquinas = 0; // En cada fila se le quitan esquinas y tenemos los de en medio
            interior = 0; // Si quitan los bordes
            escudos += esquinas * 3;
        }
        printf("Reporte:\n - aux: %f\n - aux_copy: %d\n - num_legionarios_usados: %d\n - num_legionarios: %d\n - esquinas: %d\n - borde_menos_esquinas: %d\n - interior: %d\n - escudos: %d\n",aux, aux_copy,num_legionarios_usados,num_legionarios,esquinas,borde_menos_esquinas, interior, escudos);
        printf("-----Fin vuelta %d------", count);
        printf("\n");
    }
    
    
    // Mostrar el total de escudos del ejército
    printf("El total de escudos del ejército es: %d\n", escudos);
    
    return 0;
}
