/* Agrega al final del historial una entrega exitosa.
   Devuelve 1 si todo OK, 0 si fallo el malloc.       */
int registrar_entrega(Historial *h, Paquete paquete, int id_camion)
{
    NodoHistorial *nuevo = (NodoHistorial *)malloc(sizeof(NodoHistorial));
    if (nuevo == NULL) {
        puts("ERROR. Error en memoria dinamica");
        return 0;
    }

    nuevo->entrega.paquete = paquete;
    nuevo->entrega.id_camion = id_camion;
    nuevo->siguiente = NULL;

    if (h->cabeza == NULL) {
        h->cabeza = nuevo;
    } else {
        NodoHistorial *actual = h->cabeza;
        while (actual->siguiente != NULL) actual = actual->siguiente;
        actual->siguiente = nuevo;
    }
    h->total_entregas++;
    return 1;
}
