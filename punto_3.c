#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// constantes
#define NOMBRES 5

int main() {
    char** nombres = malloc(NOMBRES * sizeof(char));
    char buff[100];

    // Cargo los nombres
    for (int i=0 ; i<NOMBRES ; i++)
    {
        printf("Ingrese el nombre %d: ", (i+1));
        gets(buff);

        nombres[i] = malloc((strlen(buff)+1) * sizeof(char));
        strcpy(nombres[i], buff);
    }

    // Muestro los nombres y libero memoria
    for (int i=0 ; i<NOMBRES ; i++)
    {
        puts(nombres[i]);
    }
    free(nombres);

    return 0;
}