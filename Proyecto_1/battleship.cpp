#include <iostream>
#include "battleship.h"
//abrir y leer archivos txt
ifstream archive_j1("barcos_j1.txt");
ifstream archive_j2("barcos_j2.txt");

//definicion variables enteros
int error = 0; //ver si hay errores
int impact_j1 = 0; //cuenta impactos del jugador 1
int impact_j2 = 0; //cuenta impactos del jugador 2
int sub_j1_impact = 0; //cuenta los impactos recibidos por el submarino del jugador 1
int cruise_j1_impact = 0; //cuenta los impactos recibidos por el crucero del jugador 1
int sub_j2_impact = 0; //cuenta los impactos recibidos por el submarino del jugador 2
int cruise_j2_impact = 0; //cuenta los impactos recibidos por el crucero del jugador 2

//Crear jugadores j1 y j2
Player j1;
Player j2;

//Crear tableros de tiro y oceano para ambos jugadores
Board board_ocean_j1(6);
Board board_fire_j1(6);
Board board_ocean_j2(6);
Board board_fire_j2(6);

bool game_over() { //verifica si alguien ya gano
    if(impact_j2 == 6 || impact_j1 == 6){ //si hay 6 impactos de alguno de los dos jugadores se acaba el juego
        if (impact_j2==6){ //gana el 2 si llega a 6
            cout<<"Se acabó el juego"<<endl;
            cout<<"Ganó el jugador 2"<<endl;
        }
        if (impact_j1==6){ //gana el 1 si llega a 6
            cout<<"Se acabó el juego"<<endl;
            cout<<"Ganó el jugador 1"<<endl;
        }
        return true;
    }
    else{ //si no hay 6 disparos de algun jugador el juego no acaba
        return false;
    }
}

int main(){ //funcion principal del juego (bucle)
    if (!game_over()){ //si no ha ganado alguien

        //leer archivos
        j1.read_j1(); 
        j2.read_j2();
        game_over(); //verificar que no haya ganado alguien
        while (!game_over() and error==0) { //si no ha ganado alguien y no hay errores
            j1.shot_j1(); //turno del jugador 1
            if (j1.last_shot_hit) { //si el ultimo tiro impacto vuelve a disparar el jugador 1
                continue;
            }
            while (!game_over()) {
                j2.shot_j2();  //turno del jugador 2
                if (j2.last_shot_hit) {
                    continue;
                }
                else{
                    break; //si el jugador 2 no impacta, vuelve el turno al jugador 1
                }
            }
        }
    }
    else{
        cout<<"Se acabó el juego"<<endl;
    } 
}

void Player::shot_j1(){
    //imprimir el jugador del turno con sus tableros de tiro y oceano
    cout<<"Jugador: "<<"Jugador 1"<<endl; 
    cout<<endl;
    cout<<"Tablero de tiro"<<endl;
    board_fire_j1.print();
    cout<<endl;
    cout<<"Tablero oceano "<<endl;
    board_ocean_j1.print();

    //solicitar el disparo 
    int column = 0;
    int row = 0;
    string shot_coord;
    cout<<endl;
    cout << "Turno del jugador 1. Ingrese la coordenada de disparo: ";
    cin >> shot_coord;
    row = shot_coord[0] - 'A' + 1; //obtener la columna de disparo en numero
    column = shot_coord[1] - '1' + 1; //obtener la fila de disparo en numero
    board_ocean_j2.fire_j1(row,column); //llamar a la funcion disparar con la fila y columna
}

void Player::shot_j2(){
    //mismo principio que shot_j1
    cout<<"Jugador: "<<"Jugador 2"<<endl;
    cout<<endl;
    cout<<"Tablero de tiro"<<endl;
    board_fire_j2.print();
    cout<<endl;
    cout<<"Tablero oceano "<<endl;
    board_ocean_j2.print();
    int column = 0;
    int row = 0;
    string shot_coord;
    cout<<endl;
    cout << "Turno del jugador 2. Ingrese la coordenada de disparo: ";
    cin >> shot_coord;
    row = shot_coord[0] - 'A' + 1;
    column = shot_coord[1] - '1' + 1;
    board_ocean_j1.fire_j2(row,column);
}

void Board::place_submarine(int row, int column) {
        cells[row][column].occupied = true; //marca la celda como ocupada
        cells[row][column].symbol = 'S'; //coloca una S en la posicion del submarino 
    }

void Board::place_cruise(int row, int column) {
        cells[row][column].occupied = true; //marca la celda como ocupada
        cells[row][column].symbol = 'C'; //coloca una C en la posicion del crucero 
    }

void Board::place_boat(int row, int column) {
        cells[row][column].occupied = true; //marca la celda como ocupada
        cells[row][column].symbol = 'L'; //coloca una L en la posicion de la lancha 
        
    }

