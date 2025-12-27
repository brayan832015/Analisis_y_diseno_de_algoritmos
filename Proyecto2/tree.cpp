#include "tree.h"

Node::Node(char value) { //nodo sin hijos
    this->data = value;
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(Node* leftBranch, char value, Node* rightBranch) { //nodo con hijos
    this->data = value;
    this->left = leftBranch;
    this->right = rightBranch;
} 

char Node::NodeValue() {
    return data;
}

Node* Node::leftSubTree() {
    return left;
}

Node* Node::rightSubTree() {
    return right; 
}

void Node::newValue(char d) {
    this->data = d; //cambia el valor del nodo
}

void Node::leftBranch(Node* n) {
    this->left = n; //cambia valor de hijo izquierdo
}

void Node::rightBranch(Node* n) {
    this->right = n; //cambia valor de hijo derecho
}

BinaryTree::BinaryTree() {
    this->root = nullptr; //crea arbol vacio
}

BinaryTree::BinaryTree(Node* r) {
    this->root = r; //crea un arbol con raiz r
}

void BinaryTree::Proot(Node* r) {
    this->root = r; //establece r como raiz
}

Node* BinaryTree::Oroot() {
    return root; //retorna puntero a la raiz
}

Node* BinaryTree::treeRoot() {
    if (this->root) 
        return this->root; //retorna el valor de la raiz
    else
        throw " arbol vacio";
}

bool BinaryTree::isEmpty() {
    return this->root == nullptr; //si el arbol es vacio, retorna null
}

Node* BinaryTree::leftSon() {
    if(this->root)
        return this->root->leftSubTree(); //retorna hijo izquierdo de la raiz
    else
        throw " arbol vacio";
}

Node* BinaryTree::rightSon() {
    if(this->root)
        return this->root->rightSubTree(); //retorna hijo derecho de la raiz
    else
        throw " arbol vacio";
}

Node* BinaryTree::newTree(Node* ramaIzqda, char data, Node* ramaDrcha) {
    return new Node(ramaIzqda, data, ramaDrcha); ////crea un nuevo nodo para un arbol binario con hijos
}

void BinaryTree::visite(Node* node) {
    cout << node->NodeValue() << endl; //imprime valor del nodo
}

void BinaryTree::preOrder() { 
    preOrder(this->root); //preorden desde la raiz
}

void BinaryTree::preOrder(Node* node) { //preorden desde un nodo especifico
    if (node != NULL) {
        visite(node); //visita raiz->izq->der
        preOrder(node->leftSubTree());
        preOrder(node->rightSubTree());
    }
}

//////////Lectura de archivos////////////////

void reader_questions(){ //lee questions.txt y extrae las preguntas para formar el arbol
	std::ifstream file("questions.txt");
	if (file.is_open()) {
	    std::getline(file, p1); //¿Su personaje es bueno?
        std::getline(file, p2); //¿Su personaje tiene sombrero?
        std::getline(file, p3); //¿Su personaje tiene caparazón?
        std::getline(file, p4); //¿Su personaje tiene pelo rojo?
        std::getline(file, p5); //¿Su personaje tiene sombrero rojo?
        std::getline(file, p6); //¿Su personaje viste de rosado?
        file.close();
    } 
    else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }
}
void reader_index(){ //lee index.txt y extrae las respuestas para formar el arbol
	std::ifstream file("index.txt");
	if (file.is_open()) {
	    std::string ignore;
	    //ignora las preguntas, utiliza solo las respuestas.
	    std::getline(file, ignore); //ignora "su personaje es bueno"
	    std::getline(file, ignore); //ignora "su personaje tiene sombrero"
	    std::getline(file, ignore); //ignora "su personaje tiene caparazon"
	    std::getline(file, ignore); //ignora "su personaje tiene sombrero rojo"
	    std::getline(file, ignore); //ignora "su personaje viste de rosado"
	    std::getline(file, ignore); //ignora "su personaje tiene pelo rojo" 
	    std::getline(file, r1); // no se encontro a su personaje
        std::getline(file, r2); //su personaje es mario
        std::getline(file, r3); //su personaje es luigi
        std::getline(file, r4); //su personaje es peach
        std::getline(file, r5); //no se encontro a su personaje
        std::getline(file, r6); //su personaje es bowser
        std::getline(file, r7); //no se encontro a su personaje
        file.close();
    } 
    else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }
}
////////////////////////////////////////////////////////////////////


char findCharacter(BinaryTree& tree, map<char, string>& questions) {
    Node* node = tree.treeRoot(); //Se obtiene el puntero a la raíz del árbol binario
    
    while (node->leftSubTree() != nullptr && node->rightSubTree() != nullptr) { //mientras el nodo tenga hijos tanto a la izquierda como a la derecha
        cout << questions[node->NodeValue()] << " (si/no): "; //se muestra la pregunta correspondiente al valor del nodo actual
        string answer; //se define respuesta del usuario
        cin >> answer; //se obtiene la respuesta dada por el usuario
        if (answer == "si" || answer == "Sí" || answer == "SI") { //si la respuesta es "si", se avanza hacia el subárbol izquierdo
            node = node->leftSubTree();
        } 
        
        else if (answer == "no" || answer == "No" || answer == "NO") { //si la respuesta es "no", se avanza hacia el subárbol derecho
            node = node->rightSubTree();
        }
        
        else { //si la respuesta no es "si" ni "no", se muestra un mensaje de respuesta inválida
            cout << "Respuesta inválida. Por favor, responda con 'si' o 'no'." << endl;
        }    
    }
    
    
    return node->NodeValue(); //se devuelve el valor del nodo actual
}



///////////////////////////
