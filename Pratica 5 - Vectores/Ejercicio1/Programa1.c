/*
 * Programa 1: Manejo de vectores
 * Escribir un programa en C que permita realizar cálculos estadísticos sobre una clase de n alumnos 
 * (nunca pueden ser más de 50 alumnos, declarar el tamaño máximo como una constante simbólica usando 
 * la directiva #define N 50).
 * Para ello, se va a utilizar un vector (float notas[N]) de números reales. 
 * En primer lugar, se le pedirá al usuario que le indique cuántos alumnos hay en la clase 
 * (por supuesto, se ha de validar este número). Posteriormente, una vez conocido el número de alumnos 
 * de la clase, se le pedirá al usuario que vaya introduciendo las notas de cada alumno, 
 * que se deberían almacenar en el vector notas creado para tal fin.
 * Una vez tomados los datos de los n alumnos, se deberá presentar un menú al usuario que permita calcular: 
 * a) La media de las notas.
 * b) La máxima nota. Además de indicar qué alumno la consigue (su índice dentro del vector). 
 * Y si fueran varios alumnos que consiguen la máxima nota decir quiénes son (sus índices dentro del vector).
 * c) La mínima nota. Además de indicar qué alumno la consigue (su índice dentro del vector). 
 * Y si fueran varios alumnos que consiguen la mínima nota decir quiénes son (sus índices dentro del vector).
 * Nota: Todas las operaciones mencionadas se realizarán dentro de la función main().
*/

#include<stdio.h>
#include<ctype.h>
#define N 50 //Tamaño maximo del vector

//Prototipos de las funciones
void mostrar_menu();
float calcular_media(float nota[], int num_alum);
void calcular_maxima_nota(float nota[], int num_alum);
void calcular_minima_nota(float nota[], int num_alum);

int main(){
    //Declaracion variables
    int num_alumnos;
    float notas[N];
    int i;
    char opciones;

    //Pedir al usuario que ingrese la cantidad de alumnos
    printf("Ingrese la cantidad de alumnos en la clase: \n");
    scanf("%d", &num_alumnos);
    getchar();

    //Validar que  no sea mayor a N ni menor a 1
    if (num_alumnos <= 0 || num_alumnos > N)
    {
        printf("Error! La cantidad debe estar entre 1 y %d\n", N);
        return 1; //Salimos de la aplicacion
    }

    // Lectura de notas
    printf("Ingrese las notas de los %d alumos:\n", num_alumnos);
    for (i = 0; i < num_alumnos; i++)
    {
        printf("Nota del alumno %d: ", i+1);
        scanf("%f", &notas[i]);
        getchar();
    }

    do
    {
        // Aqui, ya tenemos notas, alumnos y validado todo
    mostrar_menu();

    // Leer la opcion del menu
    printf("Escoge una opcion: ");
    scanf("%c", &opciones);
    opciones = tolower(opciones);
    getchar();

    switch (opciones)
    {
        case 'a':
            printf("La media de las notas es: %.2f\n", calcular_media(notas, num_alumnos));
            break;
        case 'b':
            calcular_maxima_nota(notas, num_alumnos);
            break;
        case 'c':
            calcular_minima_nota(notas, num_alumnos);
            break;
        case 'd':
            printf("Saliendo...");
            break;
        default:
            printf("Opcion invalida. Vuelve a intentarlo.\n");
            break;
    }
    } while (opciones != 'd');
    
    return 0;
}

void mostrar_menu(){
    printf("\nOpciones:\n");
    printf("A) Calcular Media\n");
    printf("B) Calcular Maxima Nota\n");
    printf("C) Calcular Minima Nota\n");
    printf("D) Salir\n");
}

float calcular_media(float nota[], int num_alum){
    float suma = 0.0;
    int i;

    for (i = 0; i < num_alum; i++)
    {
        suma += nota[i];
    }
    
    return suma / num_alum;
}

void calcular_maxima_nota(float nota[], int num_alum){
    float maxima = 0;
    int alumnos_mayor_nota[N]; // Vector para alamcenar los indices de la variable nota
    int cantidad = 0; // en el caso de que +1 tenga una nota igual
    int i;

    // Encontrar la nota maxima
    for (i = 0; i < num_alum; i++)
    {
        if(nota[i] > maxima){
            maxima = nota[i];
        }
    }

    // Encontrar al afortunado
    for (i = 0; i < num_alum; i++)
    {
        if(nota[i] == maxima){
            alumnos_mayor_nota[cantidad] = i;
            cantidad++;
        }
    }
    
    // imprimir los datos
    printf("La nota máxima es: %.2f\n", maxima);
    printf("Alumnos con la maxima nota son: \n");
    for (i = 0; i < cantidad; i++)
    {
        printf("%d ", alumnos_mayor_nota[i]+1);
    }

    printf("\n");
}

void calcular_minima_nota(float nota[], int num_alum){
    float minima = nota[0];
    int alumnos_minima_nota[N]; // Vector para alamcenar los indices de la variable nota
    int cantidad = 0; // en el caso de que +1 tenga una nota igual
    int i;

    // Encontrar la nota minima
    for (i = 0; i < num_alum; i++)
    {
        if(nota[i] < minima){
            minima = nota[i];
        }
    }

    // Encontrar al afortunado
    for (i = 0; i < num_alum; i++)
    {
        if(nota[i] == minima){
            alumnos_minima_nota[cantidad] = i;
            cantidad++;
        }
    }
    
    // imprimir los datos
    printf("La nota máxima es: %.2f\n", minima);
    printf("Alumnos con la minima nota son: \n");
    for (i = 0; i < cantidad; i++)
    {
        printf("%d ", alumnos_minima_nota[i]+1);
    }

    printf("\n");
}