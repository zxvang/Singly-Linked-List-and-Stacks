#include "Headers.h"

// LinkedList implementation
LinkedList::LinkedList() : headPtr(nullptr), tailPtr(nullptr), num_items(0) {}


LinkedList::~LinkedList() {
    while (headPtr) {
        pop_front();
    }
}

// Add to front
void LinkedList::push_front(int value) {
    Node* newNode = new Node(value);
    newNode->nextPtr = headPtr;
    headPtr = newNode;
    if (!tailPtr) tailPtr = newNode;
    ++num_items; // Update count
}

// Add to back
void LinkedList::push_back(int value) {
    Node* newNode = new Node(value);
    if (!tailPtr) {
        headPtr = tailPtr = newNode;
    } else {
        tailPtr->nextPtr = newNode;
        tailPtr = newNode;
    }
    ++num_items; // Update count
}

// Remove from front
void LinkedList::pop_front() {
    if (!headPtr) return;
    Node* temp = headPtr;
    headPtr = headPtr->nextPtr;
    delete temp;
    if (!headPtr) tailPtr = nullptr;
    --num_items; // Update count
}

// Remove from back
void LinkedList::pop_back() {
    if (!headPtr) return;
    if (headPtr == tailPtr) {
        delete headPtr;
        headPtr = tailPtr = nullptr;
        --num_items; // Update count
        return;
    }
    Node* curr = headPtr;
    while (curr->nextPtr != tailPtr) {
        curr = curr->nextPtr;
    }
    delete tailPtr;
    tailPtr = curr;
    tailPtr->nextPtr = nullptr;
    --num_items; // Update count
}

// Insert at index
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
    ++num_items; // Update count
}

// Remove at index
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
    --num_items; // Update count
    return true;
}

// Find value
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

// Print list
void LinkedList::print() const {
    Node* curr = headPtr;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->nextPtr;
    }
    cout << endl;
}

// Stack implementation

// Insert value
void Stack::push(int value) {
    data.push_back(value);
}

// Remove top element
void Stack::pop() {
    if (!data.empty())
        data.pop_back();
}

// Check if empty
bool Stack::isEmpty() const {
    return data.empty();
}

// Get top element
int Stack::top() const {
    if (!data.empty())
        return data.back();
    throw out_of_range("Stack is empty");
}

// Get average
double Stack::average() const {
    if (data.empty()) return 0.0;
    int sum = 0;
    for (int val : data) sum += val;
    return static_cast<double>(sum) / data.size();
}