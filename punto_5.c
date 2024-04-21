#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int nNombres;
    printf("Ingrese la cantidad de nombres que desea almacenar: ");
    scanf("%d", &nNombres);

    fflush(stdin);

    char** nombres = malloc(nNombres * sizeof(char));
    char buff[100];

    // Cargo los nombres
    for (int i=0 ; i<nNombres ; i++)
    {
        printf("Ingrese el nombre %d: ", (i+1));
        gets(buff);

        nombres[i] = malloc((strlen(buff)+1) * sizeof(char));
        strcpy(nombres[i], buff);
    }

    // Muestro los nombres y libero memoria
    for (int i=0 ; i<nNombres ; i++)
    {
        puts(nombres[i]);
    }
    free(nombres);

    return 0;
}