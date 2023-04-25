#ifndef LINKEDLIST_H
#define LINKEDLIST_H

enum Scene{
    Login = 0,
    Main,
    Exit
};

class LinkedList{
    public:
        LinkedList();
        ~LinkedList();
        void push_back(Scene data);
        void pop_back();
        Scene &back();

    private:
        struct Node{
            Scene data;
            Node* next;

            Node(Scene data){
                this->data = data;
                this->next = nullptr;
            }
        };
        Node* head;
        Node* tail;
};

#endif