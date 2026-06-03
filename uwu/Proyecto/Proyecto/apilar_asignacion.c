/* Apila una asignacion en el tope de la pila.
   Recibe el paquete y el id del camion como parametros separados
   para que el llamador no tenga que construir la struct.         */
int apilar_asignacion(PilaDeshacer *p, Paquete paquete, int id_camion)
{
    NodoPila *nuevo = (NodoPila *)malloc(sizeof(NodoPila));
    if (nuevo == NULL) {
        puts("ERROR 1. Error en memoria dinamica");
        return 0;
    }

    nuevo->asignacion.paquete = paquete;
    nuevo->asignacion.id_camion = id_camion;
    nuevo->siguiente = p->tope;
    p->tope = nuevo;
    p->total++;
    return 1;
}
