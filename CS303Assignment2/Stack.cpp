#include "Stack.h"
#include <iostream>

Stack::Stack() {
    stackElements = vector<int>();
}

//empty(): see if stack is empty
bool Stack::empty() const {
    return stackElements.empty();
}

//insert(): add an element to the stack
void Stack::insert(int value) {
    stackElements.push_back(value);
}

//remove(): remove an element from the top of the stack
void Stack::remove() {
    stackElements.pop_back();
}

//top(): return the value at the top of the stack
int Stack::top() const {
    return stackElements.back();
}

//average(): return the average of the elements in the stack
double Stack::average() const {
    if (stackElements.empty()) {
        return 0;
    }
    else {
        int total = 0;
        for (size_t i = 0; i < stackElements.size(); ++i) {
            total += stackElements[i];
        }
        return (1.0 * total) / stackElements.size();
    }
}

//printStack(): show the stack in terminal, for convenience in testing
void Stack::printStack() {
    for (int i = stackElements.size() - 1; i >= 0; --i) {
        cout << stackElements[i] << " ";
    }
    cout << endl;
}
