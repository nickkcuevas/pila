#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/


/* Pruebas para una pila vacia */
void pruebas_pila_vacia() {
    printf("INICIO DE PRUEBAS CON PILA VACIA \n");

    /* Declaro las variables a utilizar*/
    pila_t* pila = pila_crear();

    /* Inicio de pruebas */
    print_test("crear pila vacia inicialmente vacia es true", pila_esta_vacia(pila) == true);
    print_test("obtener tope de pila devuelve NULL es true", pila_ver_tope(pila) == NULL);
    print_test("pila desapilar devuelve NULL es true", pila_desapilar(pila) == NULL);

    pila_destruir(pila);
    print_test("la pila fue destruida", true);
}


/* Pruebas para una pila que contiene elementos */
void pruebas_pila_con_elementos() {
    printf("INICIO DE PRUEBAS CON CON PILA AGREGANDO ELEMENTOS \n");

    /* Declaro las variables a utilizar*/
    pila_t* pila = pila_crear();
    size_t tam = 10;
    int** datos = malloc(tam * sizeof(int));
    for (int i=0; i < tam; i++){
        *datos[i] = i;
        pila_apilar(pila, &datos[i]);
    }

    /* Inicio de pruebas */
    print_test("obtener tope de pila devuelve NULL es true", *((int*)pila_ver_tope(pila)) == 9);
    
    pila_destruir(pila);
    print_test("la pila fue destruida", true);
}



void pruebas_pila_alumno() {
    pruebas_pila_vacia();
    pruebas_pila_con_elementos();
}
