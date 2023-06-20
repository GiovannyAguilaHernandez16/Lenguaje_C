//BIBLIOTECAS
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char cadena[50];
//MATRICES
char registro[50][70][50];
char ventas[50][70][50];

/* ---- FUNCIONES ---- */
void Pantalla_De_Inicio();

// OPCIONES correspondientes al Menu, [1-3]
//Productos 
void agregar();
void modificar();
void EliminarProductos();

// Articulos en Stock
void imprimir();
void imprimirventas();

// OPCIONES correspondientes al Menu, [4-6]
// Ventas
void realizarventas();
void modificar_venta();
void eliminarventa();

// OPCIONES correspondientes al Menu, [6-9]
// Filtrar las Ventas Realizadas
void refacciones_mecanicas();
void refacciones_electricas();
// Mostar la suma del Total de Ventas de las piezas Electricas o Mecanicas, Segun la Opcion Elegida del Usuario.
float sumar_ventas_pcc(int tipo_producto); // Sumar Ventas Por Cada Caso [P.C.C] Unicamente las Electricas o Unicamente Mecanicas
float sumar_ventas(); // Sumar las Ventas de los productos Electricos y Mecanicos 

// OPCION correspondiente al Menu, [10]           
void salir();
/* ---- Fin Apartado de Funciones del Programa ---- */



// VARIABLES Globales
int i;
int cantidadExistente;
// int ventas;
int contador;
int numVentas;
int ventas_totales;
int cantidadoriginal;
int opcion;
int productos;
int ventas_realizadas; //asigna el ID en las ventas, asegurando que se incremente adecuadamente en cada ejecución.
// Fin del Apartado de Variables Globales


//INICIO DEL PROGRAMA PRINCIPAL
int main (){
    setlocale(LC_ALL,"");
    productos = 10;
//matriz llenada con informacion
    strcpy(registro[0][0],"1");
    strcpy(registro[0][1],"Llanta");
    strcpy(registro[0][2],"Mecanica");
    strcpy(registro[0][3],"50");
    strcpy(registro[0][4],"1500");

    strcpy(registro[1][0],"2");
    strcpy(registro[1][1],"Gato hidraulico");
    strcpy(registro[1][2],"Mecanica");
    strcpy(registro[1][3],"14");
    strcpy(registro[1][4],"1000");

    strcpy(registro[2][0],"3");
    strcpy(registro[2][1],"Volantes");
    strcpy(registro[2][2],"Electrica");
    strcpy(registro[2][3],"20");
    strcpy(registro[2][4],"500");

    strcpy(registro[3][0],"4");
    strcpy(registro[3][1],"Calaveras");
    strcpy(registro[3][2],"Electrica");
    strcpy(registro[3][3],"26");
    strcpy(registro[3][4],"1700");

    strcpy(registro[4][0],"5");
    strcpy(registro[4][1],"Focos");
    strcpy(registro[4][2],"Electrica");
    strcpy(registro[4][3],"60");
    strcpy(registro[4][4],"75");

    strcpy(registro[5][0],"6");
    strcpy(registro[5][1],"Fusiles");
    strcpy(registro[5][2],"Electrica");
    strcpy(registro[5][3],"120");
    strcpy(registro[5][4],"250");

    strcpy(registro[6][0],"7");
    strcpy(registro[6][1],"Marcha Automotriz");
    strcpy(registro[6][2],"Electrica");
    strcpy(registro[6][3],"32");
    strcpy(registro[6][4],"1850");

    strcpy(registro[7][0],"8");
    strcpy(registro[7][1],"Palanca de direccionales");
    strcpy(registro[7][2],"Electrica");
    strcpy(registro[7][3],"80");
    strcpy(registro[7][4],"500");

    strcpy(registro[8][0],"9");
    strcpy(registro[8][1],"Frenos");
    strcpy(registro[8][2],"Mecanica");
    strcpy(registro[8][3],"21");
    strcpy(registro[8][4],"1899");

    strcpy(registro[9][0],"10");
    strcpy(registro[9][1],"Claxon");
    strcpy(registro[9][2],"Mecanica");
    strcpy(registro[9][3],"13");
    strcpy(registro[9][4],"270");
    
    Pantalla_De_Inicio();
    
    printf("                                                                                                                     Presiona [ENTER/INTRO] Para dar Inicio al Programa  ");
    getch();
    system("cls"); // Limpiar la pantalla
    
    
    imprimir(); //llamada a la funcion para imprimir Los Datos Guardadeos en la Matriz

    // Impresion del Menu de Opciones
    do {
        printf("\n\t     MENU: \n\n");
        printf("\t Seleccione una opcion: \n\n");
        printf("\t PRODUCTOS: \n");
        printf("\t [1] Dar de alta Productos  \n");
        printf("\t [2] Modificar Productos    \n");
        printf("\t [3] Eliminar Productos     \n");
        printf("\n\t VENTAS: \n");
        printf("\t [4] Realizar Venta         \n");
        printf("\t [5] Modificar Venta        \n");
        printf("\t [6] Cancelar (Eliminar) Venta  \n");
        printf("\n\t FILTRAR VENTAS: \n");
        printf("\t [7] Mostrar Ventas de Refacciones Eléctricas por Fecha y su Total\n");
        printf("\t [8] Mostrar Ventas de Refacciones Mecánicas por Fecha y su Total \n");
        printf("\t [9] Mostrar Total de Ventas de Refacciones por Fecha y su Total  \n");
        printf("\n\t SALIDA: \n");
        printf("\t [10] Salir\n\n");

        printf("\t Opción:  > ");
        scanf("%d", &opcion); // lectura de la opcion a realizar
        
        
        
        
        switch (opcion) {
            case 1:
				system("cls"); // Limpiar la pantalla
                agregar();
                imprimir(); //llamada a la funcion para imprimir la tabla de productos
                imprimirventas();
                break;
            case 2:
            	system("cls"); // Limpiar la pantalla
            	imprimir(); //llamada a la funcion para imprimir la tabla de productos
                modificar();
                imprimir(); //llamada a la funcion para imprimir la tabla de productos
                imprimirventas();
                break;
             case 3:
                EliminarProductos();
                system("cls"); // Limpiar la pantalla
                imprimir();
                imprimirventas();
                break;
                
                  
             case 4:
             	system("cls"); // Limpiar la pantalla
            	imprimir(); //llamada a la funcion para imprimir la tabla de productos
            	imprimirventas();
            	
                realizarventas();
                system("cls"); // Limpiar la pantalla
                imprimir(); //llamada a la funcion para imprimir la tabla de productos
            	imprimirventas();
                break;
             case 5:
             	system("cls"); // Limpiar la pantalla
            	imprimir(); //llamada a la funcion para imprimir la tabla de productos
            	imprimirventas();
                modificar_venta ();
                imprimirventas();
                system("cls"); // Limpiar la pantalla
                imprimir();
                imprimirventas();
                break;
             case 6:
                eliminarventa();
                system("cls"); // Limpiar la pantalla
                imprimir();
                imprimirventas();
                break;
                
                
             case 7:
                system("cls"); // Limpiar la pantalla
                refacciones_electricas();
                break;
             case 8:
                system("cls"); // Limpiar la pantalla
                refacciones_mecanicas();
                
                break;
             case 9:
             	system("cls"); // Limpiar la pantalla
                imprimirventas();
                sumar_ventas();
                break;
                
                
            case 10:
            	system("cls"); // Limpiar la pantalla
                salir();
                break;
            default:
                printf("\t Opción no válida, pesione [ENTER/INTRO] ");
                getch();
                system("cls"); // Limpiar la pantalla
                imprimir();
                break;
        }
    } while (opcion != 10);
    return 0;
} // FIN DEL PROGRAMA PRINCIPAL




