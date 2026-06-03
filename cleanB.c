/* Limpia el buffer de stdin SIN imprimir mensaje (uso interno). */
void cleanB(void)
{
    int a;
    while ((a = getchar()) != '\n' && a != EOF);
}
