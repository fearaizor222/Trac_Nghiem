#include "../header/Stack.h"

Stack::Stack(){
    size = 0;
}

void Stack::push(Scene data){
    list.push_back(data);
    size++;
}

Scene Stack::pop(){
    if(isEmpty()){
        return Exit;
    }
    Scene temp = list.back();
    list.pop_back();
    size--;
    return temp;
}

Scene Stack::peek(){
    if(isEmpty()){
        return Exit;
    }
    return list.back();
}

bool Stack::isEmpty(){
    return size == 0;
}