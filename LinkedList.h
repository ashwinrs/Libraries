/*
 *
 * LinkedList.h
 *
 */

#ifndef _LinkedList_h
#define _LinkedList_h

#include "Node.h"

class LinkedList{
public:
    LinkedList();
    ~LinkedList();
    bool empty() const;
    const int front() const;
    void addFront(const int data);
    void removeFront();
private:
    Node* head;
};

#endif
