#include <stdio.h>
#include <string.h>

struct Producto{
    char nombre[20];
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
}

struct Carrito{
    int index;
    int cantidad;
};

void AgregarAlCarrito(){
    int CantidadP;
    int i = 0;
    printf("¿Cuantos productos deseas agregar al carrito? :");
    scanf("%d", &CantidadP);
    struct Carrito carrito[CantidadP];
    while( i < CantidadP){
        int P;
        printf("ingresa el numero del producto que deseas agregar al carrito : \n");
        scanf("%d", &P);
        if(P<1 || P>6){
            printf("ingrese un producto que este dentro del menu");
        }
        P -= 1;
        printf("¿Cuántas unidades de '%s' deseas agregar? ", catalogo[P].nombre);
        scanf("%d", &carrito[i].cantidad);
        carrito[i].index = P;
        printf("Producto '%s' agregado al carrito. Cantidad: %d\n", catalogo[P].nombre, carrito[i].cantidad);
        i++;
    }
}

void MenuPrincipal() {
    int menu;
    printf("MENU \n");
    printf("1. Ver catalogo de productos \n");
    printf("2. Agregrar producto al carrito \n");
    printf("3. Ver carrito y total \n");
    printf("4. confirmar pedido \n");
    printf("ingresa el numero de la funcion que desees utilizar: ");
    scanf("%d", &menu);
    switch (menu){
        case 1: 
            Catalogo();
            break;
        case 2:
            AgregarAlCarrito(); 
            break;
        default:
            printf("error");
    }
}

int main(){
    MenuPrincipal();
    return 0;
}