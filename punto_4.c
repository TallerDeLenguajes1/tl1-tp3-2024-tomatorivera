#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// Constantes y globales
#define N 5

// Estructuras
struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
                        // “CantidadProductosAPedir”
} typedef Cliente;

// Funciones
void cargarClientes(Cliente *clientes, int nClientes);

int main()
{
    srand(time(NULL));

    char *TiposProductos[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

    // Apartado i - Solicito al usuario la cantidad de clientes valida
    // entre 1 y 5 ya que en el enunciado dice que un preventista puede tener hasta 5 clientes
    int nClientes;
    do {
        printf("Ingrese la cantidad de clientes: ");
        scanf("%d", &nClientes);

        if (nClientes <= 0 || nClientes > 5) printf("[!] Ingrese una cantidad de clientes valida (entre 1 y 5 inclusive)\n");
    } while (nClientes <= 0 || nClientes > 5);

    // Apartado ii - Cargar los datos de los clientes
    Cliente *clientes = (Cliente *)malloc(nClientes * sizeof(Cliente));
    cargarClientes(clientes, nClientes);

    free(clientes);
    return 0;
}

/**
 * Realiza la carga de clientes 
 */
void cargarClientes(Cliente *clientes, int nClientes) {
    int ultimoIdCliente = 1;
    char buff[100];

    for (int i=0 ; i<nClientes ; i++)
    {
        // ID
        clientes[i].ClienteID = ultimoIdCliente;
        ultimoIdCliente++;

        // Nombre del cliente
        fflush(stdin);
        printf("Ingrese el nombre del cliente %d: ", (i+1));
        gets(buff);
        clientes[i].NombreCliente = malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(clientes[i].NombreCliente, buff);

        // Cantidad de productos a pedir
        clientes[i].CantidadProductosAPedir = 1 + rand() % 5;


    }
}