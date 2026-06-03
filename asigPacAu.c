/* Asignacion automatica: recorre la cola de paquetes y, para cada
   uno, intenta acomodarlo en algun camion. Si no cabe en el camion
   en turno, rota al siguiente. Si ya probamos los 5 camiones y no
   cabe en ninguno, lo dejamos en la cola y avisamos al usuario.   */
void asigPacAu(void)
{
    if (HeadC == NULL) {
        puts("No hay paquetes en la cola.");
        return;
    }
    if (listaCamiones == NULL) {
        puts("No hay camiones en el sistema.");
        return;
    }

    int asignados = 0;
    int rechazados = 0;

    /* Iteramos mientras haya paquetes y al menos un camion sirva */
    while (HeadC != NULL) {

        NodoCamion *inicio = listaCamiones;
        int cabe = 0;

        /* Rotamos hasta encontrar un camion que soporte el paquete (o dar la vuelta) */
        do {
            if (listaCamiones->dato.carga_actual_kg + HeadC->peso
                    <= listaCamiones->dato.capacidad_kg) {
                cabe = 1;
                break;
            }
            listaCamiones = listaCamiones->siguiente;
        } while (listaCamiones != inicio);

        if (!cabe) {
            printf("El paquete %d (%.2f kg) no cabe en ningun camion. Se queda en la cola.\n",
                   HeadC->id, HeadC->peso);
            rechazados++;
            break;  /* No insistimos: si no cabe en ninguno, los siguientes tampoco van a rotar */
        }

        /* Sacar de la cola */
        nodoc *quitado = HeadC;
        HeadC = HeadC->next;
        if (HeadC == NULL) TailC = NULL;
        else               HeadC->prev = NULL;

        /* Empaquetar info */
        Paquete p;
        p.id = quitado->id;
        p.peso_kg = quitado->peso;
        strncpy(p.destino, quitado->direccion, sizeof(p.destino) - 1);
        p.destino[sizeof(p.destino) - 1] = '\0';

        /* Cargar camion, apilar y registrar entrega */
        listaCamiones->dato.carga_actual_kg += quitado->peso;
        apilar_asignacion(&pila, p, listaCamiones->dato.id);
        registrar_entrega(&historial, p, listaCamiones->dato.id);

        printf("Paquete %d asignado al camion %d.\n", p.id, listaCamiones->dato.id);
        free(quitado);
        asignados++;
    }

    printf("\nAsignacion automatica finalizada. Asignados: %d, sin asignar: %d\n",
           asignados, rechazados);
}
