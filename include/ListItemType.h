#ifndef LIST_ITEM_TYPE
#define LIST_ITEM_TYPE

using namespace std;

typedef int ListKeyType; 

class ListItemType {
    public:
        ListItemType();
        ListItemType(ListKeyType c);

        void SetKey(ListKeyType c);
        void Print();

        ListKeyType GetKey();

    private:
        ListKeyType key;
};

#endif