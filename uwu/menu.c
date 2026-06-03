/* ============================================================
   menu.c
   Centraliza los includes y define el menu principal.
   El orden de los includes importa: primero los basicos y los que
   otras funciones llaman, despues los que dependen de ellos.
   ============================================================ */

/* --- Utilidades para limpiar el buffer de stdin --- */
#include "clean.c"
#include "cleanB.c"

/* --- Historial y pila (modulo de Aly) --- */
#include "historial_vacio.c"
#include "pila_vacia.c"
#include "inicializar_historial.c"
#include "inicializar_pila.c"
#include "registrar_entrega.c"
#include "apilar_asignacion.c"
#include "desapilar_asignacion.c"
#include "imprimir_historial.c"
#include "liberar_historial.c"
#include "liberar_pila.c"

/* --- Camiones (lista circular) --- */
#include "insertarCamion.c"
#include "creacion_camiones.c"
#include "rotarCamion.c"

/* --- Cola de paquetes (modulo de Hector) --- */
#include "VisualizarColaPac.c"
#include "regisPacAr.c"
#include "regisPacMan.c"
#include "menuRegisPac.c"

/* --- Asignacion de paquetes a camiones ---
   Nota: deshacer_asignacion va PRIMERO porque asigPacMan lo llama. */
#include "deshacer_asignacion.c"
#include "asigPacMan.c"
#include "asigPacAu.c"
#include "menuAsigPac.c"

/* --- Reportes --- */
#include "reporteGeneral.c"


/* ---------- Menu principal ---------- */
void menu(void)
{
    int op = 0;

    do {
        printf("\n##### Bienvenido al servicio de paqueteria #####\n");
        printf("Opcion 1: Registrar paquetes\n");
        printf("Opcion 2: Asignar paquetes a camiones\n");
        printf("Opcion 3: Imprimir historial de entregas\n");
        printf("Opcion 4: Reporte general del sistema\n");
        printf("Opcion 5: Rotar manualmente el turno de camiones\n");
        printf("Opcion 6: Salir del programa\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &op) == 1) {
            switch (op) {
                case 1: menuRegisPac();                  break;
                case 2: menuAsigPac();                   break;
                case 3: imprimir_historial(&historial);  break;
                case 4: reporteGeneral(&historial);      break;
                case 5: rotarCamion();                   break;
                case 6: puts("Usted ha salido del programa con exito"); break;
                default: puts("Inserte un digito valido");
            }
        } else {
            clean();
        }
    } while (op != 6);
}
