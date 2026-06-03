/* Submenu de registro de paquetes (manual o desde archivo). */
void menuRegisPac(void)
{
    int opcion = 0;
    do {
        printf("\n----- Menu de registro de paquetes -----\n");
        printf("Opcion 1: Registrar paquetes desde un archivo\n");
        printf("Opcion 2: Agregar paquete manualmente\n");
        printf("Opcion 3: Salir del menu\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opcion) == 1) {
            switch (opcion) {
                case 1:
                    if (contAr < 5) {
                        regisPacAr();
                    } else {
                        puts("No hay mas articulos por insertar desde el archivo");
                    }
                    break;
                case 2:
                    regisPacMan();
                    break;
                case 3:
                    puts("Ha salido del menu de registro de paquetes");
                    break;
                default:
                    puts("Inserte un digito valido");
            }
        } else {
            clean();
        }
    } while (opcion != 3);
}
