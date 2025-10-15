#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include <string>

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
    size_t num_items;

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

    size_t size() const { return num_items; }
};

class Stack {
private:
    vector<int> data;
public:
    void push(int value);           // Insert value
    void pop();                     // Remove top element
    bool isEmpty() const;           // Check if empty
    int top() const;                // Get top element
    double average() const;         // Get average
};