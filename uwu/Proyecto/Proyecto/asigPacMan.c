/* Asignacion manual de paquetes al camion en turno.
   El usuario decide paquete por paquete si lo asigna o si deshace
   la ultima asignacion.                                            */
void asigPacMan(void)
{
    int op = 0;

    if (listaCamiones == NULL) {
        puts("No hay camiones registrados en el sistema.");
        return;
    }

    do {
        printf("\n\t==== Asignacion manual ====\n");
        printf("Camion en turno: ID %d | capacidad %.2f kg | carga actual %.2f kg\n",
               listaCamiones->dato.id,
               listaCamiones->dato.capacidad_kg,
               listaCamiones->dato.carga_actual_kg);

        if (HeadC != NULL) {
            printf("Siguiente paquete: ID %d -> %s (%.2f kg)\n",
                   HeadC->id, HeadC->direccion, HeadC->peso);
        } else {
            puts("La cola de paquetes esta vacia.");
        }

        printf("\nOpcion 1: Asignar el siguiente paquete al camion en turno\n");
        printf("Opcion 2: Deshacer ultima asignacion\n");
        printf("Opcion 3: Salir\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &op) != 1) { clean(); continue; }

        switch (op) {
            case 1: {
                if (HeadC == NULL) {
                    puts("No hay paquetes en la cola.");
                    break;
                }
                NodoCamion *cam = listaCamiones;
                if (cam->dato.carga_actual_kg + HeadC->peso > cam->dato.capacidad_kg) {
                    printf("Este camion no soporta el paquete (%.2f + %.2f > %.2f).\n",
                           cam->dato.carga_actual_kg, HeadC->peso, cam->dato.capacidad_kg);
                    puts("Use la opcion 5 del menu principal para rotar el turno y vuelva a intentar.");
                    break;
                }

                /* 1. Sacamos el paquete de la cola (head) */
                nodoc *quitado = HeadC;
                HeadC = HeadC->next;
                if (HeadC == NULL) TailC = NULL;
                else               HeadC->prev = NULL;

                /* 2. Construimos un Paquete con sus datos */
                Paquete p;
                p.id = quitado->id;
                p.peso_kg = quitado->peso;
                strncpy(p.destino, quitado->direccion, sizeof(p.destino) - 1);
                p.destino[sizeof(p.destino) - 1] = '\0';

                /* 3. Cargamos el camion */
                cam->dato.carga_actual_kg += quitado->peso;

                /* 4. Apilamos en la pila de deshacer */
                apilar_asignacion(&pila, p, cam->dato.id);

                /* 5. Registramos en el historial de entregas */
                registrar_entrega(&historial, p, cam->dato.id);

                /* 6. Liberamos el nodo de la cola */
                free(quitado);

                printf("Paquete %d asignado al camion %d.\n", p.id, cam->dato.id);
                break;
            }
            case 2: {
                deshacer_asignacion();
                break;
            }
            case 3:
                puts("Saliendo del menu de asignacion manual.");
                break;
            default:
                puts("Opcion invalida.");
        }
    } while (op != 3);
}
