#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

class Stack{
    public:
        Stack();
        void push(Scene data);
        Scene pop();
        Scene peek();
        bool isEmpty();

    private:
        LinkedList list;
        int size;
};

#endif