#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

template <typename Item_Type>
class Single_Linked_List {
public:
    struct Node {
        Item_Type data;
        Node* next;

        Node(const Item_Type& item) : data(item), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t num_items;

public:
    Single_Linked_List();
    ~Single_Linked_List();

    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    bool pop_front();
    bool pop_back();
    Item_Type front();
    Item_Type back();
    bool empty() const;
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item);
};

#endif