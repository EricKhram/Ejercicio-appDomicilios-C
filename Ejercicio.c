#include <stdio.h>
#include <string.h>

struct Producto{
    char nombre[30];
    int precio;
};

struct Producto catalogo[6] = {
    {"Hamburguesa en combo", 18000},
    {"Pizza personal", 15000},
    {"Lasagna para 2", 25000},
    {"Combo de alitas", 23000},
    {"Salchipapas", 30000},
    {"Gaseosa personal", 40000}
};

void Catalogo() {
    for (int i = 0; i < 6; i++) {
        int idmenu = i + 1;
        printf("Producto %d: %s, Precio: $%d\n", idmenu, catalogo[i].nombre, catalogo[i].precio);
    }
    MenuSalir();
}

struct Carrito {
    int index;
    int cantidad;
    int totalxproducto;
};

struct Carrito carrito [6];
int cantidadcarrito = 0;

void AgregarAlCarrito(){
    int CantidadP;
    int i = 0;
    printf("¿Cuantos productos deseas agregar al carrito? :");
    scanf("%d", &CantidadP);
    while( i < CantidadP){
        int P;
        printf("ingresa el numero del producto que deseas agregar al carrito : \n");
        scanf("%d", &P);
        if(P<1 || P>6){
            printf("ingrese un producto que este dentro del menu \n");
            i--;
            continue;
        }
        P -= 1;
        printf("¿Cuántas unidades de '%s' deseas agregar? ", catalogo[P].nombre);
        scanf("%d", &carrito[i].cantidad);
        carrito[i].index = P;
        carrito[i].totalxproducto = catalogo[P].precio * carrito[i].cantidad;
        printf("Producto '%s' agregado al carrito. Cantidad: %d. Precio total: %d \n", catalogo[P].nombre, carrito[i].cantidad, carrito[i].totalxproducto);
        i++;
        cantidadcarrito++;
    }
    MenuSalir();
}

void MostrarCarrito() {
    if(cantidadcarrito == 0){
        printf("CARRITO VACIO!! \n");
    }else{
            int totalcarrito = 0;
            for (int i = 0; i < cantidadcarrito; i++) {
                int idcarrito = i + 1;
                 printf(" %s, Cantidad: %d ,Precio total: $%d\n", catalogo[carrito[i].index].nombre, carrito[i].cantidad, carrito[i].totalxproducto);
                totalcarrito += carrito[i].totalxproducto;
            }
            printf("el total de su carrito es: %d \n",totalcarrito);
    } 
    MenuSalir();
}

void ConfirmarPedido(){
    if (cantidadcarrito == 0){
        printf("No se puede confirmar un pedido sin productos\n");
    }else{
        printf("PEDIDO CONFIRMADO!! \n");
        printf("RESUMEN: \n");
        MostrarCarrito();
        printf("GRACIAS POR SU COMPRA, VUELVA PRONTO!!");
    }

}

void MenuSalir() {
    int salir;
    printf("Que deseas hacer ahora: \n");
    printf("1. Regresar al menu \n");
    printf("2. Salir \n");
    scanf("%d", &salir);
    switch(salir){
        case 1:
            MenuPrincipal();
            break;
        case 2:
            printf("ADIOS \n");
            return;
        default:
            printf("ingrese una opcion valida");
    }
}

void MenuPrincipal() {
    int menu;
    printf("MENU \n");
    printf("1. Ver catalogo de productos \n");
    printf("2. Agregrar producto al carrito \n");
    printf("3. Ver carrito y total \n");
    printf("4. Confirmar pedido \n");
    printf("5. Salir \n");
    printf("ingresa el numero de la funcion que desees utilizar: ");
    scanf("%d", &menu);
    switch (menu){
        case 1: 
            Catalogo();
            break;
        case 2:
            AgregarAlCarrito(carrito); 
            break;
        case 3:
            MostrarCarrito();
            break;
        case 4: 
            ConfirmarPedido();
            break;
        case 5:
            printf("HASTA LUEGO \n");
            return;
        default:
            printf("ingrese una funcion valida del menu \n");
            break;
    }
}

int main(){
    MenuPrincipal();
    return 0;
}