void Board::print(){
        //definir casillas de formato del tablero
        cells[0][0].occupied = false;
        cells[0][0].symbol = 'x';
        cells[1][0].occupied = false;
        cells[1][0].symbol = 'A';
        cells[2][0].occupied = false;
        cells[2][0].symbol = 'B';
        cells[3][0].occupied = false;
        cells[3][0].symbol = 'C';
        cells[4][0].occupied = false;
        cells[4][0].symbol = 'D';
        cells[5][0].occupied = false;
        cells[5][0].symbol = 'E';
        cells[0][1].occupied = false;
        cells[0][1].symbol = '1';
        cells[0][2].occupied = false;
        cells[0][2].symbol = '2';
        cells[0][3].occupied = false;
        cells[0][3].symbol = '3';
        cells[0][4].occupied = false;
        cells[0][4].symbol = '4';
        cells[0][5].occupied = false;
        cells[0][5].symbol = '5';

        //mostrar el tablero
        for (int row = 0; row < size; row++) { //avanza filas hasta llegar al tamano del tablero
            for (int column = 0; column < size; column++) { //avanza columnas hasta llegar al tamano del tablero
                cout << cells[row][column].symbol << "|"; //imprime la casilla con un separador |
            }
            cout << endl;
        }
    }

void Player::read_j1(){
    if (archive_j1.is_open()) { //mientras el txt del j1 este abierto
        string ignore_1;
        getline(archive_j1, ignore_1); //ignorar la linea del "Nombre de jugador:"

        string player_1_name; 
        getline(archive_j1, player_1_name); //guardar el nombre el jugador

        string ignore_2;
        getline(archive_j1, ignore_2); //ignorar la linea del "Coordenadas submarino"

        string submarine_coordinates_j1;
        getline(archive_j1, submarine_coordinates_j1); //guardar coordenadas submarino

        string ignore_3;
        getline(archive_j1, ignore_3); //ignorar la linea del "Coordenadas crucero"

        string cruise_coordinates_j1;
        getline(archive_j1, cruise_coordinates_j1); //guardar coordenadas crucero

        string ignore_4;
        getline(archive_j1, ignore_4); //ignorar la linea del "Coordenadas lancha"

        string boat_coordinates_j1;
        getline(archive_j1, boat_coordinates_j1); //guardar coordenadas lancha

        vector<pair<int, int>> numeric_coordinates_submarine; //vector de pares enteros
        string coord_submarine_j1; //string que almacena las coordenadas temporalmente
        stringstream ss_submarine(submarine_coordinates_j1);
        int large_submarine_j1 = 0; //largo submarino en lectura para detectar errores en el txt
        int out_submarine_j1 = 0; //ver si el submarino se sale del tablero
        while (getline(ss_submarine, coord_submarine_j1, ',')) { //obtener las coordenadas que se separan con la coma
            int letter = coord_submarine_j1[0] - 'A' + 1; //convertir la fila a numero
            int number = stoi(coord_submarine_j1.substr(1)); //guardar el numero de columna
            if (number > 5 || letter > 5){ //si el txt dice que la columna o fila son mayores a 5 el barco no esta definido en el tablero
                cout<<"Error: el submarino del jugador 1 se sale del tablero"<<endl;
                error++; //cierra el while de los turnos y acaba el juego
                out_submarine_j1++;
            }
            else{
                board_ocean_j1.place_submarine(letter,number);//colocar barco
                large_submarine_j1++;
                if (large_submarine_j1 > 3){ //si tiene mas de 3 casillas es mas largo de lo que deberia
                    cout<<"Error: el submarino del jugador 1 tiene mas de 3 coordenadas"<<endl;
                    error++;
                }  
            }
            
        }
        for (auto coord_submarine_j1 : numeric_coordinates_submarine) {
            if (large_submarine_j1 != 3 || out_submarine_j1 != 0){
                if (large_submarine_j1 < 3 and out_submarine_j1 == 0){ //si tiene menos de 3 casillas es mas corto
                    cout<<"Error: el submarino del jugador 1 tiene menos de 3 coordenadas"<<endl;
                    error++;
                }
                break;
            }
        }
        //misma idea anterior pero con el crucero
        vector<pair<int, int>> numeric_coordinates_cruise;
        string coord_cruise_j1;
        stringstream ss_cruise(cruise_coordinates_j1);
        int cruise_large_j1 = 0;
        int out_cruise_j1 = 0;
        while (getline(ss_cruise, coord_cruise_j1, ',')) {
            int letter = coord_cruise_j1[0] - 'A' + 1;
            int number = stoi(coord_cruise_j1.substr(1));
            if (number > 5 || letter > 5){
                cout<<"Error: el crucero del jugador 1 se sale del tablero"<<endl;
                error++;
                out_cruise_j1++;
            }
            else{
                board_ocean_j1.place_cruise(letter,number);
                cruise_large_j1++;
                if (cruise_large_j1 > 2){
                    cout<<"Error: el crucero del jugador 1 tiene mas de 2 coordenadas"<<endl;
                    error++;
                }
            }
        }
        for (auto coord_cruise_j1 : numeric_coordinates_cruise) {
            if (cruise_large_j1 != 2 || out_cruise_j1 != 0){
                if (cruise_large_j1 < 3 and out_cruise_j1 == 0){
                    cout<<"Error: el crucero del jugador 1 tiene menos de 2 coordenadas"<<endl;
                    error++;
                }
                break;
            }
        }


        vector<pair<int, int>> numeric_coordinates_boat;
        string coord_boat_j1;
        stringstream ss_boat(boat_coordinates_j1);
        int large_boat_j1 = 0;
        int out_boat_j1 = 0;
        while (getline(ss_boat, coord_boat_j1, ',')) {
            int letter = coord_boat_j1[0] - 'A' + 1;
            int number = stoi(coord_boat_j1.substr(1));
            if (number > 5 || letter > 5){
                cout<<"Error: la lancha del jugador 1 se sale del tablero"<<endl;
                error++;
                out_boat_j1++;
            }
            else{
                board_ocean_j1.place_boat(letter,number);
                large_boat_j1++;
                if (large_boat_j1 > 1){
                   cout<<"Error: la lancha del jugador 1 tiene mas de 1 coordenada"<<endl; 
                   error++;
                }
            }
        }
        for (auto coord_boat_j1 : numeric_coordinates_boat) {
            if (large_boat_j1 != 1 || out_boat_j1 !=0 ){
                break;
            }
        }
        archive_j1.close();//cerrar txt
    } 
    else {
        cout << "No se pudo abrir el archivo barcos_j1.txt" << endl;
    }
}

