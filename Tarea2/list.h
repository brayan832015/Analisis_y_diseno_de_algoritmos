#ifndef LIST_H
#define LIST_H

class Node{ //clase nodo con sus atributos y funciones
    friend class List;
    private:
        int value; //valor a manejar en las funciones
        Node*next; //puntero siguiente
    public:
        Node(int value); //crear nodo con un valor entero
};

class List{ //clase lista con sus atributos y funciones
    private:
        Node* start; //inicio
        Node* tail;  //cola
        int long_list;  //largo de la lista
    public:
        List(); //constructor
        ~List(); //destructor
        void show(); //mostrar
        int getlong(); //obtener largo de lista
        void insert_start(int value); //insertar al inicio de la lista
        void remove(int value); //eliminar un valor de la lista
        void insert_sorted(int value); //insertar ordenado en la lista
};

#endif