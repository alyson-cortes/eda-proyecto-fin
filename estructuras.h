/* ============================================================
   estructuras.h
   Definicion centralizada de TODAS las estructuras del proyecto.
   Este archivo es el "contrato comun" entre los tres modulos:
     - Registro/cola de paquetes  (Hector)
     - Camiones (lista circular)  (companero)
     - Historial y pila de deshacer (Aly)
   ============================================================ */
#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

/* ---------- 1. Cola de paquetes en espera (cola circular doble) ---------- */
typedef struct nodoc {
    int id;
    float peso;
    char direccion[50];
    struct nodoc *next;
    struct nodoc *prev;
} nodoc;

/* ---------- 2. Camion y lista circular de camiones ---------- */
typedef struct {
    int id;
    float capacidad_kg;
    float carga_actual_kg;
} Camion;

typedef struct NodoCamion {
    Camion dato;
    struct NodoCamion *siguiente;
} NodoCamion;

/* ---------- 3. Paquete "ligero" para historial y pila ----------
   Usamos esta forma sencilla cuando ya no necesitamos los punteros
   next/prev (porque el paquete ya salio de la cola).               */
typedef struct {
    int id;
    char destino[100];
    float peso_kg;
} Paquete;

/* ---------- 4. Historial (lista simple de entregas exitosas) ---------- */
typedef struct {
    Paquete paquete;
    int id_camion;
} Entrega;

typedef struct NodoHistorial {
    Entrega entrega;
    struct NodoHistorial *siguiente;
} NodoHistorial;

typedef struct {
    NodoHistorial *cabeza;
    int total_entregas;
} Historial;

/* ---------- 5. Pila de asignaciones para deshacer ---------- */
typedef struct {
    Paquete paquete;
    int id_camion;
} Asignacion;

typedef struct NodoPila {
    Asignacion asignacion;
    struct NodoPila *siguiente;
} NodoPila;

typedef struct {
    NodoPila *tope;
    int total;
} PilaDeshacer;

#endif
