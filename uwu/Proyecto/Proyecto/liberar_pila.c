/* Libera todos los nodos de la pila. */
void liberar_pila(PilaDeshacer *p)
{
    NodoPila *actual = p->tope;
    while (actual != NULL) {
        NodoPila *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    p->tope = NULL;
    p->total = 0;
}
