#include <stdio.h>
#include <time.h>

// constantes
#define filas 5
#define columnas 12

int main() {
    srand(time(NULL));

    int produccion[filas][columnas];
    int min = 10000, max = 50000, suma = 0, anio, mes, mayor = 0;
    float promedio;

    for (int i=0 ; i<filas ; i++)
    {
        for (int j=0 ; j<columnas ; j++)
        {
            produccion[i][j] = min + rand() % (max - min + 1);

            // Apartado b - Mostrar valores por pantalla
            printf("%d ", produccion[i][j]);

            // Apartado d - Calcular mayor cantidad de ventas
            if (produccion[i][j] > mayor)
            {
                mayor = produccion[i][j];
                mes = j+1;
                anio = i+1;
            }
        }
        printf("\n");
    }

    // Apartado c - Promedio de ganancia por año
    for (int i=0 ; i<filas ; i++)
    {
        for (int j=0 ; j<columnas ; j++)
        {
            suma += produccion[i][j];
        }
        promedio = suma/12;
        printf("\nResumen del anio %d:", (i+1));
        printf("\n\tTotal de ventas: %d", suma);
        printf("\n\tPromedio de ventas: %.2f", promedio);
        suma = 0;
    }

    // Apartado d - Calcular mayor cantidad de ventas
    printf("\n\nLa mayor cantidad de ventas fueron: %d en el anio %d y mes %d",
        mayor,
        anio,
        mes
    );

    return 0;
}