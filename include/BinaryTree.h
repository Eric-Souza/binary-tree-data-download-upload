#ifndef BINARY_TREE
#define BINARY_TREE

// Header file imports
#include "ChainedList.h"
#include "TreeItemType.h"

class NodeType {
    public:
        NodeType();

        ChainedList listBin;
        TreeItemType item;

    private:
        NodeType *left;
        NodeType *right;

        friend class BinaryTree;
};

class BinaryTree {
    public:
        BinaryTree();
        ~BinaryTree();

        void insert(TreeItemType item, int _bin);
        void go(int type);

        NodeType *search(KeyType chave); 

        void remove(KeyType chave);      
        void clean();

    private:
        void recursiveInsert(NodeType *&p, TreeItemType item, int _bin);
        void recursiveDelete(NodeType *p);

        NodeType *recursiveSearch(NodeType *p, KeyType c); 
        
        void recursiveRemove(NodeType *&p, KeyType chave); 
        void previous(NodeType *q, NodeType *&r);             
        void forLevel();

        void preOrder(NodeType *p);
        void inOrder(NodeType *p);
        void posOrder(NodeType *p);

        NodeType *root;
};

#endif