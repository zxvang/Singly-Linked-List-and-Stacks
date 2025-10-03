#include "Headers.h"

// LinkedList implementation
LinkedList::LinkedList() : headPtr(nullptr), tailPtr(nullptr) {}

LinkedList::~LinkedList() {
    while (headPtr) {
        pop_front();
    }
}

void LinkedList::push_front(int value) {
    Node* newNode = new Node(value);
    newNode->nextPtr = headPtr;
    headPtr = newNode;
    if (!tailPtr) tailPtr = newNode;
}

void LinkedList::push_back(int value) {
    Node* newNode = new Node(value);
    if (!tailPtr) {
        headPtr = tailPtr = newNode;
    } else {
        tailPtr->nextPtr = newNode;
        tailPtr = newNode;
    }
}

void LinkedList::pop_front() {
    if (!headPtr) return;
    Node* temp = headPtr;
    headPtr = headPtr->nextPtr;
    delete temp;
    if (!headPtr) tailPtr = nullptr;
}

void LinkedList::pop_back() {
    if (!headPtr) return;
    if (headPtr == tailPtr) {
        delete headPtr;
        headPtr = tailPtr = nullptr;
        return;
    }
    Node* curr = headPtr;
    while (curr->nextPtr != tailPtr) {
        curr = curr->nextPtr;
    }
    delete tailPtr;
    tailPtr = curr;
    tailPtr->nextPtr = nullptr;
}

void LinkedList::insert(size_t index, int value) {
    if (index == 0) {
        push_front(value);
        return;
    }
    Node* curr = headPtr;
    for (size_t i = 0; curr && i < index - 1; ++i) {
        curr = curr->nextPtr;
    }
    if (!curr) return;
    Node* newNode = new Node(value);
    newNode->nextPtr = curr->nextPtr;
    curr->nextPtr = newNode;
    if (!newNode->nextPtr) tailPtr = newNode;
}

bool LinkedList::remove(size_t index) {
    if (!headPtr) return false;
    if (index == 0) {
        pop_front();
        return true;
    }
    Node* curr = headPtr;
    for (size_t i = 0; curr->nextPtr && i < index - 1; ++i) {
        curr = curr->nextPtr;
    }
    if (!curr->nextPtr) return false;
    Node* temp = curr->nextPtr;
    curr->nextPtr = temp->nextPtr;
    if (temp == tailPtr) tailPtr = curr;
    delete temp;
    return true;
}

size_t LinkedList::find(int value) const {
    Node* curr = headPtr;
    size_t index = 0;
    while (curr) {
        if (curr->data == value) return index;
        curr = curr->nextPtr;
        ++index;
    }
    return static_cast<size_t>(-1); // Not found
}

void LinkedList::print() const {
    Node* curr = headPtr;
    while (curr) {
        std::cout << curr->data << " ";
        curr = curr->nextPtr;
    }
    std::cout << std::endl;
}

// Numbers implementation
Numbers::Numbers() : num(0) {}
Numbers::Numbers(int n) : num(n) {}