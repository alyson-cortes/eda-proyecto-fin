/* Limpia el buffer de stdin tras una lectura invalida. Avisa al usuario. */
void clean(void)
{
    int a;
    puts("Tipo de dato erroneo");
    while ((a = getchar()) != '\n' && a != EOF);
}