void Player::read_j2(){
    //misma idea de read_j1 pero con los barcos y el txt del jugador 2
    if (archive_j2.is_open()) {

        string ignore_1;
        getline(archive_j2, ignore_1); 

        string player_2_name;
        getline(archive_j2, player_2_name);

        string ignore_2;
        getline(archive_j2, ignore_2);

        string submarine_coordinates_j2;
        getline(archive_j2, submarine_coordinates_j2); 

        string ignore_3;
        getline(archive_j2, ignore_3);

        string cruise_coordinates_j2;
        getline(archive_j2, cruise_coordinates_j2); 

        string ignore_4;
        getline(archive_j2, ignore_4);

        string boat_coordinates_j2;
        getline(archive_j2, boat_coordinates_j2); 

        vector<pair<int, int>> numeric_coordinates_submarine;
        string coord_submarine_j2;
        stringstream ss_submarine(submarine_coordinates_j2);
        int large_submarine_j2 = 0;
        int out_submarine_j2 = 0;
        while (getline(ss_submarine, coord_submarine_j2, ',')) {
            int letter = coord_submarine_j2[0] - 'A' + 1;
            int number = stoi(coord_submarine_j2.substr(1));
            if (number > 5 || letter > 5){
                cout<<"Error: el submarino del jugador 2 se sale del tablero"<<endl;
                error++;
                out_submarine_j2++;
            }
            else{
                board_ocean_j2.place_submarine(letter,number);
                large_submarine_j2++;
                if (large_submarine_j2 > 3){
                    cout<<"Error: el submarino del jugador 2 tiene mas de 3 coordenadas"<<endl;
                    error++;
                }
            }
        }
        for (auto coord_submarine_j2 : numeric_coordinates_submarine) {
            if (large_submarine_j2 != 3 || out_submarine_j2 != 0){
                if (large_submarine_j2 < 3 and out_submarine_j2 == 0){
                    cout<<"Error: el submarino del jugador 2 tiene menos de 3 coordenadas"<<endl;
                    error++;
                }
                break;
            }
        }

        vector<pair<int, int>> numeric_coordinates_cruise;
        string coord_cruise_j2;
        stringstream ss_cruise(cruise_coordinates_j2);
        int out_cruise_j2 = 0;
        int cruise_large_j2 = 0;
        while (getline(ss_cruise, coord_cruise_j2, ',')) {
            int letter = coord_cruise_j2[0] - 'A' + 1;
            int number = stoi(coord_cruise_j2.substr(1));
            if (number > 5 || letter > 5){
                cout<<"Error: el crucero del jugador 2 se sale del tablero"<<endl;
                error++;
                out_cruise_j2++;
            }
            else{
                board_ocean_j2.place_cruise(letter,number);
                cruise_large_j2++;
                if (cruise_large_j2 > 2){
                cout<<"Error: el crucero del jugador 2 tiene mas de 2 coordenadas"<<endl;
                error++;
                }
            }
        }
        for (auto coord_cruise_j2 : numeric_coordinates_cruise) {
            if (cruise_large_j2 != 2 || out_cruise_j2 != 0){
                if (cruise_large_j2 < 3 and out_cruise_j2 == 0){
                    cout<<"Error: el crucero del jugador 2 tiene menos de 2 coordenadas"<<endl;
                    error++;
                }
                break;
            }
        }

        vector<pair<int, int>> numeric_coordinates_boat;
        string coord_boat_j2;
        stringstream ss_boat(boat_coordinates_j2);
        int large_boat_j2 = 0;
        int out_boat_j2 = 0;
        while (getline(ss_boat, coord_boat_j2, ',')) {
            int letter = coord_boat_j2[0] - 'A' + 1;
            int number = stoi(coord_boat_j2.substr(1));
            if (number > 5 || letter > 5){
                cout<<"Error: la lancha del jugador 2 se sale del tablero"<<endl;
                error++;
                out_boat_j2++;
            }
            else{
                board_ocean_j2.place_boat(letter,number);
                large_boat_j2++;
                if (large_boat_j2 > 1){
                   cout<<"Error: la lancha del jugador 2 tiene mas de 1 coordenada"<<endl; 
                   error++;
                }
            }
        }
        for (auto coord_boat_j2 : numeric_coordinates_boat) {
            if (large_boat_j2 != 1 || out_boat_j2 !=0 ){
                break;
            }
        } 
        archive_j2.close(); 
    } 
    else {
        cout << "No se pudo abrir el archivo barcos_j2.txt" << endl;
    }
}

