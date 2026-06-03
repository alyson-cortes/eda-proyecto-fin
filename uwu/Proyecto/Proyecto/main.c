/* ============================================================
   main.c
   Punto de entrada del programa. Aqui se declaran las variables
   globales y se incluye el menu.
   ============================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"

/* ---------- Variables globales ---------- */
int contPac = 1;      /* contador de paquetes registrados (id) */
int contAr  = 0;      /* paquetes ya leidos del CSV            */

/* Cola de paquetes en espera */
nodoc *HeadC = NULL;
nodoc *TailC = NULL;

/* Lista circular de camiones (apunta siempre al camion en turno) */
NodoCamion *listaCamiones = NULL;

/* Historial (lista simple) y pila de deshacer */
Historial   historial;
PilaDeshacer pila;

/* ---------- Se incluyen aqui todas las funciones ----------
   IMPORTANTE: menu.c hace los includes del resto en el orden correcto */
#include "menu.c"

int main(void)
{
    /* Inicializamos las estructuras dinamicas vacias */
    inicializar_historial(&historial);
    inicializar_pila(&pila);

    /* Damos de alta 5 camiones automaticos */
    creacion_camiones();

    /* Lanzamos el menu principal */
    menu();

    /* Limpieza de memoria al salir */
    liberar_historial(&historial);
    liberar_pila(&pila);

    return 0;
}
