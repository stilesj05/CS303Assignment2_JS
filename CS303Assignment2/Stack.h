#pragma once

#include <vector>
using namespace std;

class Stack {
public:
    //constructor
    Stack();

    //member functions
    bool empty() const;
    void insert(int value);
    void remove();
    int top() const;
    double average() const;

    //helper function for testing in main
    void printStack();

private:
    //create vector for the stack
    vector<int> stackElements;  
};
