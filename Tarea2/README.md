# Tarea 2: Lista Enlazada Simple Completa

## Descripción General

Esta tarea implementa una **lista enlazada simple completa** en C++ con múltiples operaciones: inserción al inicio, inserción ordenada, eliminación y visualización. Es una extensión de la Tarea 1 que añade funcionalidades adicionales para una estructura de datos más versátil.

## Objetivo

Desarrollar una lista enlazada funcional que permita:
- Insertar elementos al inicio de la lista
- Insertar elementos de forma ordenada
- Eliminar elementos por valor
- Visualizar todos los elementos
- Mantener control del tamaño de la lista
- Gestionar punteros de inicio y fin (tail)

## 📁 Archivos

### `list.h` (Header)

Define dos clases: **Node** y **List**


### `list.cpp` (Implementación)

**Constructor**

**Destructor (Libera Memoria)**

**insert_start(int value) - Insertar al Inicio:**
- Crear nuevo nodo
- Si lista vacía: apunta start y tail al nuevo nodo
- Si no vacía: enlazar nuevo nodo al inicio y actualizar start
- Incrementar long_list

**insert_sorted(int value) - Insertar Ordenado:**
Mantiene la lista en orden ascendente:
1. Si lista vacía: insertar como primer elemento
2. Si valor menor que inicio: insertar al inicio
3. Recorrer hasta encontrar posición correcta
4. Actualizar tail si se inserta al final

**show() - Mostrar Lista:**
- Recorre desde start hasta nullptr
- Imprime cada valor separado por espacios
- Maneja caso de lista vacía

**remove(int value) - Eliminar por Valor:**
Tres casos principales:
1. **Eliminar del inicio**: si value == start
2. **Eliminar del final**: si value == tail
3. **Eliminar del medio**: recorrer y desenlazar

Actualiza tail si es necesario y decrementa long_list.

**getlong() - Obtener Tamaño:**
Retorna long_list (cantidad de elementos)