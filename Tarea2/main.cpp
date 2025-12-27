#include "list.h"

int main(){ //funciones del programa al ejecutarse
    List list;
    //agregar ordenado 3 numeros:
    list.insert_sorted(3);
    list.insert_sorted(1);
    list.insert_sorted(2);
    list.show(); //mostrar la lista completa
}