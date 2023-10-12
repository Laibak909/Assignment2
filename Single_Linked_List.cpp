#include "Single_Linked_List.h"
#include <iostream>

using namespace std;

template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (!empty()) {
        pop_front();
    }
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = new_node;
        tail = new_node;
    }
    else {
        new_node->next = head;
        head = new_node;
    }
    num_items++;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = new_node;
        tail = new_node;
    }
    else {
        tail->next = new_node;
        tail = new_node;
    }
    num_items++;
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::pop_front() {
    if (empty()) {
        return false;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    num_items--;
    if (num_items == 0) {
        tail = nullptr;
    }
    return true;
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::pop_back() {
    if (empty()) {
        return false;
    }
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    num_items--;
    return true;
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() {
    if (!empty()) {
        return head->data;
    }
    // Handle empty list (you may choose to throw an exception here).
    return Item_Type();
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() {
    if (!empty()) {
        return tail->data;
    }
    // Handle empty list (you may choose to throw an exception here).
    return Item_Type();
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return num_items == 0;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index > num_items) {
        index = num_items;
    }
    Node* new_node = new Node(item);
    if (index == 0) {
        new_node->next = head;
        head = new_node;
        if (tail == nullptr) {
            tail = new_node;
        }
    }
    else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        if (index == num_items) {
            tail = new_node;
        }
    }
    num_items++;
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items) {
        return false;
    }
    if (index == 0) {
        pop_front();
    }
    else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        if (index == num_items - 1) {
            tail = current;
        }
        num_items--;
    }
    return true;
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) {
    Node* current = head;
    size_t index = 0;
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items;  // Item not found, return the size of the list.
}



int main() {
    Single_Linked_List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);

    cout << endl;
    cout << "  List: ";

    for (Single_Linked_List<int>::Node* current = list.head; current != nullptr; current = current->next) {
        cout << ":::: " << current->data << " --> ";
    }
    cout << "None";
    cout << endl << endl;

    cout << "  *  Front: " << list.front();
    cout << endl << endl;
    cout << "  *  Back: " << list.back();
    cout << endl << endl;

    list.insert(2, 100);
    cout << "  Inserted 100 at index 2: " << endl;
    cout << endl << "  List: ";
    for (Single_Linked_List<int>::Node* current = list.head; current != nullptr; current = current->next) {
        cout << ":::: " << current->data << " --> ";
    }
    cout << "None";
    cout << endl << endl;

    cout << "  Removed item at index 1: " << list.remove(1);
    cout << endl << endl;
    cout << "  List: ";
    for (Single_Linked_List<int>::Node* current = list.head; current != nullptr; current = current->next) {
        cout << ":::: " << current->data << " -> ";
    }
    cout << "None";
    cout << endl;

    cout << endl;
    cout << "   * Index of 2: " << list.find(2);
    cout << endl;
    cout << endl;
    cout << "   * Index of 4: " << list.find(4);
    cout << endl;

    return 0;
}


