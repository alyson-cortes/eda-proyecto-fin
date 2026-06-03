/* Reporte general del estado del sistema:
     - Paquetes en espera (cola)
     - Entregas registradas (historial)
     - Estado de capacidad de cada camion
*/
void reporteGeneral(Historial *h)
{
    int i;

    printf("\n############# REPORTE GENERAL DEL SISTEMA #############\n");

    /* --- Paquetes en espera --- */
    printf("\n>>> Paquetes en espera (cola)\n");
    if (HeadC == NULL) {
        puts("   (no hay paquetes en espera)");
    } else {
        nodoc *temp = HeadC;
        int total_cola = 0;
        float peso_total = 0.0f;
        printf("   %-5s %-30s %-10s\n", "ID", "Direccion", "Peso (kg)");
        while (temp != NULL) {
            printf("   %-5d %-30s %-10.2f\n", temp->id, temp->direccion, temp->peso);
            peso_total += temp->peso;
            total_cola++;
            temp = temp->next;
        }
        printf("   Total en cola: %d paquetes (%.2f kg)\n", total_cola, peso_total);
    }

    /* --- Entregas en historial --- */
    printf("\n>>> Entregas registradas (historial)\n");
    if (historial_vacio(h)) {
        puts("   (no hay entregas registradas)");
    } else {
        printf("   Total de entregas: %d\n", h->total_entregas);
        NodoHistorial *e = h->cabeza;
        i = 1;
        while (e != NULL) {
            printf("   %2d. Paquete %d -> %s (%.2f kg) en camion %d\n",
                   i, e->entrega.paquete.id, e->entrega.paquete.destino,
                   e->entrega.paquete.peso_kg, e->entrega.id_camion);
            e = e->siguiente;
            i++;
        }
    }

    /* --- Estado de los camiones --- */
    printf("\n>>> Estado de los camiones (lista circular)\n");
    if (listaCamiones == NULL) {
        puts("   (no hay camiones registrados)");
    } else {
        printf("   %-5s %-12s %-12s %-12s %s\n", "ID", "Capacidad", "Carga", "Disponible", "%Uso");
        NodoCamion *c = listaCamiones;
        do {
            float disp = c->dato.capacidad_kg - c->dato.carga_actual_kg;
            float pct  = (c->dato.capacidad_kg > 0)
                            ? (c->dato.carga_actual_kg / c->dato.capacidad_kg) * 100.0f
                            : 0.0f;
            printf("   %-5d %-12.2f %-12.2f %-12.2f %.1f%%\n",
                   c->dato.id, c->dato.capacidad_kg, c->dato.carga_actual_kg, disp, pct);
            c = c->siguiente;
        } while (c != listaCamiones);
        printf("   Camion en turno actual: ID %d\n", listaCamiones->dato.id);
    }

    /* --- Pila de deshacer --- */
    printf("\n>>> Pila de deshacer\n");
    printf("   Asignaciones disponibles para deshacer: %d\n", pila.total);

    printf("\n######################################################\n");
}
