//CS303 ASSIGNMENT 2
//NAME: Jaydine Stiles
//DUE: Sept. 26, 2024

#include <iostream>
#include "SingleLinkedList.h" 
#include "Stack.h"            

using namespace std;  // Since you're using namespace std

int main() {
    cout << "=== SINGLE LINKED LIST TESTING ===" << endl;

    SingleLinkedList<int> list;

    // --- Testing EMPTY on empty list ---
    cout << "\n-- Testing EMPTY on empty list --" << endl;
    cout << "Is the list empty? " << (list.empty() ? "Yes" : "No") << endl;

    cout << "Calling pop_front on empty list:" << endl;
    list.pop_front();  //error

    cout << "Calling pop_back on empty list:" << endl;
    list.pop_back();   //error

    cout << "Calling front() on empty list:" << endl;
    int f = list.front();  //error, return 0
    cout << "Front returns: " << f << endl;

    cout << "Calling back() on empty list:" << endl;
    int b = list.back();   //error, return 0
    cout << "Back returns: " << b << endl;

    cout << "Calling remove(0) on empty list:" << endl;
    bool rem = list.remove(0);  //error, return false
    cout << "Remove returned: " << (rem ? "true" : "false") << endl;

    cout << "Calling find(0) on empty list:" << endl;
    size_t pos = list.find(0);
    cout << "Find returned index: " << pos << " (should be num_items)" << endl;


    // --- Testing INSERT functionality ---
    cout << "\n-- Testing INSERT --" << endl;
    cout << "Inserting 333 at index 1 on empty list" << endl;
    list.insert(1, 333);  
    cout << "List after insertion: ";
    list.printList(); //[ 333 ]

    cout << "Inserting 333 at index 0:" << endl;
    list.insert(0, 465);  
    cout << "List now: ";
    list.printList(); //[ 465 333 ]

    cout << "Inserting 50 at index 1:" << endl;
    list.insert(1, 50); 
    cout << "List now: ";
    list.printList(); //[ 465 50 333 ]

    cout << "Inserting 1000 at index 3:" << endl;
    list.insert(3, 1000);  
    cout << "List now: ";
    list.printList(); //[ 465 50 333 1000 ]


    // --- Testing REMOVE functionality ---
    //list right now is [ 333 50 333 10000 ]
    cout << "\n-- Testing REMOVE --" << endl;
    cout << "Attempting to remove element at index 5 (out-of-bounds):" << endl;
    rem = list.remove(5);
    cout << "Remove returned: " << (rem ? "true" : "false") << endl;
    cout << "List remains: ";
    list.printList(); // [ 333 50 333 1000 ]

    cout << "Removing element at index 0:" << endl;
    list.remove(0);
    cout << "List now: ";
    list.printList(); // [ 50 333 1000 ]

    cout << "Removing element at index 1:" << endl;
    list.remove(1);
    cout << "List now: ";
    list.printList(); // [ 50 1000 ]

    //reinsert for more testing
    list.insert(0, 50);
    list.insert(1, 66);
    list.insert(2, 77);

    //list now is [ 50 66 77 50 1000 ]
    cout << "\n-- Testing PUSH_FRONT and PUSH_BACK --" << endl;
    cout << "Current list: ";
    list.printList(); // [ 50 66 77 50 1000 ]

    cout << "Calling push_front(25) and push_front(10):" << endl;
    list.push_front(25);
    list.push_front(10);
    cout << "List now: ";
    list.printList(); // [ 10 25 50 66 77 50 1000 ]

    cout << "Calling push_back(88) and push_back(99):" << endl;
    list.push_back(88);
    list.push_back(99);
    cout << "List now: ";
    list.printList(); // [ 10 25 50 66 77 50 1000 88 99 ]


    // --- Testing FRONT, POP_FRONT, BACK, and POP_BACK ---
    cout << "\n-- Testing FRONT, POP_FRONT, BACK, and POP_BACK --" << endl;
    list.printList(); 
    if (!list.empty()) {
        cout << "Front element: " << list.front() << endl; //10
        cout << "Back element: " << list.back() << endl; //99
    }
    cout << "Calling pop_front():" << endl;
    list.pop_front();
    cout << "List after pop_front: ";
    list.printList(); // [ 25 50 66 77 50 1000 88 99 ]

    cout << "Calling pop_back():" << endl;
    list.pop_back();
    cout << "List after pop_back: ";
    list.printList(); // [ 25 50 66 77 50 1000 88 ]


    // --- Testing FIND ---
    cout << "\n-- Testing FIND --" << endl;
    cout << "Current list: ";
    list.printList(); //[ 25 50 66 77 50 1000 88 ]
    cout << "Finding first occurrence of 66: index " << list.find(66) << endl; //index 2
    cout << "Finding first occurrence of 999 (not in list): index " << list.find(999) << " (should be num_items)" << endl; //not in list, return num_items which is 7


    // --- Testing EMPTY ---
    cout << "\n-- Testing EMPTY --" << endl;
    cout << "Is the list empty? " << (list.empty() ? "Yes" : "No") << endl; //no


    // ===== STACK FUNCTIONALITY =====
    cout << "\n\n=== STACK FUNCTIONALITY ===" << endl;
    Stack myStack;

    cout << "\nIs the stack empty? " << (myStack.empty() ? "Yes" : "No") << endl; //no

    cout << "\nInserting 5, 10, and 20 onto the stack..." << endl;
    myStack.insert(5);
    myStack.insert(10);
    myStack.insert(20);
    cout << "Current stack (top to bottom): "; //20 10 5
    myStack.printStack();

    cout << "\nTop of the stack: " << myStack.top() << endl; //20

    cout << "\nRemoving the top element from the stack..." << endl; 
    myStack.remove();
    cout << "Stack after removal: ";
    myStack.printStack(); //10 5

    cout << "\nAverage of the stack elements: " << myStack.average() << endl; //7.5
    cout << "Is the stack empty? " << (myStack.empty() ? "Yes" : "No") << endl; //no

    return 0;
}