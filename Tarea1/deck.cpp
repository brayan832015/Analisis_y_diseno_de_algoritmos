#include "deck.h"
#include <iostream>
using namespace std;

Node::Node(int val) {
    value = val;
    next = NULL;
}

List::List() {
    first = NULL;
}

List::~List() {
    Node* current = first;
    Node* next;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
}

void List::insert_sorted(int val) {
    Node* newNode = new Node(val);
    if (first == NULL || val < first->value) {
        newNode->next = first;
        first = newNode;
    }
    else {
        Node* current = first;
        while (current->next != NULL && current->next->value <= val) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}
//// List display changed to display the card accord to the number selected
void List::display() {
    Node* current = first;
    while (current != NULL) {
    	////////Picks///////////
    	// if the current value correspond to the number of card, display the card name
        if (current->value==1){
        	std::cout<< "APickBlack" << std::endl;
		}
		else if (current->value==2){
        	std::cout<< "2PickBlack" << std::endl;
		}
		else if (current->value==3){
        	std::cout<< "3PickBlack" << std::endl;
		}
		else if (current->value==4){
        	std::cout<< "4PickBlack" << std::endl;
		}
		else if (current->value==5){
        	std::cout<< "5PickBlack" << std::endl;
		}
		else if (current->value==6){
        	std::cout<< "6PickBlack" << std::endl;
		}
		else if (current->value==7){
        	std::cout<< "7PickBlack" << std::endl;
		}
		else if (current->value==8){
        	std::cout<< "8PickBlack" << std::endl;
		}
		else if (current->value==9){
        	std::cout<< "9PickBlack" << std::endl;
		}
		else if (current->value==10){
        	std::cout<< "10PickBlack" << std::endl;
		}
		else if (current->value==11){
        	std::cout<< "JPickBlack" << std::endl;
		}
		else if (current->value==12){
        	std::cout<< "QPickBlack" << std::endl;
		}
		else if (current->value==13){
        	std::cout<< "KPickBlack" << std::endl;
		}
		///////Clovers////////////
		else if (current->value==14){
        	std::cout<< "ACloverBlack" << std::endl;
		}
		else if (current->value==15){
        	std::cout<< "2CloverBlack" << std::endl;
		}
		else if (current->value==16){
        	std::cout<< "3CloverBlack" << std::endl;
		}
		else if (current->value==17){
        	std::cout<< "4CloverBlack" << std::endl;
		}
		else if (current->value==18){
        	std::cout<< "5CloverBlack" << std::endl;
		}
		else if (current->value==19){
        	std::cout<< "6CloverBlack" << std::endl;
		}
		else if (current->value==20){
        	std::cout<< "7CloverBlack" << std::endl;
		}
		else if (current->value==21){
        	std::cout<< "8CloverBlack" << std::endl;
		}
		else if (current->value==22){
        	std::cout<< "9CloverBlack" << std::endl;
		}
		else if (current->value==23){
        	std::cout<< "10CloverBlack" << std::endl;
		}
		else if (current->value==24){
        	std::cout<< "JCloverBlack" << std::endl;
		}
		else if (current->value==25){
        	std::cout<< "QCloverBlack" << std::endl;
		}
		else if (current->value==26){
        	std::cout<< "KCloverBlack" << std::endl;
		}
		///////Hearts////////////
		else if (current->value==27){
        	std::cout<< "AHeartRed" << std::endl;
		}
		else if (current->value==28){
        	std::cout<< "2HeartRed" << std::endl;
		}
		else if (current->value==29){
        	std::cout<< "3HeartRed" << std::endl;
		}
		else if (current->value==30){
        	std::cout<< "4HeartRed" << std::endl;
		}
		else if (current->value==31){
        	std::cout<< "5HeartRed" << std::endl;
		}
		else if (current->value==32){
        	std::cout<< "6HeartRed" << std::endl;
		}
		else if (current->value==33){
        	std::cout<< "7HeartRed" << std::endl;
		}
		else if (current->value==34){
        	std::cout<< "8HeartRed" << std::endl;
		}
		else if (current->value==35){
        	std::cout<< "9HeartRed" << std::endl;
		}
		else if (current->value==36){
        	std::cout<< "10HeartRed" << std::endl;
		}
		else if (current->value==37){
        	std::cout<< "JHeartRed" << std::endl;
		}
		else if (current->value==38){
        	std::cout<< "QHeartRed" << std::endl;
		}
		else if (current->value==39){
        	std::cout<< "KHeartRed" << std::endl;
		}
		///////Diamonds////////////
		else if (current->value==40){
        	std::cout<< "ADiamondRed" << std::endl;
		}
		else if (current->value==41){
        	std::cout<< "2DiamondRed" << std::endl;
		}
		else if (current->value==42){
        	std::cout<< "3DiamondRed" << std::endl;
		}
		else if (current->value==43){
        	std::cout<< "4DiamondRed" << std::endl;
		}
		else if (current->value==44){
        	std::cout<< "5DiamondRed" << std::endl;
		}
		else if (current->value==45){
        	std::cout<< "6DiamondRed" << std::endl;
		}
		else if (current->value==46){
        	std::cout<< "7DiamondRed" << std::endl;
		}
		else if (current->value==47){
        	std::cout<< "8DiamondRed" << std::endl;
		}
		else if (current->value==48){
        	std::cout<< "9DiamondRed" << std::endl;
		}
		else if (current->value==49){
        	std::cout<< "10DiamondRed" << std::endl;
		}
		else if (current->value==50){
        	std::cout<< "JDiamondRed" << std::endl;
		}
		else if (current->value==51){
        	std::cout<< "QDiamondRed" << std::endl;
		}
		else if (current->value==52){
        	std::cout<< "KDiamondRed" << std::endl;
		}
		else{
			std::cout<<"One of the selected card do not correspond on the poker deck"<< "-";
		}
        current = current->next;
    }
    std::cout << std::endl;
}
////////////////Dictionary for transformations/////////////////////
// This simply dictionary transform a card in number accordin to their precedence.
// Recives a string, create a int value, if the string correspond to any of cases determinated they will be transformed to a number
int dictionary(std::string card) {
    int card1 = 0;

    if (card == "APickBlack") {
        card1 = 1;
    }
    else if (card == "2PickBlack") {
        card1 = 2;
    }
    else if (card == "3PickBlack") {
        card1 = 3;
    }
    else if (card == "4PickBlack") {
        card1 = 4;
    }
    else if (card == "5PickBlack") {
        card1 = 5;
    }
    else if (card == "6PickBlack") {
        card1 = 6;
    }
    else if (card == "7PickBlack") {
        card1 = 7;
    }
    else if (card == "8PickBlack") {
        card1 = 8;
    }
    else if (card == "9PickBlack") {
        card1 = 9;
    }
    else if (card == "10PickBlack") {
        card1 = 10;
    }
    else if (card == "JPickBlack") {
        card1 = 11;
    }
    else if (card == "QPickBlack") {
        card1 = 12;
    }    
    else if (card == "KPickBlack") {
        card1 = 13;
    }
//////////////Clovers///////////////////////
    else if (card == "ACloverBlack") {
        card1 = 14;
    }
    else if (card == "2CloverBlack") {
        card1 = 15;
    }
    else if (card == "3CloverBlack") {
        card1 = 16;
    }
    else if (card == "4CloverBlack") {
        card1 = 17;
    }
    else if (card == "5CloverBlack") {
        card1 = 18;
    }
    else if (card == "6CloverBlack") {
        card1 = 19;
    }
    else if (card == "7CloverBlack") {
        card1 = 20;
    }
    else if (card == "8CloverBlack") {
        card1 = 21;
    }
    else if (card == "9CloverBlack") {
        card1 = 22;
    }
    else if (card == "10CloverBlack") {
        card1 = 23;
    }
    else if (card == "JCloverBlack") {
        card1 = 24;
    }
    else if (card == "QCloverBlack") {
        card1 = 25;
    }
    else if (card == "KCloverBlack") {
        card1 = 26;
    }
//////////////Hearts///////////////////////
    else if (card == "AHeartRed") {
        card1 = 27;
    }
    else if (card == "2HeartRed") {
        card1 = 28;
    }
    else if (card == "3HeartRed") {
        card1 = 29;
    }
    else if (card == "4HeartRed") {
        card1 = 30;
    }
    else if (card == "5HeartRed") {
        card1 = 31;
    }
    else if (card == "6HeartRed") {
        card1 = 32;
    }
    else if (card == "7HeartRed") {
        card1 = 33;
    }
    else if (card == "8HeartRed") {
        card1 = 34;
    }
    else if (card == "9HeartRed") {
        card1 = 35;
    }
    else if (card == "10HeartRed") {
        card1 = 36;
    }
    else if (card == "JHeartRed") {
        card1 = 37;
    }
    else if (card == "QHeartRed") {
        card1 = 38;
    }
    else if (card == "KHeartRed") {
        card1 = 39;
    }
///////////////Diamonds////////////////////////
    else if (card == "ADiamondRed") {
        card1 = 40;
    }
    else if (card == "2DiamondRed") {
        card1 = 41;
    }
    else if (card == "3DiamondRed") {
        card1 = 42;
    }
    else if (card == "4DiamondRed") {
        card1 = 43;
    }
    else if (card == "5DiamondRed") {
        card1 = 44;
    }
    else if (card == "6DiamondRed") {
        card1 = 45;
    }
    else if (card == "7DiamondRed") {
        card1 = 46;
    }
    else if (card == "8DiamondRed") {
        card1 = 47;
    }
    else if (card == "9DiamondRed") {
        card1 = 48;
    }
    else if (card == "10DiamondRed") {
        card1 = 49;
    }
    else if (card == "JDiamondRed") {
        card1 = 50;
    }
    else if (card == "QDiamondRed") {
        card1 = 51;
    }
    else if (card == "KDiamondRed") {
        card1 = 52;
    }
    return card1;
}

