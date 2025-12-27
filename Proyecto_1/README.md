# Proyecto 1: Battleship - Juego de Batalla Naval

## Descripción General

Este proyecto implementa una **versión del juego Battleship (Batalla Naval)** en C++. Es un juego interactivo para dos jugadores donde el objetivo es hundir todos los barcos del oponente mediante un sistema de coordenadas.

## Objetivo del Proyecto

Desarrollar un programa funcional de Batalla Naval que:
- Lee la configuración de barcos desde archivos de o
- Permite a dos jugadores jugar alternativamente
- Mantiene tableros separados de océano y tiro
- Detecta impactos y hundimientos
- Gestiona turnos y condiciones de victoria
- Registra jugadas

## 📁 Archivos del Proyecto

### Archivos de Código

#### `battleship.h` (Header)

Define tres clases principales:

**Clase Player:**
class Player {
public:
void shot_j1(); // Turno jugador 1
void shot_j2(); // Turno jugador 2
bool last_shot_hit; // Si último tiro impactó
void read_j1(); // Leer archivo jugador 1
void read_j2(); // Leer archivo jugador 2
};



**Clase Cell:**
class Cell {
public:
bool occupied = false; // Si contiene barco
char symbol = 'X'; // Símbolo visual
};



**Clase Board:**
class Board {
public:
int size; // Tamaño 6x6
vector<vector<Cell>> cells; // Matriz de celdas


Board(int size);               // Constructor
void print();                  // Mostrar tablero
void place_submarine(...);     // Colocar submarino (3 casillas)
void place_cruise(...);        // Colocar crucero (2 casillas)
void place_boat(...);          // Colocar lancha (1 casilla)
void fire_j1(...);             // Disparo jugador 1
void fire_j2(...);             // Disparo jugador 2
void impact(...);              // Marcar impacto
void water(...);               // Marcar agua
};



#### `battleship.cpp` (Implementación)

**Variables Globales:**
- `error`: Bandera de errores
- `impact_j1`, `impact_j2`: Contador de impactos por jugador
- `sub_j1_impact`, `cruise_j1_impact`: Impactos específicos por barco
- `board_ocean_j1/j2`: Tablero privado (con barcos)
- `board_fire_j1/j2`: Tablero público (para disparos enemigos)

**Funciones Principales:**

**game_over():**
bool game_over() {
if(impact_j2 == 6 || impact_j1 == 6) {
if (impact_j2 == 6) {
// Gana jugador 1
} else {
// Gana jugador 2
}
return true;
}
return false;
}


- Verifica si algún jugador recibió 6 impactos
- Los 3 barcos suman 6 casillas totales (3+2+1)

**read_j1() / read_j2():**
- Abre archivos "barcos_j1.txt" y "barcos_j2.txt"
- Extrae nombre del jugador y coordenadas
- Valida que las coordenadas estén dentro del tablero (A-E, 1-5)
- Valida que los barcos tengan el tamaño correcto
- Coloca los barcos en el tablero de océano

**shot_j1() / shot_j2():**
- Muestra tablero de tiro y océano del jugador
- Solicita entrada en formato "Letra+Número" (ej: A2)
- Convierte letra a índice (A=1, B=2, ..., E=5)
- Convierte número a índice (1=1, 2=2, ..., 5=5)
- Llama a la función de disparo (fire_j1/fire_j2)

**place_submarine/cruise/boat():**
void Board::place_submarine(int row, int column) {
cells[row][column].occupied = true;
cells[row][column].symbol = 'S'; // Submarino
}

void Board::place_cruise(int row, int column) {
cells[row][column].occupied = true;
cells[row][column].symbol = 'C'; // Crucero
}

void Board::place_boat(int row, int column) {
cells[row][column].occupied = true;
cells[row][column].symbol = 'L'; // Lancha
}



**print():**
- Establece encabezados (A-E horizontal, 1-5 vertical)
- Imprime matriz con separadores "|"
- Muestra símbolos: X (vacío), S (submarino), C (crucero), L (lancha)
- Símbolos de impacto: O (agua), H (hit/impacto)

### Archivos de Configuración

#### `barcos_j1.txt`

Nombre de Jugador:
Jhon Doe
Coordenadas submarino
A1,B1,C1
Coordenadas crucero
C3,C2
Coordenadas lancha
C4

**Tableros Separados:**
- **Ocean Board**: Contiene posiciones reales de barcos
- **Fire Board**: Registra disparos enemigos

**Sistema de Símbolos:**
- `X` - Casilla vacía sin disparar
- `S` - Submarino
- `C` - Crucero
- `L` - Lancha
- `O` - Agua (disparo fallido)
- `H` - Hit (impacto)



## 🎯 Reglas del Juego

1. Cada jugador tiene 3 barcos:
   - Submarino: 3 casillas
   - Crucero: 2 casillas
   - Lancha: 1 casilla

2. Formato de disparo: **LETRA + NÚMERO** (ej: A2, E5)
   - Letras válidas: A, B, C, D, E
   - Números válidos: 1, 2, 3, 4, 5

3. Si impactas: turno extra
4. Si fallas: turno del oponente
5. Ganar: 6 impactos totales

