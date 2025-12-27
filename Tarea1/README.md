# Tarea 1: Implementación de Lista Enlazada con Baraja de Naipes

## Descripción General

Esta tarea implementa una **lista enlazada** en C++ con una aplicación específica: ordenar cartas de una baraja de póker utilizando un algoritmo de inserción ordenada.

## Objetivo

Implementar una estructura de datos de lista enlazada simple que sea capaz de:
- Insertar elementos de forma ordenada
- Mantener un orden específico basado en la precedencia de cartas
- Mostrar los elementos almacenados con sus nombres correspondientes
- Validar las cartas de una baraja estándar

## 📚 Conceptos Clave

- **Listas Enlazadas**: Estructura de datos dinámica basada en nodos
- **Inserción Ordenada**: Mantener elementos en orden sin necesidad de ordenamiento posterior
- **Punteros**: Gestión de memoria dinámica
- **Traducción Strings a Números**: Mapeo de valores usando un diccionario
- **Iteración**: Recorrido de la lista enlazada

## 📁 Archivos

### `deck.h` (Header)
Define la estructura de datos mediante dos clases:

**Clase Node:**
- `int value` - Valor numérico de la carta (1-52)
- `Node* next` - Puntero al siguiente nodo
- Constructor `Node(int val)` - Inicializa un nodo

**Clase List:**
- `Node* first` - Puntero al primer nodo de la lista
- Constructor `List()` - Inicializa lista vacía
- Destructor `~List()` - Libera memoria de todos los nodos
- `void insert_sorted(int val)` - Inserta un valor manteniendo orden
- `void display()` - Imprime todas las cartas de la lista

**Función Global:**
- `int dictionary(std::string card)` - Convierte nombre de carta a número

### `deck.cpp` (Implementación)

**Inserción Ordenada:**
- Si la lista está vacía o el valor es menor que el primer nodo, inserta al inicio
- Si no, recorre hasta encontrar la posición correcta
- Mantiene la lista siempre ordenada

**Función display():**
Recorre cada nodo y convierte el número a nombre de carta:
- Valores 1-13: Cartas de Picas (APickBlack hasta KPickBlack)
- Valores 14-26: Cartas de Tréboles (ACloverBlack hasta KCloverBlack)
- Valores 27-39: Cartas de Corazones (AHeartRed hasta KHeartRed)
- Valores 40-52: Cartas de Diamantes (ADiamondRed hasta KDiamondRed)

**Función dictionary():**
Mapea 52 cadenas de caracteres a números 1-52 según la precedencia:
APickBlack = 1 ACloverBlack = 14 AHeartRed = 27 ADiamondRed = 40
2PickBlack = 2 2CloverBlack = 15 2HeartRed = 28 2DiamondRed = 41
...
KPickBlack = 13 KCloverBlack = 26 KHeartRed = 39 KDiamondRed = 52

### `main.cpp` (Programa Principal)

**Lógica:**
1. Crea una instancia de `List` (baraja)
2. Inserta 44 cartas (11 de cada palo) en orden aleatorio
3. La lista se mantiene ordenada automáticamente
4. Imprime todas las cartas ordenadas
