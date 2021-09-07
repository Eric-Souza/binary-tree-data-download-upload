#include <iostream>


// Header file imports
#include "BinaryTree.h"

NodeType :: NodeType() {
    left = NULL;
    right = NULL;
}

BinaryTree :: BinaryTree() {
    root = NULL;
}

BinaryTree :: ~BinaryTree() {
    clean();
}

void BinaryTree :: insert(TreeItemType item, int _bin) {
    recursiveInsert(root, item, _bin);
}

void BinaryTree :: recursiveInsert(NodeType *&p, TreeItemType item, int _bin) {
    ListItemType binaryNumber;
    binaryNumber.SetKey(_bin);

    if (p == NULL) {
        p = new NodeType();

        p -> item = item;
        p -> listBin.insertEnd(binaryNumber);
    }

    else {
        if (item.GetKey() > p -> item.GetKey()) recursiveInsert(p -> right, item, _bin);
        else if (item.GetKey() < p -> item.GetKey()) recursiveInsert(p -> left, item, _bin);
        else p -> listBin.insertEnd(binaryNumber);
    }
}

void BinaryTree :: preOrder(NodeType *p) {
    if (p == NULL) {
        p -> item.Print();

        preOrder(p -> left);
        preOrder(p -> right);
    }
}

void BinaryTree :: inOrder(NodeType *p) {
    if (p != NULL) {
        inOrder(p -> left);
        p -> item.Print();
        inOrder(p -> right);
    }
}

void BinaryTree :: posOrder(NodeType *p) {
    if (p != NULL) {
        posOrder(p -> left);
        posOrder(p -> right);

        p -> item.Print();
    }
}

void BinaryTree :: forLevel() {}

void BinaryTree :: clean() {
    recursiveDelete(root);
    root = NULL;
}

void BinaryTree :: recursiveDelete(NodeType *p) {
    if (p != NULL) {
        recursiveDelete(p -> left);
        recursiveDelete(p -> right);

        delete p;
    }
}

NodeType* BinaryTree :: search(KeyType key) { return recursiveSearch(root, key); }

NodeType* BinaryTree :: recursiveSearch(NodeType *p, KeyType key) {
    TreeItemType aux;

    if (p == NULL) return new NodeType();
    if (key > p -> item.GetKey()) return recursiveSearch(p -> right, key);
    else if (key < p -> item.GetKey()) return recursiveSearch(p -> left, key);

    // Returns current item with key
    else return p; 
}

void BinaryTree :: remove(KeyType key) { return recursiveRemove(root, key); }

void BinaryTree :: recursiveRemove(NodeType *&node, KeyType key) {
    NodeType *aux;

    if (node == NULL) {
        std::cerr << "Item not found";
        exit(-1);
    }

    if (key < node -> item.GetKey()) return recursiveRemove(node -> left, key);
    else if (key > node -> item.GetKey()) return recursiveRemove(node -> right, key);

    else {
        if (node -> right == NULL) {
            aux = node;
            node = node -> left;

            free(aux);
        }

        else if (node -> left == NULL) {
            aux = node;
            node = node -> right;

            free(aux);
        }

        else previous(node, node -> left);
    }
}

void BinaryTree :: previous(NodeType *q, NodeType *&r) {
    if (r -> right != NULL) {
        previous(q, r -> right);
        return;
    }

    q -> item = r -> item;
    q -> listBin = r -> listBin;
    q = r;
    r = r -> left;

    free(q);
}

void BinaryTree :: go(int tipo) {
    if (tipo == 1) preOrder(root);
    else if (tipo == 2) inOrder(root);
    else if (tipo == 3) posOrder(root);

    else std::cerr << "Tipo não é válido";
}