/* Deshace la ultima asignacion:
     1. Saca la asignacion del tope de la pila.
     2. Refunde la carga del camion correspondiente.
     3. Devuelve el paquete a la cola de espera.
     4. Quita la ultima entrada del historial (que correspondia a esa asignacion).
*/
void deshacer_asignacion(void)
{
    Asignacion deshecha;

    if (!desapilar_asignacion(&pila, &deshecha)) {
        puts("No hay asignaciones que deshacer.");
        return;
    }

    /* 1. Buscar el camion correspondiente en la lista circular y restarle la carga */
    if (listaCamiones != NULL) {
        NodoCamion *temp = listaCamiones;
        do {
            if (temp->dato.id == deshecha.id_camion) {
                temp->dato.carga_actual_kg -= deshecha.paquete.peso_kg;
                if (temp->dato.carga_actual_kg < 0) temp->dato.carga_actual_kg = 0;
                break;
            }
            temp = temp->siguiente;
        } while (temp != listaCamiones);
    }

    /* 2. Devolver el paquete a la cola (al final) */
    nodoc *restaurado = (nodoc *)malloc(sizeof(nodoc));
    if (restaurado != NULL) {
        restaurado->id = deshecha.paquete.id;
        restaurado->peso = deshecha.paquete.peso_kg;
        strncpy(restaurado->direccion, deshecha.paquete.destino, sizeof(restaurado->direccion) - 1);
        restaurado->direccion[sizeof(restaurado->direccion) - 1] = '\0';
        restaurado->next = NULL;

        if (HeadC == NULL && TailC == NULL) {
            restaurado->prev = NULL;
            HeadC = restaurado;
            TailC = restaurado;
        } else {
            restaurado->prev = TailC;
            TailC->next = restaurado;
            TailC = restaurado;
        }
    }

    /* 3. Quitar la ultima entrada del historial (la mas reciente) */
    if (historial.cabeza != NULL) {
        if (historial.cabeza->siguiente == NULL) {
            free(historial.cabeza);
            historial.cabeza = NULL;
        } else {
            NodoHistorial *act = historial.cabeza;
            while (act->siguiente->siguiente != NULL) act = act->siguiente;
            free(act->siguiente);
            act->siguiente = NULL;
        }
        historial.total_entregas--;
    }

    printf("Deshecha la asignacion: paquete %d (%s) del camion %d.\n",
           deshecha.paquete.id, deshecha.paquete.destino, deshecha.id_camion);
    printf("Asignaciones restantes en la pila: %d\n", pila.total);
}
