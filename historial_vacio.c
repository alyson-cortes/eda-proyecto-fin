/* Indica si el historial esta vacio (1 = vacio, 0 = tiene elementos). */
int historial_vacio(Historial *h)
{
    return (h->cabeza == NULL);
}
