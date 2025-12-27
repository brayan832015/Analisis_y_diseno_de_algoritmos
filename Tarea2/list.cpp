#include <iostream>
#include "list.h"

Node::Node(int value){ //definicion nodo
    this->value = value; 
    this->next = nullptr;
}

List::List(){//comenzar lista vacia
    this->start = nullptr; 
    this->long_list = 0;
    this->tail = nullptr;
}

List::~List(){ //eliminar lista (destructor)
    Node* current = this->start; //puntero actual en inicio de la lista
    while (current != nullptr){ //si la lista no esta vacia entra en el while
        Node* next = current->next; //mover puntero
        delete current; //eliminar valor del puntero
        current = next;
    }
}

void List::insert_start(int value){ //insertar al inicio
    Node* newNode = new Node(value); //definir nodo nuevo
    if (this->start == nullptr){ //entra si la lista esta vacia
        //apunta el inicio y la cola al nodo nuevo:
        this->start = newNode;
        this->tail = newNode;
    }
    else{
        newNode->next=this->start; //si la lista no esta vacia el nuevo nodo se enlaza con el inicio
        this->start = newNode; //colocar el inicio en el nuevo nodo
    }
    this->long_list++; //sumar a la lontitud de la lista
}

void List::show(){ //mostrar lista
    Node* current=this->start; //definir puntero actual
    while(current!=nullptr){ //si la lista no esta vacia entra
        std::cout<<current->value<<" "; //imprimir valor de actual y moverlo para correr toda la lista
        current=current->next;
    }
    if (this->start==nullptr){ //si la lista esta vacia se indica
        std::cout<<"La lista está vacía"<<std::endl;
    }
}

void List::insert_sorted(int value){ //inserta valor en orden
    Node* newNode = new Node(value); //definir nodo
    if (this->start == nullptr) { //entra si la lista esta vacia
        this->start = newNode; //apunta inicio y cola al nuevo nodo
        this->tail = newNode;
    }
    if(this->start->next!=nullptr){ //si el segundo valor no es null entra
        Node* current=this->start->next; //definir puntero actual y temporal
        Node* tmp=this->start;
        while (current->value < newNode->value){ //si el valor del puntero actual es menor al valor del nuevo nodo entra
            if (current->next==nullptr){ //si el actual es el ultimo de la lista entra
                current->next=newNode; //acomodar nuevo nodo
                this->tail=newNode;
            }
            else{
                current=current->next; //recorrer punteros y volver al while
                tmp=tmp->next;
            }
        }
        if(current->value > newNode->value){ //si actual es mayor al nuevo nodo
            if(tmp->value < newNode->value){ //si temporal es menor que nuevo nodo
                tmp->next=newNode; //acomodar nuevo nodo
                newNode->next=current;
            }
            else{
                newNode->next=tmp; //si temporal es mayor a nuevo nodo se acomoda el nuevo nodo
                this->start=newNode;
            }
        }
    }
    if(this->start->value > newNode->value){ //si el inicio es mayor al nuevo nodo
        newNode->next=this->start; //acomodar el nuevo nodo al inicio
        this->start=newNode;
    }
    if(long_list==1 && newNode->value > this->start->value){ //si hay un elemento en la lista y es menor que nuevo nodo
        this->start->next=newNode; //insertar nuevo nodo al final
        this->tail=newNode;
    }    
    long_list++; //sumar a largo de lista
}    


void List::remove(int value){ //eliminar valor
    Node* current=this->start; //definir puntero actual
    if (this->long_list==0){ //si la lista esta vacia se indica
        std::cout<<"La lista esta vacia nada para eliminar"<<std::endl;
    }
    else if(this->start->value==value){ //si el valor a eliminar es el primero
        Node* tmp=this->start; //definir puntero temporal
        this->start=this->start->next; //apuntar inicio al segundo valor
        tmp->next=nullptr; //enlazar a null el primer valor
        delete tmp; //eliminar el primer valor (tmp)
        this->long_list--; //quitarle al largo de lista
    }
    else {
        while (current->next!=nullptr){ //si la lista no es de un valor
            if(current->next==this->tail && current->next->value==value){ //si el valor a eliminar es el ultimo
                Node* tmp=this->tail; //definir temporal en la cola
                this->tail=current; //mover cola a valor anterior
                this->tail->next=nullptr; //enlazar ese valor a null
                delete tmp; //eliminar temporal
                this->long_list--; 
            }
            else if(current->next->value==value){ //si el valor a eliminar es el segundo
                Node* tmp = current->next; //definir temporal
                current->next=tmp->next; //enlazar valor inicio con el tercer valor
                delete tmp; //eliminar temporal
                this->long_list--;
            }
            else{
                current=current->next; //mover actual y volver al while
                if(current->next==nullptr){ //si actual siguiente es null el valor a eliminar no esta en la lista
                    std::cout << "El valor no se encuentra en la lista"<< std::endl;
                }
            }
        }
    }
}