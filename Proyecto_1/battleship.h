#ifndef BATTLESHIP_H
#define BATTLESHIP_H
using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>

class Player {//clase jugador
    public:
        void shot_j1(); //turno del jugador 1
        void shot_j2(); //turno del jugador 2
        bool last_shot_hit = false; //inicializar que el ultimo tiro no impacto
        void read_j1(); //leer txt jugador 1
        void read_j2(); //leer txt jugador 2
};

class Cell { //clase celda
public:
    bool occupied = false; //inicializar que la celda esta vacia
    char symbol = 'X'; //simbolo de vacia es X
};

class Board { //clase tablero
    public:
        int size; //tamano tablero

        //crea una estructura de datos que puede almacenar una matriz de objetos 
        // cells es un vector de vectores que representa las celdas del tablero de juego
        vector<vector<Cell>> cells;

        //Constructor, inicializa el tamaño del tablero y crea una matriz de celdas
        Board(int size) : size(size), cells(size, vector<Cell>(size)) {}

        void print(); //imprimir tablero
        void place_submarine(int row, int column); //colocar submarino
        void place_cruise(int row, int column); //colocar crucero
        void place_boat(int row, int column); //colocar lancha
        void fire_j1(int row, int column); //disparar con el jugador 1
        void fire_j2(int row, int column); //disparar con el jugador 2
        void impact(int row, int column); //marca la casilla como impactada en el tablero de tiro
        void water(int row, int column); //marca la casilla como agua en el tablero de tiro
};

#endif