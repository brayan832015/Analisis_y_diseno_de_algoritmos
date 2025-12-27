#include "tree.h"

//variables declaradas para uso en cualquier sitio
std::string p1, p2, p3, p4, p5, p6; 
std::string r1, r2, r3, r4, r5, r6, r7;

//asociacion de clave char con valor string para las preguntas y los personajes
std::map<char, std::string> questions;
std::map<char, std::string> characters;
BinaryTree a1,a2,a3,a4,a; //crea el arbol a y los subarboles
Node *n1,*n2,*n3, *n4; //crea 4 nodos
int main() {
	cout<<"Bienvenido! Intentaremos averiguar su personaje de Mario Bros, por favor responda las siguientes preguntas:"<<endl; //mensaje bienvenida
	reader_questions(); //leer questions.txt para tener las preguntas
	reader_index(); //leer index.txt para tener las respuestas
	bool result=true; //cuando el usuario responde si o no en la pregunta de confirmacion del personaje, se mantiene el bucle mientras responda no o se cierra el bucle si responde si
	
	while (result==true){
    	n1 = a1.newTree(NULL,'A',NULL); //Su personaje es Mario es A
    	n2 = a2.newTree(NULL,'B',NULL); //Su personaje es Luigi es B
    	n3 = a3.newTree(n1,'C',n2); //Su personaje tiene sombrero rojo? es C
    	n1 = a1.newTree(NULL,'D',NULL); //Su personaje es Peach es D
    	n2 = a2.newTree(NULL,'E',NULL); //No se encontro personaje es E
    	n4 = a4.newTree(n1,'F',n2); //Su personaje viste de rosado? es F
    	n1 = a1.newTree(n3,'G',n4); //Su personaje tiene sombrero? es G
    	n2 = a2.newTree(NULL,'H',NULL); //Su personaje es Bowser es H
    	n3 = a3.newTree(NULL,'I',NULL); //No se encontro personaje es I
    	n4 = a4.newTree(n2,'J',n3); //Su personaje tiene pelo rojo? es J
    	n3 = a3.newTree(NULL,'K',NULL); //No se encontro personaje es K
    	n2 = a2.newTree(n4,'L',n3); //Su personaje tiene caparazon? es L
    	n3 = a3.newTree(n1,'M',n2); //Su personaje es bueno? es M
    	a.Proot(n3); //establece a n3 como raiz de a
    	
    	//Diccionario de personajes y sus oraciones
		//asignacion de respuestas
		map<char, string> characters;
    	characters['A'] = r2;
    	characters['B'] = r3;
   		characters['D'] = r4;
    	characters['H'] = r6;
   		characters['K'] = r1;
    	characters['K'] = r5;
    	characters['I'] = r7;
    	characters['E'] = r1;
		//asignacion de preguntas
    	map<char, string> questions;
    	questions['C'] = p5;
    	questions['F'] = p6;
    	questions['G'] = p2;
    	questions['J'] = p4;
    	questions['L'] = p3;
		questions['M'] = p1;

    	char characterFounded = findCharacter(a, questions); //llama a la funcion de encontrar personaje con el arbol a y mediante las preguntas

    	if (characterFounded != '\0') { // \0 es un carácter nulo, se utiliza para representar la ausencia de un personaje encontrado
        	cout << characters[characterFounded] << endl; //imprimir el personaje encontrado
        	string decision; //string de la desicion del usuario si es correcto o no el personaje
    		bool continuar=true; 
    		cout << "¿Es correcto? : "; //pregunta al usuario si el personaje encontrado es correcto
   			cin >> decision; //obtiene lo escrito por el usuario
   			
    		while(continuar==true){
    			if ((decision == "si" || decision == "Sí" || decision == "SI")) { //evita fallos de escritura
        			result = false; //termina el juego
        			continuar = false; //termina el ciclo while
					cout<<"Perfecto! Juego terminado."<<endl;
    			}
    			else if (decision == "no" || decision == "No" || decision == "NO") { //evita fallos de escritura
        			result = true; //vuelve a iniciar el juego
        			continuar = false;
					cout<<"Volviendo a empezar..."<<endl;
    			}
				else{ //si no es si o no se vuelve a comenzar el juego
					cout << "Respuesta invalida. Por favor, responda con 'si' o 'no'." << endl;
				}
				break; //corta el ciclo while
			}
    	}
	}
	
	return result;
}
