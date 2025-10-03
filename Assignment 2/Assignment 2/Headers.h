#pragma once
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* nextPtr;
    Node() : data(0), nextPtr(nullptr) {}
    Node(int d) : data(d), nextPtr(nullptr) {}
};

class LinkedList {
private:
    Node* headPtr;
    Node* tailPtr;

public:
    LinkedList();
    ~LinkedList();

    void push_front(int value);
    void push_back(int value);
    void pop_front();
    void pop_back();
    void insert(size_t index, int value);
    bool remove(size_t index);
    size_t find(int value) const;
    void print() const;
};

class Numbers {
protected:
    int num;

public:
    Numbers(); // Default constructor
    Numbers(int n); // Overload constructor

    int getNum() const { return num; } // Accessor
    void setNum(int n) { num = n; } // Mutator
};