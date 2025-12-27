#ifndef DECK_H
#define DECK_H
#include <bits/stringfwd.h>
#include <string>
#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int val);
};

class List {
public:
    List();
    ~List();
    void insert_sorted(int val);
    void display();
private:
    Node* first;
};
int dictionary(std::string card);

#endif