// Apartado de Funciones:

// Imprime la Tabla de los Datos que se van guardando en la Matriz, se manda a invocar cuando se nescesita, al PROGRAMA PRINCIPAL.
void imprimir() {
    printf("\n\t\t  REFACCIONARIA AUTOMOTRIZ GENERAL ELECTRIC \t\n");
    printf(" ------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf(" ¦   No. del Producto    ¦   Producto                     ¦   Tipo (Electrica ó Mecanica)    ¦   Existencia             ¦   Precio              ¦\n");
    printf(" ------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < productos; i++) {
        printf(" ¦   No: %-15s ¦   %-25s    ¦   Tipo: %-24s ¦   Existencia: %-10s ¦   Precio: $%-10s ¦\n",
               registro[i][0], registro[i][1], registro[i][2], registro[i][3], registro[i][4]);
        printf(" ------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
} // Fin Funcion Tabla

// Imprime conforme se actualizan los datos almacenados en la Matriz, correspondiente a las Ventas Realizados correspondientes alas opciones [3-6] 
void imprimirventas() {
    int id;
    int total = 0;
    printf("\n\t\t\t\t\t\t    REGISTRO DE VENTAS ´GENERAL ELECTRIC´ \n");
    printf("\t\t\t   --------------------------------------------------------------------------------------------\n");
    printf("\t\t\t   ¦  ID   ¦  Fecha           ¦   No. de Producto   ¦   Cantidad Comprada   ¦    Importe      ¦ \n");
    printf("\t\t\t   --------------------------------------------------------------------------------------------\n");

    for (i = 0; i < ventas_totales; i++) {
        printf("\t\t\t   ¦  %-3s  ¦  %-15s ¦   No: %-13s ¦   Cant: %-12s  ¦    $%-10s  ¦\n",
		       ventas[i][0], ventas[i][1], ventas[i][2], ventas[i][3],  ventas[i][4]);
    printf("\t\t\t   --------------------------------------------------------------------------------------------\n");
	}
	printf("\n");
}




/* ---- Productos --------- */
void agregar() {
    int cantidadProductos;
    int i;

    printf("\n   Ingrese la cantidad de productos que desea agregar: ");
    scanf("%d", &cantidadProductos);
    
    if (productos + cantidadProductos <= 50) {

        for (i = 0; i < cantidadProductos; i++) {
			getchar ();
            sprintf(registro[productos][0], "%d", productos + 1); 

            printf("\n   ------------ Producto (%i) ---------------\n\n",i+1);
            printf("   Ingrese el nombre del producto: ");
            gets(registro[productos][1]);

            printf("   Ingrese el tipo del producto (Electrica o Mecanica): ");
            gets(registro[productos][2]);

            printf("   Ingrese la existencia del producto: ");
            gets(registro[productos][3]);

            printf("   Ingrese el precio del producto: ");
            gets(registro[productos][4]);

            productos++;

            printf("\n   Producto %i agregado Correctamente.\n",i+1);
        }
        printf("\n\n\n\n   Productos Agragados Correctamente");
        printf("\n   Presione [ENTER/INTRO] Para Visualizarlos en el Inventario ...");
        getchar(); // Esperar a que se presione una tecla
		system("cls"); // Limpiar la pantalla
    } else {
        printf("\nNo se pueden agregar más productos. El almacén está lleno.\n");
    }
    
} // Fin de Funcion de Agregar Productos [1] OPCION 1
void modificar(){
	int i;
	int productomodificar;
	int registromodificar;
printf ("\n --------- Modificacion de Datos Guardados en el Inventario --------------------\n");
printf ("\n   Numero del producto a modificar (No.): ");
scanf ("%i",&productomodificar);

printf ("\n   Elige que Campo de registro, del producto, que quieres modificar:\n\n");
printf ("    - [1] Nombre\n");
printf ("    - [2] Tipo\n");
printf ("    - [3] Existencia\n");
printf ("    - [4] Precio\n");
printf ("\n    - Opción:  > ");
scanf ("%i",&registromodificar);
        
for (i=0;i<=1;i++){
getchar(); 
i=productomodificar;
printf ("\n   Modificacion: ");
gets(registro[i-1][registromodificar]);

}
system("cls"); // Limpiar la pantalla
} // Fin Funcion Modificar Productos Guardados [2] OPCION 2
void EliminarProductos() {
    int eliminar;
    int i, j;
    printf ("\n\t Ingrese el Numero del producto que desea eliminar (No.): ");
    scanf("%d", &eliminar);

    if (eliminar > 0 && eliminar <= productos) {
        // Desplazar los productos posteriores una posición hacia atrás
        for (i = eliminar - 1; i < productos - 1; i++) {
            for (j = 0; j < 11; j++) {
                strcpy(registro[i][j], registro[i + 1][j]); //copiar los valores del producto que sigue en la lista al producto actual
            }
            // Actualizar el ID del contacto eliminado
            sprintf(registro[i][0], " %d", i + 1);
        }

        productos--; // Reducir la cantidad de productos
        //imprimir();
    }
	else{
        printf("Numero de producto inválido. Intente nuevamente\n");
    }
} // Fin de Funcion Eliminar Productos [3] OPCION 3


/* ---- Ventas ---- */
void realizarventas() {
    int total = 0;
    int i;
    int id;
    printf("\n\t\t   REGISTRO DE VENTAS   \n\n");
    printf("   Cantidad de productos a vender: ");
    scanf("%d", &numVentas);

    if (ventas_totales + numVentas <= 50) {
        for (i = 0; i < numVentas; i++) {
            getchar();
            sprintf(ventas[ventas_totales][0], "%d", ventas_realizadas + 1);  // Asignar ID en la columna 5
            printf("\n   El [ID] de esta Venta sera: %s", ventas[ventas_totales][0]);  // Impresión del ID asignado
            printf("\n\n   - Ingrese la Fecha del Dia de Hoy Bajo el Siguiente Formato [DDMMAAAA]: ");
            gets(ventas[ventas_totales][1]);
            printf("\n   -Numero de producto vendido (No.): ");
            gets(ventas[ventas_totales][2]);
            printf("   -Ingrese la Cantidad del Articulo en cuestion: ");
            gets(ventas[ventas_totales][3]);
            ventas_realizadas++;  //aumenta el id

            // Obtener el número de producto y la cantidad vendida
            int num = atoi(ventas[ventas_totales][2]);
            int cantidad = atoi(ventas[ventas_totales][3]);

            // Obtener el precio del producto
            int precio = atoi(registro[num - 1][4]);

            // Calcular el importe
            int importe = precio * cantidad;
            printf("\n   El Importe del Producto es: $%i\n", importe);

            //Copiar el importe a la matriz
			sprintf(ventas[ventas_totales][4], "%d", importe);

			//calcular el importe total
            total += importe;

 cantidadoriginal = atoi(registro[num - 1][3]);//cantidad del almacen sin modificar para poder utilizarla en modificar y eliminar
            // Actualizar la cantidad en existencia del producto
            cantidadExistente = atoi(registro[num - 1][3]);
            int cantidadRestante = cantidadExistente - cantidad;
            sprintf(registro[num - 1][3], "%d", cantidadRestante);

            ventas_totales++;
            printf("\n   Producto vendido Correctamente\n");
        }
        printf("\n\n   Importe Total de las Ventas Realizadas: $%i\n", total);
    }
}
void modificar_venta() {
    int id;
    int opcion;
    printf("\n\t\t\t\t\t\t    MODIFICAR VENTA   \n");
    printf("\t\t\t   - Ingrese el [ID] de la venta que desea modificar: ");
    scanf("%d", &id);

    int i;
    for (i = 0; i < ventas_totales; i++) {
        if (atoi(ventas[i][0]) == id) {
            printf("\n\t\t\t   Venta encontrada:\n");
            
            printf("\t\t\t   --------------------------------------------------------------------------------------------\n");
            printf("\t\t\t   ¦  ID   ¦  Fecha           ¦   No. de Producto   ¦   Cantidad Comprada   ¦    Importe      ¦ \n");
            printf("\t\t\t   --------------------------------------------------------------------------------------------\n");
            printf("\t\t\t   ¦  %-3s  ¦  %-15s ¦   No: %-13s ¦   Cant: %-12s  ¦    $%-10s  ¦\n",
		                       ventas[i][0], ventas[i][1], ventas[i][2], ventas[i][3],  ventas[i][4]);
			printf("\t\t\t   --------------------------------------------------------------------------------------------\n");


            printf("\n\t\t\t   ¿Qué campo desea modificar?\n");
            printf("\t\t\t   1. Fecha\n");
            printf("\t\t\t   2. Cantidad\n");
            printf("\t\t\t   Opción: ");
            scanf("%d", &opcion);

            switch (opcion) {
                case 1:
                    printf("\t\t\t   Nueva fecha: ");
                    getchar();
                    gets(ventas[i][1]);
                    break;
                case 2:
                    printf("\t\t\t   Nueva cantidad comprada: ");
                    getchar();
                    gets(ventas[i][3]);

                    // Obtener el número de producto y la cantidad vendida
                    int num = atoi(ventas[i][2]);
                    int nuevaCantidad = atoi(ventas[i][3]);

                    // Obtener la cantidad original del producto en el almacén
                    int cantidadOriginal = atoi(registro[num - 1][3]);

                    // Calcular el importe
                    int importe = nuevaCantidad * atoi(registro[num - 1][4]);
                    printf("\t\t\t   El importe del Producto es: %d\n", importe);

                    // Actualizar el importe en ventas
                    sprintf(ventas[i][4], "%d", importe);

                    // Actualizar la cantidad en existencia del producto en el almacén

                    int cantidadRestante = cantidadoriginal - nuevaCantidad;
                    sprintf(registro[num - 1][3], "%d", cantidadRestante);
            }
        }
    }
}
void eliminarventa() {
    int elimventa;
    int i, j, num, cantidad;
    printf("\n\t - Escribe el número de venta que deseas eliminar: ");
    scanf("%i", &elimventa);
    int total = 0;

    printf("\n\t\tREGISTRO DE VENTAS\n");

    if (elimventa > 0 && elimventa <= ventas_totales) {
        // Obtener el número de producto y la cantidad vendida de la venta a eliminar
        num = atoi(ventas[elimventa - 1][2]);
        cantidad = atoi(ventas[elimventa - 1][3]);

        // Regresar la cantidad de existencias en el almacén
        int cantidadRestante = atoi(registro[num - 1][3]);
        cantidadRestante += cantidad;
        sprintf(registro[num - 1][3], "%d", cantidadRestante);

        // Desplazar las ventas  una posición hacia atrás
        for (i = elimventa - 1; i < ventas_totales - 1; i++) {
            for (j = 0; j < 5; j++) {
                strcpy(ventas[i][j], ventas[i + 1][j]);
            }

            // Actualizar el ID del producto eliminado
            sprintf(ventas[i][0], " %d", i + 1);

            // Obtener el número de producto y la cantidad vendida
            num = atoi(ventas[i][2]);
            cantidad = atoi(ventas[i][3]);

            // Calcular el importe
            int precio = atoi(registro[num - 1][4]);
            int importe = precio * cantidad;
            printf("El importe del producto es: %i\n", importe);
            sprintf(ventas[i][4], "%d", importe);
            total += importe;
        }

        ventas_totales--; // Reducir la cantidad de ventas
    }

    printf("Importe total: %i\n", total);
}


/* ---- Filtrar Ventas --------- */
float sumar_ventas() {
    float total_ventas_totales = 0.0;
    
    for ( i = 0; i < ventas_totales; i++) {
        float importe = atof(ventas[i][4]);
        total_ventas_totales += importe;
    }
    printf("\n\t\t   Total de la Venta De Refacciones [ELECTRICAS Y MECANICAS] : $%.2f\n", total_ventas_totales);
    return total_ventas_totales;
    
}
float sumar_ventas_pcc(int tipo_producto) {
    float total_ventas = 0.0;
    
    for ( i = 0; i < ventas_totales; i++) {
        int x = atoi(ventas[i][2]);
        int y = strlen(registro[x - 1][2]);
        
        if (tipo_producto == 1 && y == 9) { // Producto eléctrico
            float importe = atof(ventas[i][4]);
            total_ventas += importe;
        } else if (tipo_producto == 2 && y == 8) { // Producto mecánico
            float importe = atof(ventas[i][4]);
            total_ventas += importe;
        }
    }
    
    return total_ventas;
}
void refacciones_electricas() {
    printf("\n\t\t    REGISTRO DE VENTAS ´GENERAL ELECTRIC´ Refacciones ELECTRICAS   \n");
    printf("\t\t   --------------------------------------------------------------------------------------------\n");
    printf("\t\t   ¦  ID   ¦  Fecha           ¦   No. de Producto   ¦   Cantidad Comprada   ¦    Importe      ¦ \n");
    printf("\t\t   --------------------------------------------------------------------------------------------\n");
    
    for ( i = 0; i < ventas_totales; i++) {
        int x = atoi(ventas[i][2]);
        int y = strlen(registro[x - 1][2]);
        
        if (y == 9) {
            printf("\t\t   ¦  %-3s  ¦  %-15s ¦   No: %-13s ¦   Cant: %-12s  ¦    $%-10s  ¦\n",
                   ventas[i][0], ventas[i][1], ventas[i][2], ventas[i][3], ventas[i][4]);
            printf("\t\t   --------------------------------------------------------------------------------------------\n");
        }
    }
    
    float total_ventas = sumar_ventas_pcc(1); // Suma de ventas de productos eléctricos
    printf("\n\t\t   Total de ventas de productos eléctricos: $%.2f\n", total_ventas);
}
void refacciones_mecanicas() {
    printf("\n\t\t    REGISTRO DE VENTAS ´GENERAL ELECTRIC´ Refacciones MECANICAS   \n");
    printf("\t\t   --------------------------------------------------------------------------------------------\n");
    printf("\t\t   ¦  ID   ¦  Fecha           ¦   No. de Producto   ¦   Cantidad Comprada   ¦    Importe      ¦ \n");
    printf("\t\t   --------------------------------------------------------------------------------------------\n");
    
    for ( i = 0; i < ventas_totales; i++) {
        int x = atoi(ventas[i][2]);
        int y = strlen(registro[x - 1][2]);
        
        if (y == 8) {
            printf("\t\t   ¦  %-3s  ¦  %-15s ¦   No: %-13s ¦   Cant: %-12s  ¦    $%-10s  ¦\n",
                   ventas[i][0], ventas[i][1], ventas[i][2], ventas[i][3], ventas[i][4]);
            printf("\t\t   --------------------------------------------------------------------------------------------\n");
        }
    }
    
    float total_ventas = sumar_ventas_pcc(2); // Suma de ventas de productos mecánicos
    printf("\n\t\t   Total de ventas de productos mecánicos: $%.2f\n", total_ventas);
}








/* --- Funcion (Salir del Programa) --- 
Crea un Efecto de Dibujo de Contorno en el Mensaje dedespededida y se agradece al Usuario por Utilizar el Programa de Nuestra Autoria*/
void salir(){
  	
int i;

  // Animacion de un punto detras de otro para Simular Carga ...		
  printf("\n\n   Saliendo del programa ");
  Sleep(100);
  printf(" *");
  Sleep(100);
  printf(" *");
  Sleep(100);
  printf(" *");
  Sleep(100);

  // Fin Animacion
     
     
     
	 //Linea 1 
       for (i = 0; i < 86; i++) {
      	Sleep(3);
        printf(" *");
  }   
  //Fin Linea 1

  printf("\n  *                                                                                                                                                                                                        *\n");
  printf("  *               Su programa Presento:                                                                                                                                                                    *\n");
  printf("  *                                                                                                                                                                                                        *\n");                                                                                                                                                          
  printf("  *              -¿Algun Problema? o ¿Nescecita ayuda para su Uso?,                                                                                                                                        *    \n");
  printf("  *              -Llame a Servicio al Cliente ( 246-217-8555 ) ellos lo Atenderan.                                                                                                                         *\n");
  printf("  *                                                                                                                                                                                                        *\n");
  printf("  *                               En dado Caso de Solicitar un Rembolso:                                                                                                                                   *     \n");
  printf("  *                                                                                                                                                                                                        *\n");
  printf("  *                               -Presente su Factura de Compra del Programa en Cuestion + Su RFC, al ( 246-217-8555 ).                                                                                   *   \n");
  printf("  *                                                                                                                                     -Gracias por usar nuestros Servicios MICROSOFT´2023-2025´(R)       *   \n");
  printf("  *                                                                                                                                                                                                        *\n ");                                                                                                                                                          
  


// Linea 2
       for (i = 0; i < 101; i++) {
      	Sleep(3);
        printf(" *");
  }   // Fin Linea 2 
  

    printf("\n\n\n\n\t\t El Equipo de Desarrollo Agradece su Preferencia con nuestros Productos:\n\n\n");
    printf("\t\t - GIOVANNY AGUILA HERNANDEZ.\n\n");
    printf("\t\t - ISABELA RAMIREZ CRUZ.\n\n");
    printf("\t\t - VALERIA ARIADNA SASTRE HERNANDEZ.\n\n");
    printf("\t\t - DENIS RUBI MUÑOZ RODRIGUEZ. \n\n");
    printf("\t\t - YEZMIN ZAMORA CERVANTES .\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

}   



/* --- Funcion de Pantalla de Inicio del Programa ( Animacion de una serie de Autos Estacionandeoce ) ---  */
void Pantalla_De_Inicio() {
	
        Auto_uno();
        Sleep(100); // Pausa de 1 segundo entre cada iteración (1000 ms)
        system("cls");

        Auto_dos();
        Sleep(100); // Pausa de 1 segundo entre cada iteración (1000 ms)
        system("cls");
        
        Auto_tres();
        Sleep(100); // Pausa de 1 segundo entre cada iteración (1000 ms)
        system("cls");
            
        Auto_cuatro();
        Sleep(100); // Pausa de 1 segundo entre cada iteración (1000 ms)
        system("cls");
        
        Auto_cinco();
        Sleep(100); // Pausa de 1 segundo entre cada iteración (1000 ms)
        system("cls");

        Auto_seis();
        Sleep(100); // Pausa de 1 segundo entre cada iteración (1000 ms)
        system("cls");
        
        Auto_siete();
        Sleep(100); // Pausa de 1 segundo entre cada iteración (1000 ms)
        system("cls");
            
        Auto_ocho();
        Sleep(100); // Pausa de 1 segundo entre cada iteración (1000 ms)
        system("cls");
        
        Auto_nueve();
        Sleep(100); // Pausa de 1 segundo entre cada iteración (1000 ms)
        system("cls");

        Auto_diez();
        Sleep(100); // Pausa de 1 segundo entre cada iteración (1000 ms)
        system("cls");
        
        Auto_once();
        Sleep(100); // Pausa de 1 segundo entre cada iteración (1000 ms)
        system("cls");
            
        Auto_doce();
        Sleep(100); // Pausa de 1 segundo entre cada iteración (1000 ms)
        system("cls");
        
        Auto_trece();
        Sleep(100); // Pausa de 1 segundo entre cada iteración (1000 ms)
        system("cls");

        Auto_catorce();
        Sleep(100); // Pausa de 1 segundo entre cada iteración (1000 ms)
        system("cls");
        
        Auto_quince();
        Sleep(100); // Pausa de 1 segundo entre cada iteración (1000 ms)
        system("cls");
            
        Auto_diesciseis();
        Sleep(100); // Pausa de 1 segundo entre cada iteración (1000 ms)
        
    printf("                                                                                                                \\___________________________________________________________\n\n\n");    
    printf("            _______________________________________       _____________________________________________________________________________________________________               \n");
    printf("           /                                       \\     /                                                                                                     \\                  \n");
    printf("           |        !!!!! Bienvenidos !!!!!!        |    |                                                                                                     |                    \n");
    printf("           |                                        |    |   ____  _____ _____ _    ____ ____ ___ ___  _   _    _    ____  ___    _                            |                    \n");
    printf("           |            ¡Tenemos lo que             |    |  |  _ \\| ____|  ___/ \\  / ___/ ___|_ _/ _ \\| \\ | |  / \\  |  _ \\|_ _|  / \\                           |             \n");
    printf("           |              necesitas!                |    |  | |_) |  _| | |_ / _ \\| |  | |    | | | | |  \\| | / _ \\ | |_) || |  / _ \\                          |                \n");
    printf("           |                                        |    |  |  _ <| |___|  _/ ___ | |__| |___ | | |_| | |\\  |/ ___ \\|  _ < | | / ___ \\                         |                 \n");
    printf("           |     -> Amplia variedad de piezas       |    |  |_| \\_|_____|_|/_/   \\_\\____\\____|___\\___/|_| \\_/_/   \\_|_| \\_|___/_/   \\_\\                        |          \n");
    printf("           |     -> Calidad garantizada             |    |                                                                                                     |                    \n");
    printf("           |     -> Excelente servicio al cliente   |    |     --- ELECTRICA AUTOMOTRIZ GENERAL ELECTRIC ----------                                            |                    \n");
    printf("           |     -> Precios competitivos            |    |                                                                                                     |                    \n");
    printf("           |                                        |    |     - Accesorios Para tu Auto / Moto / Tractor / Trailer / Podadora / Bicicleta                     |                    \n");
    printf("           |     Ven y descubre nuestro catálogo    |    |                                                                                                     |                    \n");
    printf("           |     completo de repuestos y accesorios |    |     - Variedad en Piezas:                                                                           |                    \n");
    printf("           |     para tu automóvil.                 |    |        -> Mecanicas y                                                                               |                    \n");
    printf("           |                                        |    |         -> Electricas                                                                               |                    \n");
    printf("           |     Te esperamos en nuestra tienda:    |    |                                                                                                     |                    \n");
    printf("           |     Dirección: Calle Principal, No. 1  |    |      Contamos con Garantia de 8 meses Aviles despues de realizada tu Compra.                        |                    \n");
    printf("           |     Horario: Lunes a Viernes, 8am-6pm  |    |        - Solo Presenta tu Ticket de Compra,                                                         |                    \n");
    printf("           |                                        |    |        - + RFC y Tu INE.                                                                            |                    \n");
    printf("           |        ___                 ___         |    |                                                                                                     |                    \n");
    printf("           |       |   \\               /   |        |    |     + Si encuentra errores en el prgrama.   + Desea hacer valida su garantia, u otra razon.         |                   \n");
    printf("           |       | |\\ \\             / /| |        |    |       - Contacte a Servicio al Cliente, ellos lo atenderan:                                         |                  \n");
    printf("           |       | |_\\ \\           / /_| |        |    \\                                                                                                     /                 \n");
    printf("           |       |  ___ \\         / ___  |        |     -----------------------------------------------------------------------------------------------------                    \n");
    printf("           |       | |   \\ \\       / /   | |        |    ______________________________________________________________        ______________________________          \n");
    printf("           |       |_|    \\_\\_____/ /     |_|       |   /      Servicio de Atencion Al cliente: (246-217-8555)         \\    /                                  \\       \n");
    printf("           |        \\___________, /______ /         |  |                       [ - Horario:   ]                         |   | - Licenciado y optimizado por:   |          \n");
    printf("           |                   | /                  |  |                                                                |   |         -- GI.AG.HER ---         |          \n");
    printf("           \\                   |/                  /    \\     + 12am-8pm MX      + 12am-1pm EUA       +8am-1pm PRU     /    \\     + MICROSOFT (R) 2023         /            \n");
    printf("            ---------------------------------------      --------------------------------------------------------------        -------------------------------    \n\n\n");
	printf(" --------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");

}
void Auto_uno() {
    printf("                                                         _________________________   \n");
    printf("                    /\\      _____          _____       |   |     |     |    | |  \\  \n");
    printf("     ,-----,       /  \\____/__|__\\_    ___/__|__\\___   |___|_____|_____|____|_|___\\ \n");
    printf("  ,--'---:---`--, /  |  _     |     `| |      |      `| |                    | |    \\\n");
    printf(" ==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------------(o)--'  \n");
    printf("````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");

}            
void Auto_dos() {
    printf("                                                          _________________________   \n");
    printf("                     /\\      _____          _____       |   |     |     |    | |  \\  \n");
    printf("      ,-----,       /  \\____/__|__\\_    ___/__|__\\___   |___|_____|_____|____|_|___\\ \n");
    printf("   ,--'---:---`--, /  |  _     |     `| |      |      `| |                    | |    \\\n");
    printf("  ==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------------(o)--'  \n");
    printf("````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");

}   		
void Auto_tres() {
    printf("                                                           _________________________   \n");
    printf("                      /\\      _____          _____       |   |     |     |    | |  \\  \n");
    printf("       ,-----,       /  \\____/__|__\\_    ___/__|__\\___   |___|_____|_____|____|_|___\\ \n");
    printf("    ,--'---:---`--, /  |  _     |     `| |      |      `| |                    | |    \\\n");
    printf("   ==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------------(o)--'  \n");
    printf("````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");

}	
void Auto_cuatro() {
    printf("                                                            _________________________   \n");
    printf("                       /\\      _____          _____       |   |     |     |    | |  \\  \n");
    printf("        ,-----,       /  \\____/__|__\\_    ___/__|__\\___   |___|_____|_____|____|_|___\\ \n");
    printf("     ,--'---:---`--, /  |  _     |     `| |      |      `| |                    | |    \\\n");
    printf("    ==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------------(o)--'  \n");
    printf("````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");

}     
void Auto_cinco() {
    printf("                                                             _________________________   \n");
    printf("                        /\\      _____          _____       |   |     |     |    | |  \\  \n");
    printf("         ,-----,       /  \\____/__|__\\_    ___/__|__\\___   |___|_____|_____|____|_|___\\ \n");
    printf("      ,--'---:---`--, /  |  _     |     `| |      |      `| |                    | |    \\\n");
    printf("     ==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------------(o)--'  \n");
    printf("````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");

}       
void Auto_seis() {
    printf("                                                              _________________________   \n");
    printf("                         /\\      _____          _____       |   |     |     |    | |  \\  \n");
    printf("          ,-----,       /  \\____/__|__\\_    ___/__|__\\___   |___|_____|_____|____|_|___\\ \n");
    printf("       ,--'---:---`--, /  |  _     |     `| |      |      `| |                    | |    \\\n");
    printf("      ==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------------(o)--'  \n");
    printf("````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");

}   	
void Auto_siete() {
    printf("                                                               _________________________   \n");
    printf("                          /\\      _____          _____       |   |     |     |    | |  \\  \n");
    printf("           ,-----,       /  \\____/__|__\\_    ___/__|__\\___   |___|_____|_____|____|_|___\\ \n");
    printf("        ,--'---:---`--, /  |  _     |     `| |      |      `| |                    | |    \\\n");
    printf("       ==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------------(o)--'  \n");
    printf("````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");

}    			
void Auto_ocho() {
    printf("                                                                _________________________   \n");
    printf("                           /\\      _____          _____       |   |     |     |    | |  \\  \n");
    printf("            ,-----,       /  \\____/__|__\\_    ___/__|__\\___   |___|_____|_____|____|_|___\\ \n");
    printf("         ,--'---:---`--, /  |  _     |     `| |      |      `| |                    | |    \\\n");
    printf("        ==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------------(o)--'  \n");
    printf("````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");

}   
void Auto_nueve() {
    printf("                                                                 _________________________   \n");
    printf("                            /\\      _____          _____       |   |     |     |    | |  \\  \n");
    printf("             ,-----,       /  \\____/__|__\\_    ___/__|__\\___   |___|_____|_____|____|_|___\\ \n");
    printf("          ,--'---:---`--, /  |  _     |     `| |      |      `| |                    | |    \\\n");
    printf("         ==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------------(o)--'  \n");
    printf("````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");

}               
void Auto_diez() {
    printf("                                                                   _________________________   \n");
    printf("                              /\\      _____          _____       |   |     |     |    | |  \\  \n");
    printf("               ,-----,       /  \\____/__|__\\_    ___/__|__\\___   |___|_____|_____|____|_|___\\ \n");
    printf("            ,--'---:---`--, /  |  _     |     `| |      |      `| |                    | |    \\\n");
    printf("           ==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------------(o)--'  \n");
    printf("````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");

}   		
void Auto_once() {
    printf("                                                                     _________________________   \n");
    printf("                                /\\      _____          _____       |   |     |     |    | |  \\  \n");
    printf("                 ,-----,       /  \\____/__|__\\_    ___/__|__\\___   |___|_____|_____|____|_|___\\ \n");
    printf("              ,--'---:---`--, /  |  _     |     `| |      |      `| |                    | |    \\\n");
    printf("             ==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------------(o)--'  \n");
    printf("````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");

}	
void Auto_doce() {
    printf("                                                                       _________________________   \n");
    printf("                                  /\\      _____          _____       |   |     |     |    | |  \\  \n");
    printf("                   ,-----,       /  \\____/__|__\\_    ___/__|__\\___   |___|_____|_____|____|_|___\\ \n");
    printf("                ,--'---:---`--, /  |  _     |     `| |      |      `| |                    | |    \\\n");
    printf("               ==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------------(o)--'  \n");
    printf("````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");

}     
void Auto_trece() {
    printf("                                                                         _________________________   \n");
    printf("                                    /\\      _____          _____       |   |     |     |    | |  \\  \n");
    printf("                     ,-----,       /  \\____/__|__\\_    ___/__|__\\___   |___|_____|_____|____|_|___\\ \n");
    printf("                  ,--'---:---`--, /  |  _     |     `| |      |      `| |                    | |    \\\n");
    printf("                 ==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------------(o)--'  \n");
    printf("````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");

}       
void Auto_catorce() {
    printf("                                                                           _________________________   \n");
    printf("                                      /\\      _____          _____       |   |     |     |    | |  \\  \n");
    printf("                       ,-----,       /  \\____/__|__\\_    ___/__|__\\___   |___|_____|_____|____|_|___\\ \n");
    printf("                    ,--'---:---`--, /  |  _     |     `| |      |      `| |                    | |    \\\n");
    printf("                   ==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------------(o)--'  \n");
    printf("````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");

}   
void Auto_quince() {
    printf("                                                                             _________________________   \n");
    printf("                                        /\\      _____          _____       |   |     |     |    | |  \\  \n");
    printf("                         ,-----,       /  \\____/__|__\\_    ___/__|__\\___   |___|_____|_____|____|_|___\\ \n");
    printf("                      ,--'---:---`--, /  |  _     |     `| |      |      `| |                    | |    \\\n");
    printf("                     ==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------------(o)--'  \n");
    printf("````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");

}
void Auto_diesciseis() {
    printf("                                                                               _________________________   \n");
    printf("                                          /\\      _____          _____       |   |     |     |    | |  \\  \n");
    printf("                           ,-----,       /  \\____/__|__\\_    ___/__|__\\___   |___|_____|_____|____|_|___\\ \n");
    printf("                        ,--'---:---`--, /  |  _     |     `| |      |      `| |                    | |    \\\n");
    printf("                       ==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------------(o)--'  \n");
    printf("````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");

}    

     


