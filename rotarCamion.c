/* Rota manualmente el turno de camiones avanzando la cabeza
   a su siguiente nodo dentro de la lista circular. */
void rotarCamion(void)
{
    if (listaCamiones == NULL) {
        puts("No existen camiones registrados en el sistema.");
        return;
    }
    listaCamiones = listaCamiones->siguiente;
    printf("Turno rotado manualmente. Camion activo: ID %d  (capacidad %.2f kg, carga actual %.2f kg)\n",
           listaCamiones->dato.id,
           listaCamiones->dato.capacidad_kg,
           listaCamiones->dato.carga_actual_kg);
}
