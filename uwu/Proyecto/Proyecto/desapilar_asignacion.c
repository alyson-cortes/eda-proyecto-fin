/* Saca la asignacion del tope de la pila y la copia en *salida.
   Devuelve 1 si exito, 0 si la pila estaba vacia.                */
int desapilar_asignacion(PilaDeshacer *p, Asignacion *salida)
{
    if (pila_vacia(p)) {
        return 0;
    }

    NodoPila *temp = p->tope;
    *salida = temp->asignacion;
    p->tope = temp->siguiente;
    free(temp);
    p->total--;
    return 1;
}
