#include <iostream>

// Header file imports
#include "TreeItemType.h"

TreeItemType :: TreeItemType() {
    key = "";
}

TreeItemType :: TreeItemType(KeyType c) {
    key = c;
}

KeyType TreeItemType :: GetKey() {
    return key;
}

void TreeItemType :: SetKey(KeyType c) {
    key = c;
}

void TreeItemType :: Print() {
    std :: cout << key << " ";
}
