/* Libera todos los nodos del historial. */
void liberar_historial(Historial *h)
{
    NodoHistorial *actual = h->cabeza;
    while (actual != NULL) {
        NodoHistorial *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    h->cabeza = NULL;
    h->total_entregas = 0;
}
