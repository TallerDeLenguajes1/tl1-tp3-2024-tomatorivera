#include <stdio.h>
#include <time.h>

// constantes
#define filas 5
#define columnas 12

int main() {
    srand(time(NULL));

    int produccion[filas][columnas];
    int min = 10000, max = 50000, suma = 0, anioMayor, mesMayor, anioMenor, mesMenor, mayor = 0, menor = max+1;
    float promedio;

    for (int i=0 ; i<filas ; i++)
    {
        for (int j=0 ; j<columnas ; j++)
        {
            produccion[i][j] = min + rand() % (max - min + 1);

            // Apartado b - Mostrar valores por pantalla
            printf("%d ", produccion[i][j]);

            // Apartado d - Calcular mayor y menor cantidad de ventas
            if (produccion[i][j] > mayor)
            {
                mayor = produccion[i][j];
                mesMayor = j+1;
                anioMayor = i+1;
            }
            if (produccion[i][j] < menor)
            {
                menor = produccion[i][j];
                mesMenor = j+1;
                anioMenor = i+1;
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

    // Apartado d - Calcular mayor y menor cantidad de ventas
    printf("\n\nLa mayor cantidad de ventas fueron: %d en el anio %d y mes %d",
        mayor,
        anioMayor,
        mesMayor
    );
    printf("\nLa menor cantidad de ventas fueron: %d en el anio %d y mes %d",
        menor,
        anioMenor,
        mesMenor
    );

    return 0;
}