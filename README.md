# Proyecto Final EDAI — Gestor de Paqueteria y Ruteo

## Cómo compilar y ejecutar

```bash
gcc main.c -o programa
./programa
```

(En Windows con MinGW lo mismo, o `gcc main.c -o programa.exe`.)

Hay también un `Makefile` para usar simplemente:

```bash
make        # compila
make run    # compila y ejecuta
make clean  # borra el binario
```

El programa lee `paquetes.csv` desde el mismo directorio donde se ejecuta.

---

## Estructura de archivos

Todo el proyecto compila desde **un solo `gcc main.c`** porque `main.c` incluye
`menu.c` y éste a su vez incluye el resto de los `.c`. Las estructuras viven en
`estructuras.h` para que las usen todos los módulos.

```
estructuras.h            <- TODAS las structs (compartido entre los 3)
main.c                   <- variables globales + entrada del programa
menu.c                   <- menú principal + includes de todos los modulos
clean.c, cleanB.c        <- utilidades para limpiar el buffer

-- Modulo: registro y cola de paquetes (Hector)
VisualizarColaPac.c
regisPacMan.c
regisPacAr.c
menuRegisPac.c

-- Modulo: camiones (lista circular)
insertarCamion.c
creacion_camiones.c
rotarCamion.c

-- Modulo: asignacion
asigPacMan.c
asigPacAu.c
deshacer_asignacion.c
menuAsigPac.c

-- Modulo: historial y pila de deshacer (Aly)
inicializar_historial.c
registrar_entrega.c
imprimir_historial.c
liberar_historial.c
historial_vacio.c
inicializar_pila.c
apilar_asignacion.c
desapilar_asignacion.c
pila_vacia.c
liberar_pila.c

-- Reportes
reporteGeneral.c

-- Datos
paquetes.csv
```

---

## Estructuras de datos implementadas (cumple los 6 puntos del PDF)

1. **Arreglo maestro de paquetes** → `paquetes.csv` (almacenamiento inicial).
2. **Cola de paquetes en espera** → lista doblemente enlazada `nodoc` (HeadC/TailC).
3. **Pila de deshacer** → `PilaDeshacer` (lista simple LIFO).
4. **Historial de entregas** → `Historial` (lista simple FIFO).
5. **Lista circular de camiones** → `NodoCamion` (turno rota cíclicamente).
6. **Structs** → `Paquete`, `Camion`, `Entrega`, `Asignacion` en `estructuras.h`.

---

## Cómo se mapea cada requisito del PDF

| Requisito del PDF                                            | Implementado en                                                           |
| ------------------------------------------------------------ | ------------------------------------------------------------------------- |
| Cargar paquetes desde CSV                                    | `regisPacAr.c` + `paquetes.csv`                                           |
| Insertar nuevos paquetes en la cola principal                | `regisPacMan.c` (manual) y `regisPacAr.c` (desde archivo)                 |
| Asignar paquetes a camiones (turno de entrega)               | `asigPacMan.c`, `asigPacAu.c`                                             |
| Registrar entregas exitosas en lista simple                  | `registrar_entrega.c`, `imprimir_historial.c`                             |
| Pila para deshacer última asignación                         | `apilar_asignacion.c`, `desapilar_asignacion.c`, `deshacer_asignacion.c`  |
| Reportes del estado del sistema                              | `reporteGeneral.c`                                                        |
| Rotar el turno de camiones manualmente                       | `rotarCamion.c` (opción 5 del menú principal)                             |
| Manejo de errores (memoria, archivo, formato)                | Validaciones de `malloc`, `fopen`, `scanf` en cada función                |

---

## Cómo funciona el flujo de asignación

1. Se asigna un paquete → sale de la cola, se carga al camión, se empuja a la
   **pila** y se registra en el **historial**.
2. Si se hace "deshacer" → se desapila la última asignación, se descarga el
   camión, se devuelve el paquete a la cola y se borra la última entrada del
   historial.
3. La asignación automática (`asigPacAu`) rota por la lista circular para
   encontrar un camión que soporte el paquete.

---

## División del trabajo en el equipo (para GitHub)

Como cada `.c` es un archivo independiente, cada miembro del equipo edita
**solo sus archivos** y no hay conflictos al hacer merge:

- **Andrés** (cola de paquetes): `VisualizarColaPac.c`, `regisPacMan.c`,
  `regisPacAr.c`, `menuRegisPac.c`, `clean.c`, `cleanB.c`.
- **Victoria** (camiones): `insertarCamion.c`, `creacion_camiones.c`,
  `rotarCamion.c`.
- **Aly** (historial y pila): los 10 archivos individuales de historial/pila
  más `deshacer_asignacion.c`.
- **Compartidos (los tres revisan)**: `estructuras.h`, `main.c`, `menu.c`,
  `asigPacMan.c`, `asigPacAu.c`, `menuAsigPac.c`, `reporteGeneral.c`.

El archivo más delicado es `estructuras.h`: si alguien cambia una struct, todos
deben `git pull` antes de seguir trabajando.
