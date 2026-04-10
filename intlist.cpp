// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    if (source.head == nullptr){ // checks if the LL is empty
        head = nullptr; // if so head points to nothing and returns
        return;
    }

    head = new Node; // creates first new node
    head -> info = source.head -> info; // sets the value of the node

    head -> next = nullptr; // makes the node point to nothing
    tail = head; // 

    Node* old = source.head -> next; // variable old to keep track of original list

    while (old != nullptr){ // loops through each node
        Node* block = new Node; // creates new node
        block -> info = old -> info; // assigns the value of the old to the new node
        block -> next = nullptr; // makes the node point to nothing
        tail -> next = block; // links the last node to the new node
        tail = block; // increments the tail
        old = old -> next; // moves to the next node in the original list
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    while(head != nullptr){ // loops through every node
        Node* temp = head; // creates temp var for head
        head = head -> next; // moves to next node
        delete temp; // deletes the node temp is at 
    }
}


// return sum of values in list
int IntList::sum() const {
    Node* temp = head; // creates temp var for head
    int sum = 0; // initializes sum to 0
    while(temp != nullptr){ // loops through every node
        sum += temp -> info; // adds value of each node to sum
        temp = temp -> next; // moves to next node
    }

    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    if (head == nullptr){ // checks for empty list and returns false if so
        return false;
    }

    Node* temp = head; // creates temp var for head
    while(temp != nullptr){ // loops through every node
        if (temp -> info == value){ // checks if the value at that node is equal to the specified value
            return true; // if so returns true
        }
        temp = temp -> next; // moves to the next node
    }

    return false; 
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (head == nullptr){ // checks for empty list and if so returns 0
        return 0;
    }

    Node* temp = head; // makes temp var for head
    int max = temp -> info; // initializes max to first value
    while(temp != nullptr){ // loops through every node
        if (temp -> info > max){ // checks if value at node is greater than current max
            max = temp -> info; // if so replaces value of max
        }
        temp = temp -> next; // moves to next node
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (head == nullptr){ // checks for empty list and if so returns 0
        return 0.0;
    }

    Node* temp = head; // creates temp var for head

    // initalizes sum and count values
    double sum = 0;
    int count = 0;

    while(temp != nullptr){ // loops through every value
        sum += temp -> info; // increases sum by value in node
        count++; // increments count
        temp = temp -> next; // moves to next node
    }

    return sum / count; // returns the average 
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* temp = new Node; // creates temp var for head
    temp -> info = value; // sets the value of the node
    temp -> next = head; // makes the node point to the previous first node in list
    head = temp; // head points to the new node
}

// append value at end of list
void IntList::push_back(int value) {
    
    Node* temp = new Node; // creates temp var for head
    temp -> info = value; // sets the value of the node
    temp -> next = nullptr; // makes the node point to nothing (end of list)

    if (head == nullptr){ // checks if list is empty
        // if so both head and tail point to the new node
        tail = temp;
        head = temp;
    }
    else{
        // otherwise makes the previous last node point to the new node and tail point to the new node
        tail -> next = temp;
        tail = temp;
    }
    
}

// return count of values
int IntList::count() const {
    Node* temp = head; // creates temp var for head
    int count = 0; // initializes count to 0

    while(temp != nullptr){ // loops through every node
        count++; // increments count
        temp = temp -> next; // moves to next node
    }

    return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    while(head != nullptr){ // loops through every node
        Node* temp = head; // creates temp var for head
        head = head -> next; // moves head to next node before deletion
        delete temp; // deletes node 
    }

    tail = nullptr; // removes tail pointer

    if (source.head != nullptr){ // checks if list isn't empty
        head = new Node; // creates first new node
        head -> info = source.head -> info; // sets the value of the node

        head -> next = nullptr; // makes the node point to nothing
        tail = head; // 

        Node* old = source.head -> next; // variable old to keep track of original list

        while (old != nullptr){ // loops through each node
            Node* block = new Node; // creates new node
            block -> info = old -> info; // assigns the value of the old to the new node
            block -> next = nullptr; // makes the node point to nothing
            tail -> next = block; // links the last node to the new node
            tail = block; // increments the tail
            old = old -> next; // moves to the next node in the original list
        }
    }

    else {
        // if list is empty, sets both head and tail to point to nothing
        head = nullptr; 
        tail = nullptr;
    }

    return *this; 
}

// constructor sets up empty list
IntList::IntList(){ 
    // initalizes both head and tail to nullptr
    head = nullptr;
    tail = nullptr;
}




// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

