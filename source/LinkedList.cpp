#include "../header/LinkedList.h"

LinkedList::LinkedList(){
    head = tail = nullptr;
}

LinkedList::~LinkedList(){
    for(Node *temp = head; temp != nullptr; temp = head){
        head = head->next;
        delete temp;
    }
}

void LinkedList::push_back(Scene data){
    Node *temp = new Node(data);
    if(head == nullptr){
        head = tail = temp;
    }else{
        tail->next = temp;
        tail = temp;
    }
}

void LinkedList::pop_back(){
    if(head == nullptr){
        return;
    }else if(head == tail){
        delete head;
        head = tail = nullptr;
    }else{
        Node *temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
}

Scene &LinkedList::back(){
    return tail->data;
}