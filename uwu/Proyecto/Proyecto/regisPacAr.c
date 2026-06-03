/* Registra paquetes leyendolos desde el archivo paquetes.csv.
   Pregunta al usuario cuantos quiere descargar (1-5).            */
int regisPacAr(void)
{
    int i, option;
    FILE *archivo = fopen("paquetes.csv", "r");

    if (archivo == NULL) {
        puts("ERROR 2. No se ha encontrado el archivo paquetes.csv");
        return 1;
    }

    /* Saltamos las lineas ya leidas en cargas anteriores */
    for (i = 0; i < contAr; i++) {
        fscanf(archivo, "%*[^\n]\n");
    }

    puts("----- Cuantos elementos deseas descargar? -----");
    puts("Escoge un numero del uno al cinco");

    if (scanf("%d", &option) == 1) {
        if (option < 1 || option > 5) {
            puts("Intervalo no valido");
            fclose(archivo);
            return 1;
        }
        if (option + contAr > 5) {
            puts("No hay elementos suficientes en el archivo");
            fclose(archivo);
            return 1;
        }

        for (i = 0; i < option; i++) {
            nodoc *Nuevo = (nodoc *)malloc(sizeof(nodoc));
            if (Nuevo == NULL) {
                puts("ERROR 1. Error en memoria dinamica");
                fclose(archivo);
                return 1;
            }
            if (fscanf(archivo, "%f,%49[^\n]\n ", &Nuevo->peso, Nuevo->direccion) != 2) {
                puts("Formato invalido en CSV");
                free(Nuevo);
                fclose(archivo);
                return 1;
            }

            /* Enganchamos al final de la cola */
            if (HeadC == NULL && TailC == NULL) {
                Nuevo->next = NULL;
                Nuevo->prev = NULL;
                HeadC = Nuevo;
                TailC = Nuevo;
            } else {
                Nuevo->prev = TailC;
                TailC->next = Nuevo;
                Nuevo->next = NULL;
                TailC = Nuevo;
            }

            Nuevo->id = contPac;
            contAr++;
            contPac++;
        }

        puts("Datos guardados correctamente");
        VisualizarColaPac();
        fclose(archivo);
        return 0;
    } else {
        fclose(archivo);
        clean();
        return 1;
    }
}
