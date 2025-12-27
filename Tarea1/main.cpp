// archivo main.cpp

#include "deck.h"
#include <iostream>
using namespace std;
////Clover are solicited before pick to show that the insert sorted works properly
//// Main call a insert_sorted who call a dictionary to turn cards in numbers

int main() {
    List deck;
    
    deck.insert_sorted(dictionary("ACloverBlack"));
    deck.insert_sorted(dictionary("2CloverBlack"));
    deck.insert_sorted(dictionary("3CloverBlack"));
	deck.insert_sorted(dictionary("4CloverBlack"));
	deck.insert_sorted(dictionary("5CloverBlack"));
	deck.insert_sorted(dictionary("6CloverBlack"));
	deck.insert_sorted(dictionary("7CloverBlack"));
	deck.insert_sorted(dictionary("8CloverBlack"));
	deck.insert_sorted(dictionary("9CloverBlack"));
	deck.insert_sorted(dictionary("10CloverBlack"));
	deck.insert_sorted(dictionary("JCloverBlack"));

    deck.insert_sorted(dictionary("APickBlack"));
    deck.insert_sorted(dictionary("2PickBlack"));
    deck.insert_sorted(dictionary("3PickBlack"));
	deck.insert_sorted(dictionary("4PickBlack"));
	deck.insert_sorted(dictionary("5PickBlack"));
	deck.insert_sorted(dictionary("6PickBlack"));
	deck.insert_sorted(dictionary("7PickBlack"));
	deck.insert_sorted(dictionary("8PickBlack"));
	deck.insert_sorted(dictionary("9PickBlack"));
	deck.insert_sorted(dictionary("10PickBlack"));
	deck.insert_sorted(dictionary("JPickBlack"));
	
	deck.insert_sorted(dictionary("AHeartRed"));
    deck.insert_sorted(dictionary("2HeartRed"));
    deck.insert_sorted(dictionary("3HeartRed"));
	deck.insert_sorted(dictionary("4HeartRed"));
	deck.insert_sorted(dictionary("5HeartRed"));
	deck.insert_sorted(dictionary("6HeartRed"));
	deck.insert_sorted(dictionary("7HeartRed"));
	deck.insert_sorted(dictionary("8HeartRed"));
	deck.insert_sorted(dictionary("9HeartRed"));
	deck.insert_sorted(dictionary("10HeartRed"));
	deck.insert_sorted(dictionary("JHeartRed"));
	
	deck.insert_sorted(dictionary("ADiamondRed"));
    deck.insert_sorted(dictionary("2DiamondRed"));
    deck.insert_sorted(dictionary("3DiamondRed"));
	deck.insert_sorted(dictionary("4DiamondRed"));
	deck.insert_sorted(dictionary("5DiamondRed"));
	deck.insert_sorted(dictionary("6DiamondRed"));
	deck.insert_sorted(dictionary("7DiamondRed"));
	deck.insert_sorted(dictionary("8DiamondRed"));
	deck.insert_sorted(dictionary("9DiamondRed"));
	deck.insert_sorted(dictionary("10DiamondRed"));
	deck.insert_sorted(dictionary("JDiamondRed"));
    deck.display();

    return 0;
}
