#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// Constantes y globales
#define N 5
char *TiposProductos[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

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
void cargarProductos(Producto *productos, int nProductos);
float calcularCostoTotal(Producto producto);

int main()
{
    srand(time(NULL));

    // Apartado i - Solicito al usuario la cantidad de clientes valida
    // entre 1 y 5 ya que en el enunciado dice que un preventista puede tener hasta 5 clientes
    int nClientes;
    do {
        // Para que si el usuario ingresa una letra, no quede en bucle infinito el programa
        fflush(stdin);

        printf("Ingrese la cantidad de clientes: ");
        scanf("%d", &nClientes);
        
        if (nClientes <= 0 || nClientes > 5) printf("[!] Ingrese una cantidad de clientes valida (entre 1 y 5 inclusive)\n");
    } while (nClientes <= 0 || nClientes > 5);

    // Apartado ii/iii - Cargar los datos de los clientes y sus productos
    Cliente *clientes = (Cliente *)malloc(nClientes * sizeof(Cliente));
    cargarClientes(clientes, nClientes);

    // Apartado iv - Calcular costo total de un producto
    Cliente cliente = clientes[0];
    Producto producto = cliente.Productos[0];

    float precio = calcularCostoTotal(producto);
    printf("\n\n===== Costo total del producto =====");
    printf("\nCliente: %d - Producto %s (ID %d)", cliente.ClienteID, producto.TipoProducto, producto.ProductoID);
    printf("\n\tPrecio unitario: $%.2f - Cantidad: %d | Costo total: $%.2f", producto.PrecioUnitario, producto.Cantidad, precio);

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
        printf("\n\nIngrese el nombre del cliente %d: ", (i+1));
        gets(buff);
        clientes[i].NombreCliente = malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(clientes[i].NombreCliente, buff);

        // Cantidad de productos a pedir
        int nProductos = 1 + rand() % 5;
        clientes[i].CantidadProductosAPedir = nProductos;

        // Muestro en pantalla los datos del cliente para hacer un seguimiento de como va la carga de datos
        printf("CLIENTE %d: ", (i+1));
        printf("\n\tNombre: %s \n\tProductos asociados: %d", 
            clientes[i].NombreCliente,
            nProductos
        );

        // Carga de productos
        clientes[i].Productos = (Producto *)malloc(nProductos * sizeof(Producto));
        cargarProductos(clientes[i].Productos, nProductos);
    }
}

/**
 * Carga productos con caracteristicas aleatorias
 */
void cargarProductos(Producto *productos, int nProductos) {
    int ultimoIdProducto = 1;

    printf("\n\tProductos: ");
    for (int i=0 ; i<nProductos ; i++)
    {
        // ID
        productos[i].ProductoID = ultimoIdProducto;
        ultimoIdProducto++;

        // Cantidad
        productos[i].Cantidad = 1 + rand() % 10;

        // Tipo de producto
        productos[i].TipoProducto = TiposProductos[rand() % (5)];

        // Precio unitario
        productos[i].PrecioUnitario = 10 + rand() % 91;

        // Muestro por pantalla los datos del producto para hacer un seguimiento de como va la carga de datos
        printf("\n\t\tID: %d - CANTIDAD: %d - TIPO PRODUCTO: %s - PRECIO: $%.2f",
            productos[i].ProductoID,
            productos[i].Cantidad,
            productos[i].TipoProducto,
            productos[i].PrecioUnitario
        );
    }
}

/**
 * Calcula el costo total de un producto
 */
float calcularCostoTotal(Producto producto) {
    return producto.Cantidad * producto.PrecioUnitario;
}