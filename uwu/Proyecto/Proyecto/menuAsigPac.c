/* Submenu de asignacion de paquetes. */
void menuAsigPac(void)
{
    int opcion = 0;
    do {
        printf("\n----- Menu de asignacion de paquetes -----\n");
        printf("Opcion 1: Asignar paquetes manualmente\n");
        printf("Opcion 2: Asignar paquetes automaticamente\n");
        printf("Opcion 3: Deshacer ultima asignacion\n");
        printf("Opcion 4: Salir del menu\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opcion) == 1) {
            switch (opcion) {
                case 1: asigPacMan();          break;
                case 2: asigPacAu();           break;
                case 3: deshacer_asignacion(); break;
                case 4: puts("Ha salido del menu de asignacion"); break;
                default: puts("Inserte un digito valido");
            }
        } else {
            clean();
        }
    } while (opcion != 4);
}
