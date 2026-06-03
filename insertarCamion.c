/* Inserta un camion al final de la lista circular de camiones. */
void insertarCamion(NodoCamion **cabeza, Camion nuevoCamion)
{
    NodoCamion *nuevoNodo = (NodoCamion *)malloc(sizeof(NodoCamion));
    if (nuevoNodo == NULL) {
        printf("Error 1. Error en memoria dinamica\n");
        return;
    }
    nuevoNodo->dato = nuevoCamion;

    if (*cabeza == NULL) {
        /* Primer nodo: apunta a si mismo */
        *cabeza = nuevoNodo;
        nuevoNodo->siguiente = *cabeza;
    } else {
        /* Recorre hasta el ultimo nodo (el que apunta a la cabeza) */
        NodoCamion *temp = *cabeza;
        while (temp->siguiente != *cabeza) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
        nuevoNodo->siguiente = *cabeza;
    }
}
