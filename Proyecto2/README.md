# Proyecto 2: Guest Who!! - Adivinador de Personajes con Árbol Binario

## Descripción General

Este proyecto implementa una versión del juego **Guest Who!!** en C++. Utiliza un **árbol binario de búsqueda** para hacer preguntas al usuario y adivinr el personaje de Mario Bros que tiene en mente.

## Objetivo del Proyecto

Desarrollar un programa que:
- Lee preguntas desde un archivo de o (`questions.txt`)
- Lee respuestas y personajes desde otro archivo (`index.txt`)
- Construye un árbol binario dinámicamente basado en los datos
- Realiza preguntas interactivas navegando el árbol
- Determina el personaje correcto basado en las respuestas
- Permite reiniciar el juego si la respuesta fue incorrecta



## 📁 Archivos del Proyecto

### Archivos de Código

#### `tree.h` (Header)

Define dos clases principales y funciones globales:

**Clase Node:**
class Node {
friend class BinaryTree;
private:
char data; // Dato del nodo (carácter identificador)
Node* left; // Hijo izquierdo
Node* right; // Hijo derecho
public:
Node(char value); // Constructor simple
Node(Node* leftBranch, char value, Node* rightBranch); // Constructor completo


char NodeValue();         // Retorna el valor
Node* leftSubTree();      // Retorna hijo izquierdo
Node* rightSubTree();     // Retorna hijo derecho
void newValue(char d);    // Cambia el valor
void leftBranch(Node* n); // Establece hijo izquierdo
void rightBranch(Node* n);// Establece hijo derecho
};



**Clase BinaryTree:**
class BinaryTree {
private:
Node* root; // Raíz del árbol
public:
BinaryTree(); // Constructor árbol vacío
BinaryTree(Node* r); // Constructor con raíz
void Proot(Node* r); // Establece raíz
Node* Oroot(); // Obtiene puntero a raíz
Node* treeRoot(); // Obtiene raíz (con validación)
bool isEmpty(); // Verifica si está vacío
Node* leftSon(); // Hijo izquierdo de raíz
Node* rightSon(); // Hijo derecho de raíz
Node* newTree(Node* ramaIzqda, char data, Node* ramaDrcha); // Crea nodo
void visite(Node* node); // Imprime valor
void preOrder(); // Recorrido preorden
void preOrder(Node* node); // Preorden desde nodo
};



**Variables Externas Globales:**
extern std::string p1, p2, p3, p4, p5, p6; // Preguntas
extern std::string r1, r2, r3, r4, r5, r6, r7; // Respuestas



**Funciones Globales:**
void reader_questions(); // Lee questions.txt
void reader_index(); // Lee index.txt
char findCharacter(BinaryTree& tree, std::map& questions); // Busca personaje



#### `tree.cpp` (Implementación)

**Constructores de Node:**
Node::Node(char value) {
this->data = value;
this->left = nullptr;
this->right = nullptr;
}

Node::Node(Node* leftBranch, char value, Node* rightBranch) {
this->data = value;
this->left = leftBranch;
this->right = rightBranch;
}



**Métodos de Node:**
- `NodeValue()` - Retorna el carácter del nodo
- `leftSubTree()` / `rightSubTree()` - Retornan hijos
- `newValue()`, `leftBranch()`, `rightBranch()` - Setters

**Métodos de BinaryTree:**
- `treeRoot()` - Lanza excepción si árbol vacío
- `isEmpty()` - Verifica si root es nullptr
- `preOrder(Node* node)` - Recursivo: visita nodo, izq, der
- `visite(Node* node)` - Imprime valor del nodo

**reader_questions():**
void reader_questions() {
std::ifstream file("questions.txt");
if (file.is_open()) {
std::getline(file, p1); // "¿Su personaje es bueno?"
std::getline(file, p2); // "¿Su personaje tiene sombrero?"
std::getline(file, p3); // "¿Su personaje tiene caparazón?"
std::getline(file, p4); // "¿Su personaje tiene pelo rojo?"
std::getline(file, p5); // "¿Su personaje tiene sombrero rojo?"
std::getline(file, p6); // "¿Su personaje viste de rosado?"
file.close();
}
}



**reader_index():**
- Lee archivo `index.txt`
- Ignora las primeras 6 líneas (que contienen preguntas)
- Extrae las 7 respuestas/personajes

**findCharacter():**
char findCharacter(BinaryTree& tree, map& questions) {
Node* node = tree.treeRoot();
while (node->leftSubTree() != nullptr && node->rightSubTree() != nullptr) {
cout << questions[node->NodeValue()] << " (si/no): ";
string answer;
cin >> answer;


    if (answer == "si" || answer == "Sí" || answer == "SI") {
        node = node->leftSubTree();  // Rama izquierda para "sí"
    } else if (answer == "no" || answer == "No" || answer == "NO") {
        node = node->rightSubTree();  // Rama derecha para "no"
    } else {
        cout << "Respuesta inválida..." << endl;
    }
}
return node->NodeValue();  // Retorna resultado en hoja
}



#### `main.cpp` (Programa Principal)

**Variables Globales:**
std::string p1, p2, p3, p4, p5, p6; // Preguntas (6)
std::string r1, r2, r3, r4, r5, r6, r7; // Respuestas (7)

std::map<char, std::string> questions; // Pregunta por carácter
std::map<char, std::string> characters; // Personaje por carácter

BinaryTree a1, a2, a3, a4, a; // Árbol principal y subárboles
Node *n1, *n2, *n3, *n4; // Nodos para construcción



**Flujo Principal:**
1. Lee archivos con `reader_questions()` y `reader_index()`
2. Construye el árbol binario con `newTree()`
3. Crea mapeos carácter → pregunta y carácter → personaje
4. Llama a `findCharacter()` para navegar el árbol
5. Muestra resultado y pregunta si es correcto
6. Reinicia si la respuesta fue incorrecta

### Archivos de Datos

#### `questions.txt`

¿Su personaje es bueno?
¿Su personaje tiene sombrero?
¿Su personaje tiene caparazón?
¿Su personaje tiene pelo rojo?
¿Su personaje tiene sombrero rojo?
¿Su personaje viste de rosado?



6 preguntas para discriminar entre 4 personajes (Mario, Luigi, Peach, Bowser)

#### `index.txt`

¿Su personaje es bueno?
¿Su personaje tiene sombrero?
¿Su personaje tiene caparazón?
¿Su personaje tiene sombrero rojo?
¿Su personaje viste de rosado?
¿Su personaje tiene pelo rojo?
No se encontró el personaje ← r1
Su personaje es Mario ← r2
Su personaje es Luigi ← r3
Su personaje es Peach ← r4
No se encontró el personaje ← r5
Su personaje es Bowser ← r6
No se encontró el personaje ← r7



### Ejemplo de Ejecución

Bienvenido! Intentaremos averiguar su personaje de Mario Bros...

¿Su personaje es bueno? (si/no): si
¿Su personaje tiene sombrero? (si/no): si
¿Su personaje tiene caparazón? (si/no): no

Su personaje es Mario

¿Es correcto? : si
Perfecto! Juego terminado.

## 🎮 Personajes Soportados

1. **Mario** - Bueno, tiene sombrero, sin caparazón
2. **Luigi** - Bueno, tiene sombrero, sin caparazón, sin pelo rojo
3. **Peach** - Buena, sin sombrero, sin caparazón, viste rosado
4. **Bowser** - Malo, sin sombrero, tiene caparazón

