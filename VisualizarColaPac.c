/* Imprime en pantalla todos los paquetes que estan en la cola de espera. */
void VisualizarColaPac(void)
{
    int i;
    nodoc *temp = HeadC;

    if (HeadC == NULL && TailC == NULL) {
        printf("No hay paquetes que visualizar, vuelva mas tarde\n");
        return;
    }

    for (i = 0; i < 50; i++) printf("_");
    puts("\n\t\tCola de paquetes");
    printf("%-30s %-11s %s\n", "Direccion", "Peso", "Id");

    while (temp != NULL) {
        printf("%-29s  %-10.2f  %d\n", temp->direccion, temp->peso, temp->id);
        temp = temp->next;
    }

    for (i = 0; i < 50; i++) printf("_");
    printf("\n");
}
