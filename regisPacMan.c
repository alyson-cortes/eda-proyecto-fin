/* Registra un paquete leyendo direccion y peso desde el teclado. */
int regisPacMan(void)
{
    nodoc *nuevo = (nodoc *)malloc(sizeof(nodoc));
    if (nuevo == NULL) {
        puts("ERROR 1. Error en memoria dinamica");
        return 1;
    }

    cleanB();  /* limpia el '\n' que dejo el scanf previo */
    puts("Direccion del destinatario del paquete: ");
    fgets(nuevo->direccion, 50, stdin);
    nuevo->direccion[strcspn(nuevo->direccion, "\n")] = '\0';

    printf("Ingresa el peso (kg): ");
    if (scanf(" %f", &nuevo->peso) == 1) {

        /* Enganchamos el paquete al final de la cola */
        if (HeadC == NULL && TailC == NULL) {
            nuevo->next = NULL;
            nuevo->prev = NULL;
            HeadC = nuevo;
            TailC = nuevo;
        } else {
            nuevo->prev = TailC;
            TailC->next = nuevo;
            nuevo->next = NULL;
            TailC = nuevo;
        }

        nuevo->id = contPac;
        contPac++;

        puts("Datos guardados correctamente");
        VisualizarColaPac();
        return 0;
    } else {
        free(nuevo);
        clean();
        return 1;
    }
}
