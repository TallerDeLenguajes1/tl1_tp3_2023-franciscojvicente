#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 char* TiposProductos[]= {"Galletas","Cervezas","Cigarrillos","Caramelos","Bebidas"};

struct {
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
}typedef Producto;

struct {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}typedef Cliente;

Producto CargarProducto();
Cliente CargarCliente();
Cliente* CargarClientes(int cant);
void MostrarProducto(Producto prod);
void MostrarProductos(Producto* productos, int cant);
void MostrarCliente(Cliente client);
void MostrarClientes(Cliente* clientes, int cant);
void CalcularCosto (Cliente* clientes, int cant);

int main(){
    printf("Ingrese la cantidad de clientes; \n");
    int cantclientes;
    scanf("%d",&cantclientes);
    Cliente* datosclientes;
    datosclientes = CargarClientes(cantclientes);
    MostrarClientes(datosclientes , cantclientes);
    CalcularCosto (datosclientes , cantclientes);

    for(int i=0;i<cantclientes;i++){
        for(int j=0;j<cantclientes;j++){
            free(datosclientes[i].Productos[j].TipoProducto);
        }
        free(datosclientes[i].NombreCliente);
    }
    free(datosclientes);
    
    return 0;
}

Producto CargarProducto(){
    Producto aux;
    aux.Cantidad=rand()%9+1;
    aux.TipoProducto=(char*) malloc(12*sizeof(char));
    aux.TipoProducto=TiposProductos[rand()%5];
    aux.PrecioUnitario=rand()%91+10;
    return(aux);
}

Cliente CargarCliente(){
    Cliente aux;
    aux.NombreCliente=(char*)malloc(sizeof(char)*30);
    printf("Ingrese su nombre(max:30 caracteres):\n");
    fflush(stdin);
    gets(aux.NombreCliente);
    aux.CantidadProductosAPedir=rand()%5+1;
    aux.Productos=(Producto*)malloc(aux.CantidadProductosAPedir*sizeof(Producto));
    for(int i=0;i<aux.CantidadProductosAPedir;i++){
        aux.Productos[i]=CargarProducto();
        aux.Productos[i].ProductoID=i;
    }
    return(aux);
}

Cliente* CargarClientes(int cant){
    Cliente* aux;
    aux=(Cliente*)malloc(sizeof(Cliente)*cant);
    for(int i=0;i<cant;i++){
        aux[i]=CargarCliente();
        aux[i].ClienteID=i;
    }
return(aux);
} 

void MostrarProducto(Producto prod){
    printf("ID: %d\n",prod.ProductoID);
    printf("Tipo: ");
    puts(prod.TipoProducto);
    printf("Cantidad: %d\n",prod.Cantidad);
    printf("Precio por unidad: %f\n",prod.PrecioUnitario);
}
void MostrarProductos(Producto* productos, int cant){
    for (int i=0;i<cant;i++){
    printf("------  PRODUCTO %d -------\n",i+1);
    MostrarProducto(productos[i]);
    }

}

void MostrarCliente(Cliente client){
    printf("ID cliente: %d\n",client.ClienteID);
    printf("Nombre del cliente: %s\n",client.NombreCliente);
    printf("Cantidad de productos a pedir:%d\n",client.CantidadProductosAPedir);
    MostrarProductos(client.Productos,client.CantidadProductosAPedir);

}

void MostrarClientes(Cliente* clientes, int cant){
    for(int i=0;i<cant;i++){
        printf("\n");
        printf("\n");
        printf("=========CLIENTE %d===============",i+1);
         MostrarCliente(clientes[i]);
    }
}

void CalcularCosto (Cliente* clientes, int cant){
    char* dato;
    int total;
    int id;
    printf("Ingrese el nombre del cliente\n");
    dato=(char*)malloc(30*sizeof(int));
    gets(dato);
    for(int i=0;i<cant;i++){
        if(strcmp(dato,clientes[i].NombreCliente)==0){
            printf("Ingrese el id del producto\n");
            scanf("%d",&id);
            for(int j=0;j<clientes[i].CantidadProductosAPedir;j++){
                if(id==clientes[i].Productos[j].ProductoID){
                    total=clientes[i].Productos[j].Cantidad*clientes[i].Productos[j].PrecioUnitario;
                    printf("El total de %s es %d\n",clientes[i].Productos[j].TipoProducto,total);
                }
            }
        }
    }
    
}