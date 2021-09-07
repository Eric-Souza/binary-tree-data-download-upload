#include <stdio.h>

// Header file imports
#include "ListItemType.h"

ListItemType :: ListItemType() {
    key = -1; 
}

ListItemType :: ListItemType(ListKeyType c) {
    key = c;
}

ListKeyType ListItemType :: GetKey() {
    return key;
}

void ListItemType :: SetKey(ListKeyType c) {
    key = c;
}

void ListItemType :: Print() {
    printf("%d ", key);
}
