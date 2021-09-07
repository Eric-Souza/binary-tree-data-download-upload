#ifndef CHAINED_LIST
#define CHAINED_LIST

// Header file imports
#include "ListItemType.h"

class Node {
    public:
        Node();

    private:
        ListItemType item;
        Node *next;

        friend class ChainedList;
};

class ChainedList {
    public: 
        ChainedList();
        ~ChainedList();

        ListItemType getItem(int position);

        void setItem(ListItemType item, int position);
        void insertStart(ListItemType item);
        void insertEnd(ListItemType item);
        void insertPosition(ListItemType item, int position);

        ListItemType Search(ListKeyType c);
        ListItemType removeStart();
        ListItemType removeEnd();
        ListItemType removePosition(int position);

        void Clean();
        void Print();
        int sum();

    private:
        Node *first;
        Node *last;
        Node *position(int position, bool before);

        int size;
};

#endif