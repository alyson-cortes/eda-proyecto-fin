/* Imprime en pantalla todas las entregas registradas. */
void imprimir_historial(Historial *h)
{
    if (historial_vacio(h)) {
        puts("\nEl historial de entregas esta vacio.\n");
        return;
    }

    printf("\n========== HISTORIAL DE ENTREGAS (%d) ==========\n", h->total_entregas);

    NodoHistorial *actual = h->cabeza;
    int i = 1;
    while (actual != NULL) {
        printf("[Entrega #%d]\n", i);
        printf("  ID Paquete: %d\n", actual->entrega.paquete.id);
        printf("  Destino   : %s\n", actual->entrega.paquete.destino);
        printf("  Peso      : %.2f kg\n", actual->entrega.paquete.peso_kg);
        printf("  Camion ID : %d\n\n", actual->entrega.id_camion);
        actual = actual->siguiente;
        i++;
    }
    puts("================================================\n");
}
