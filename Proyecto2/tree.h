#ifndef TREE_H
#define TREE_H
#include <string>
#include <fstream>
#include <map>
#include <iostream>
using namespace std;

//extern se utiliza para indicar que las variables se declararan e inicializaran en otro archivo fuente, y se utilizaran en el archivo actual
extern std::string p1, p2, p3, p4, p5, p6; //preguntas
extern std::string r1, r2, r3, r4, r5, r6, r7; //respuestas

class Node {
    friend class BinaryTree;
private:
    char data; //dato del nodo
    Node* left; // puntero al nodo hijo izquierdo
    Node* right; // puntero al nodo hijo derecho 
public:
    Node(char value); //iniciar nodo con valor
    Node(Node* leftBranch, char value, Node* rightBranch); //iniciar nodo con valor e hijos izq y der

    char NodeValue(); //retorna el valor del nodo
    Node* leftSubTree(); //retorna sub-arbol izq
    Node* rightSubTree(); //retorna sub-arbol der
    void newValue(char d); //cambia el valor del nodo
    void leftBranch(Node* n); //define la rama izq del nodo
    void rightBranch(Node* n); //define la rama derecha del nodo
};

class BinaryTree {
private:
    Node* root; // puntero a la raiz
public:
    BinaryTree(); //contructor del arbol con raiz null
    BinaryTree(Node* r); //constructor del arbol con raiz r
    void Proot(Node* r); //hace raiz a r
    Node* Oroot(); //devuelve un puntero al nodo raiz del árbol binario
    Node* treeRoot(); //puntero a la raiz del arbol, si esta vacio indica "arbol vacio"
    bool isEmpty(); //comprueba si el arbol binario esta vacio o no
    Node* leftSon(); //devuelve un puntero al hijo izquierdo de la raiz del arbol binario
    Node* rightSon(); //devuelve un puntero al hijo derecho de la raiz del arbol binario
    Node* newTree(Node* ramaIzqda, char data, Node* ramaDrcha); //crea un nuevo nodo para un arbol binario
    void visite(Node* node); //imprime el valor del nodo
    void preOrder(); //recorre el arbol en preorden
    void preOrder(Node* node); //recorre el arbol en preorden desde un nodo especificado
};

void reader_questions(); //lector de preguntas (questions.txt)
void reader_index(); //lector de respuestas (index.txt)
char findCharacter(BinaryTree& tree, std::map<char, std::string>& questions); //funci'on para encontrar el personaje
#endif
