#ifndef TREE_ITEM_TYPE
#define TREE_ITEM_TYPE

#include <string>

using namespace std;

typedef string KeyType; 

class TreeItemType {
    public:
        TreeItemType();
        TreeItemType(KeyType c);

        void SetKey(KeyType c);
        void Print();

        KeyType GetKey();

    private:
        KeyType key;
};

#endif