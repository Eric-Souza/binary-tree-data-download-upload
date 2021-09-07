#include <iostream>
#include <fstream>
#include <string>

// Header file imports
#include "BinaryTree.h"

using namespace std;

int main(int argc, char const *argv[]) {
    string textFile = argv[1];
    fstream file;

    file.open(textFile);

    if (!file.is_open()) {
        cerr << "Error while opening file\n";
        return -1;
    }

    BinaryTree Tree;

    int data, bin;
    string name;

    file >> data;

    for (int i = 0; i < data; i++) {
        file >> name;
        file >> bin;

        TreeItemType newItem;

        // Complexity: O(1)
        newItem.SetKey(name);

        // Complexity: O(log n)
        Tree.insert(newItem, bin);
    }
    
    // Complexity: O(n)
    Tree.go(2);
    printf("\n");

    NodeType *Node;

    while (file >> name) {
        // Complexity: O(log n) average case | O(1) best case | O(n) worst case (Tree degenerated)
        Node = Tree.search(name);

        // Complexity: O(n) 
        printf("%s %d\n", name.c_str(), Node -> listBin.sum()); 

        // Complexity: O(log n) average case | O(n) worst case
        Tree.remove(name);
    }

    // Complexity: O(n)
    Tree.go(2);

    file.close();

    return 0;
}