void Board::fire_j1(int row, int column){
    if (cells[row][column].occupied){ //si la celda esta ocupada
        board_fire_j1.impact(row, column); //colocar I en la celda en el tablero de tiro
        if (cells[row][column].symbol == 'S'){ //si es un submarino
            sub_j2_impact++; //sumar impacto
            if (sub_j2_impact == 3){ //si se llegan a 3 impactos el submarino se hundio
                cout<<"Hundido!"<<endl;
            }
            else{
                cout<<"Impacto!"<<endl; //sino decir impacto solamente
            }
        }
        if (cells[row][column].symbol == 'C'){ //misma idea pero con el crucero
            cruise_j2_impact++;
            if (cruise_j2_impact == 2){
                cout<<"Hundido!"<<endl;
            }
            else{
                cout<<"Impacto!"<<endl;
            }
        }
        if (cells[row][column].symbol == 'L'){ //misma idea con la lancha
            cout<<"Hundido!"<<endl; //en este caso no hay impacto solo hundido porque solo tiene 1 casilla
        }
        cells[row][column].symbol = 'I'; //marcar en el oceano del jugador el impacto del rival
        impact_j1++; //sumarle a los impactos del jugador
        if(impact_j1 < 6){
            j1.last_shot_hit = true; //acerto el tiro entonces se vuelve true y se repite el turno
        }
        cout<<endl;
    }
    else {
        j1.last_shot_hit = false; //si no acierta el tiro es falso
        board_fire_j1.water(row, column); //marcar en el tablero de tiro A
        cout<<"Agua!"<<endl; //imprimir agua
        cells[row][column].symbol = 'A'; //marcar en el tablero de oceano del rival A
        cout<<endl;
    }
}

void Board::fire_j2(int row, int column){
    //misma idea que fire_j1 pero con el jugador 2
    if (cells[row][column].occupied){
        if (cells[row][column].symbol == 'S'){
            sub_j1_impact++;
            if (sub_j1_impact == 3){
                cout<<"Hundido!"<<endl;
            }
            else{
                cout<<"Impacto!"<<endl;
            }
        }
        if (cells[row][column].symbol == 'C'){
            cruise_j1_impact++;
            if (cruise_j1_impact == 2){
                cout<<"Hundido!"<<endl;
            }
            else{
                cout<<"Impacto!"<<endl;
            }
        }
        if (cells[row][column].symbol == 'L'){
            cout<<"Hundido!"<<endl;
        }
        board_fire_j2.impact(row, column);
        cells[row][column].symbol = 'I';
        impact_j2++;
        if(impact_j2 < 6){
            j2.last_shot_hit = true;
        }
        cout<<endl;
    }
    else {
        j2.last_shot_hit = false;
        board_fire_j2.water(row, column);
        cout<<"Agua!"<<endl;
        cells[row][column].symbol = 'A';
        cout<<endl;
    }
}

void Board::impact(int row, int column){
    cells[row][column].symbol = 'I'; //marca I en la casilla
}

void Board::water(int row, int column){
    cells[row][column].symbol = 'A'; //marca A en la casilla
}