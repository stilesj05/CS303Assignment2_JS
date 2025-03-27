#pragma once
#include <iostream>
#include <cstddef>  //for size_t

using namespace std;

//node structure for the linked list
template<typename Item_Type>
struct Node {
    Item_Type data;
    Node<Item_Type>* next;
};

//single linked list class declaration
template<typename Item_Type>
class SingleLinkedList {
public:
    //constructor and destructor
    SingleLinkedList();
    ~SingleLinkedList();

    //member function declarations
    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    void pop_front();
    void pop_back();
    Item_Type front() const;
    Item_Type back() const;
    bool empty() const;
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item) const;

    //helper function for testing in main
    void printList() const;
   
private:
    //declare data members
    Node<Item_Type>* head;
    Node<Item_Type>* tail;
    size_t num_items;
};


//Function Definitions (I do not have a .cpp for this because the Item_Type/template stuff was being weird when
//I tried to separate it)

//SingleLinkedList(): constructor
template<typename Item_Type>
SingleLinkedList<Item_Type>::SingleLinkedList() {
    //initialize head, tail, and num_items
    head = nullptr;
    tail = nullptr;
    num_items = 0;
}

//~SingleLinkedList(): destructor
template<typename Item_Type>
SingleLinkedList<Item_Type>::~SingleLinkedList() {
    //clear the list
    Node<Item_Type>* current = head; 
    while (current != nullptr) {
        Node<Item_Type>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

//push_front(): take an item from user and put that at the head of the list
template<typename Item_Type>
void SingleLinkedList<Item_Type>::push_front(const Item_Type& item) {
    //new node creation
    Node<Item_Type>* newNode = new Node<Item_Type>;
    newNode->data = item;
    newNode->next = nullptr;

    //if list is empty, newNode will be head and tail
    if (head == nullptr) { 
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
    ++num_items;
}

//push_back(): take an item from user and put that at the end of the list
template<typename Item_Type>
void SingleLinkedList<Item_Type>::push_back(const Item_Type& item) {
    Node<Item_Type>* newNode = new Node<Item_Type>;
    newNode->data = item;
    newNode->next = nullptr;

    //if list is empty, item will be head and tail
    if (head == nullptr) { 
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    ++num_items;
}

//pop_front(): delete first element of list
template<typename Item_Type>
void SingleLinkedList<Item_Type>::pop_front() {
    //check for empty list
    if (head == nullptr) {
        cout << "List is empty. No items to pop." << endl;
    }
    else {
        //check if there is only one node in the list
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            //create temp variable to store value after head, delete head, set temp variable to head
            Node<Item_Type>* temp = head->next;
            delete head;
            head = temp;
        }
        --num_items;
    }
}

//pop_back(): delete last element of the list
template<typename Item_Type>
void SingleLinkedList<Item_Type>::pop_back() {
    //check for empty list
    if (head == nullptr) {
        cout << "List is empty. No items to pop." << endl;
    }
    else {
        //check if there is only one node in the list
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            //traverse through the list, find the tail, and delete it. Set previous node to tail.
            Node<Item_Type>* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        --num_items; 
    }
}

//front(): return the data of the first node of the list
template<typename Item_Type>
Item_Type SingleLinkedList<Item_Type>::front() const {
    //check for empty list
    if (head == nullptr) {
        cout << "Empty list. Cannot return front value. ";
        return Item_Type();
    }
    return head->data;
}

//back(): return the data of the last node of the list
template<typename Item_Type>
Item_Type SingleLinkedList<Item_Type>::back() const {
    //check for empty list
    if (head == nullptr) {
        cout << "Empty list. Cannot return back value. ";
        return Item_Type();
    }
    return tail->data;
}

//empty(): return true if list is empty, otherwise return false
template<typename Item_Type>
bool SingleLinkedList<Item_Type>::empty() const {
    if (head == nullptr) {
        return true;
    }
    return false;
}

//insert(): insert an element into the list at the given index
template<typename Item_Type>
void SingleLinkedList<Item_Type>::insert(size_t index, const Item_Type& item) {
    //if index is 0, use push_front()
    if (index == 0) {
        push_front(item);
    }
    //if index is greater, add to end of list (push_back())
    else if (index >= num_items) {
        push_back(item);
    }
    else {
        //iterate through list to get to the node before the chosen index
        Node<Item_Type>* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        //create the new node with the given information
        Node<Item_Type>* newNode = new Node<Item_Type>;
        newNode->next = current->next;
        newNode->data = item;
        current->next = newNode;
        ++num_items;
    }
}

//remove(): remove an element of the list at the given index
template<typename Item_Type>
bool SingleLinkedList<Item_Type>::remove(size_t index) {
    //check if the list is empty or index is out of bounds
    if (head == nullptr || index >= num_items) {
        return false;
    }
    //if they want to remove first index
    if (index == 0) {
        Node<Item_Type>* temp = head;
        head = head->next;
        //if list is empty after this, update tail
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        --num_items;
        return true;
    }
    //iterate through list to get to 1 before selected index
    Node<Item_Type>* prev = head;
    for (size_t i = 0; i < index - 1; ++i) {
        prev = prev->next;
    }
    Node<Item_Type>* current = prev->next;
    Node<Item_Type>* after = current->next;
    prev->next = after;
    //if removing tail, update tail to be element before
    if (current == tail) {
        tail = prev;
    }
    delete current;
    --num_items;
    return true;
}

//find(): find an element at a given index
template<typename Item_Type>
size_t SingleLinkedList<Item_Type>::find(const Item_Type& item) const {
    Node<Item_Type>* current = head;
    size_t index = 0;
    //iterate through list to find the item at a certain index.
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        ++index;
    }
    return num_items;
}

// printList(): prints all elements in the list from head to tail.
template<typename Item_Type>
void SingleLinkedList<Item_Type>::printList() const {
    Node<Item_Type>* current = head;
    cout << "[ ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "]" << endl;
}
