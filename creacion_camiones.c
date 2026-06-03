/* Crea 5 camiones con capacidades 100, 200, 300, 400 y 500 kg
   y los inserta en la lista circular global. */
void creacion_camiones(void)
{
    int i;
    for (i = 0; i < 5; i++) {
        Camion transporte = { i + 1, (i + 1) * 100.0f, 0.0f };
        insertarCamion(&listaCamiones, transporte);
    }
    printf("Se crearon 5 camiones automaticamente.\n");
}
