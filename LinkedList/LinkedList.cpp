//
//  LinkedList.cpp
//  
//
//  Created by Ashwin R S on 12/24/13.
//
//

#include "LinkedList.h"

LinkedList::LinkedList():head(NULL){ //constructor
    
}

LinkedList::~LinkedList(){
    while (!empty()) {
        removeFront();
    }
}

bool LinkedList::empty() const{
    return head == NULL;
}

const int LinkedList::front() const{
    return head->data;
}

void LinkedList::addFront(const int d) {
    Node* temp = new Node;
    temp->data = d;

    head = new Node();
    head->data = d;
}

void LinkedList::removeFront(){
    Node* old = head;
    head = old->next;
    delete old;
}