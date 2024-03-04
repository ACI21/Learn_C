#include <stdio.h>

// Prototipo de la función para desglosar la cantidad a devolver en monedas
void DesgloseDeMoneda(float devolver, int valores[], int monedas[]);

int main()
{
    // Declaración e inicialización del vector de valores de monedas en céntimos
    int valores[8] = {200, 100, 50, 20, 10, 5, 2, 1};
    // Declaración del vector para almacenar el número de monedas de cada valor
    int monedas[8] = {0}; // Inicializar todas las posiciones a 0

    float importe_servicio, cant_intro;

    // Paso 2: Leer y validar el importe del servicio
    printf("Introducir el importe del servicio: ");
    scanf("%f", &importe_servicio);
    while (importe_servicio <= 0)
    {
        printf("El importe del servicio debe ser un valor positivo. Inténtelo de nuevo: ");
        scanf("%f", &importe_servicio);
    }

    // Paso 3: Leer y validar la cantidad introducida por el cliente
    printf("Introducir la cantidad para el cobro: ");
    scanf("%f", &cant_intro);
    while (cant_intro < importe_servicio)
    {
        printf("La cantidad introducida debe ser mayor o igual que el importe a pagar (%.2f euros).\nInténtelo de nuevo: ", importe_servicio);
        scanf("%f", &cant_intro);
    }

    // Calcular el importe a devolver
    float a_devolver = cant_intro - importe_servicio;
    printf("La cantidad a devolver es de %.2f euros\n", a_devolver);

    // Paso 5: Llamar a la función para desglosar la cantidad a devolver en monedas
    DesgloseDeMoneda(a_devolver, valores, monedas);

    // Paso 6: Escribir el desglose de monedas
    printf("Desglose de monedas:\n");
    for (int i = 0; i < 8; i++)
    {
        if (monedas[i] > 0)
        {
            printf("%d moneda(s) de %.2f euros\n", monedas[i], (float)valores[i] / 100);
        }
    }

    return 0;
}

// Función para desglosar la cantidad a devolver en monedas
void DesgloseDeMoneda(float devolver, int valores[], int monedas[])
{
    // Iterar sobre cada valor de moneda
    for (int i = 0; i < 8; i++)
    {
        // Calcular el número de monedas de este valor
        monedas[i] = devolver / (valores[i] / 100);
        // Actualizar la cantidad a devolver restando el valor de las monedas asignadas
        devolver -= monedas[i] * (valores[i] / 100);
    }
}

/**
 * Declaración e inicialización de vectores: 
 *      Se declaran e inicializan los vectores valores y monedas. El primero contiene los valores de las monedas en céntimos y el segundo almacenará el número de monedas de cada valor.
 * Lectura y validación del importe del servicio: 
 *      Se lee el importe del servicio por teclado y se valida para asegurar que sea un valor positivo.
 * Lectura y validación de la cantidad introducida: 
 *      Se lee la cantidad introducida por el cliente y se valida para asegurar que sea mayor o igual que el importe del servicio.
 * Cálculo del importe a devolver: 
 *      Se calcula la cantidad a devolver restando el importe del servicio de la cantidad introducida por el cliente.
 * Llamada a la función para desglosar monedas: 
 *      Se llama a la función DesgloseDeMoneda para calcular el número de monedas de cada valor que se necesitan para devolver el cambio.
 * Escribir el desglose de monedas: 
 *      Se muestra en pantalla el desglose de monedas con el número de monedas de cada valor.
 */