#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class LinkedList
{
public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) { this->value = value; }
};

#endif // LINKED_LIST_H
