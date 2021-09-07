#include <iostream>
#include <math.h>

// Header file imports
#include "ChainedList.h"

using namespace std;

Node :: Node() {
    item.SetKey(-1);
    next = NULL;
}

ChainedList :: ChainedList() {
    first = new Node();
    last = first;
    size = 0;
}

// O(n)
ChainedList :: ~ChainedList() {
    Clean();
    delete first;
}

// O(n)
Node* ChainedList :: position(int pos, bool before = false) {
    if ((pos > size) || (pos <= 0)) {
        cerr << "Invalid position";
        exit(-1);
    }

    Node *p;
    p = first;

    for (int i = 1; i < pos; i++) {
        p = p -> next;
    }

    if (!before) p = p -> next;

    return p;
}

ListItemType ChainedList :: getItem(int pos) { return position(pos) -> item; }

void ChainedList :: setItem(ListItemType item, int pos) { position(pos) -> item = item; }

void ChainedList :: insertStart(ListItemType item) {
    Node *newNode = new Node();
    newNode -> item = item;

    newNode -> next = first -> next;
    first -> next = newNode;
    size++;

    if (newNode -> next == NULL) last = newNode;
}

void ChainedList :: insertEnd(ListItemType item) {
    Node *newNode = new Node();
    newNode -> item = item;

    last -> next = newNode;
    last = newNode;
    size++;
}

void ChainedList :: insertPosition(ListItemType item, int pos) {
    if ((pos > size) || (pos <= 0)) {
        cerr << "Invalid position";
        exit(-1);
    }

    Node *newNode = new Node();
    newNode -> item = item;

    Node *aux = position(pos, true);

    newNode -> next = aux -> next;
    aux -> next = newNode;
    size++;

    if (newNode -> next == NULL) last = newNode;
}

ListItemType ChainedList :: removeStart() {
    ListItemType aux;
    Node *p;

    if (size == 0) {
        cerr << "List is empty";
        exit(-1);
    }

    p = first -> next; 

    first -> next = p -> next;
    size--;

    if (first -> next == NULL) last = first;

    aux = p -> item;
    delete p; 

    return aux;
}

ListItemType ChainedList :: removeEnd() {
    ListItemType aux;
    Node *p;

    if (size == 0) {
        cerr << "List is empty";
        exit(-1);
    }

    p = position(size, true);

    aux = last -> item;
    p -> next = NULL;
    size--;

    delete last;
    last = p;

    return aux;
}

ListItemType ChainedList :: removePosition(int pos) {
    if (size == 0)
    {
        cerr << "List is empty";
        exit(-1);
    }

    ListItemType aux;
    Node *p, *q;

    p = position(pos, true);
    q = p -> next;
    aux = q -> item;

    p -> next = q -> next;
    size--;

    delete q;

    if (p -> next == NULL) last = p;

    return aux;
}

ListItemType ChainedList :: Search(ListKeyType c) {
    ListItemType aux(-1);
    Node *p;

    if (size == 0) {
        cerr << "List is empty";
        exit(-1);
    }

    p = first -> next;

    while (p != NULL) {
        if (p -> item.GetKey() == c) {
            aux = p -> item;
            break;
        }

        p = p -> next;
    }

    return aux;
}

void ChainedList :: Print() {
    Node *p;

    p = first -> next;

    while (p != NULL) {
        p -> item.Print();
        p = p -> next;
    }

    cout << endl;
}

void ChainedList :: Clean() {
    Node *p;

    p = first -> next;

    while (p != NULL) {
        first -> next = p -> next;
        delete p;

        p = first -> next;
    }

    last = first;
    size = 0;
}


int convertToBinary(int n) {
    int decimal = 0;

    int bit;
    int i = 0;

    while (n != 0) {
        bit = n % 10;
        n = n / 10;
        decimal += bit * pow(2, i);

        i++;
    }

    return decimal;
}

int ChainedList :: sum() {
    Node *p;
    p = first -> next;

    int fullSum = 0;
    int decimal;

    while (p != NULL) {
        decimal = convertToBinary(p -> item.GetKey());
        fullSum += decimal;

        p = p -> next;
    }

    return fullSum;
}