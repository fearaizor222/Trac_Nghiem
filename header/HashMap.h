#ifndef HASHMAP_H
#define HASHMAP_H

#include <initializer_list>
#include <utility>
#include <string>

/**
 * @brief HashMap but only for string key and string value
*/
class HashMap{
    public:
        struct Node{
            std::string key;
            std::string value;
            Node* next;

            Node(std::string key, std::string value){
                this->key = key;
                this->value = value;
                this->next = nullptr;
            }
        };

        HashMap(){
            this->size = 100;
            this->data = new Node*[size];
            for(int i = 0; i< size; i++){
                data[i] = nullptr;
            }
        }

        HashMap(int size){
            this->size = size;
            this->data = new Node*[size];
            for(int i = 0; i< size; i++){
                data[i] = nullptr;
            }
        }

        HashMap(std::initializer_list<std::pair<std::string, std::string>> list) : HashMap(list.size()){
            typename std::initializer_list<std::pair<std::string, std::string>>::iterator it = list.begin();

            while(it != list.end()){
                int index = hashFunction(it->first);
                Node* node = new Node(it->first, it->second);
                node->next = data[index];
                data[index] = node;
                it++;
            }
        }

        std::string &operator[](std::string key){
            int index = hashFunction(key);
            Node* node = data[index];
            while(node != nullptr){
                if(node->key == key){
                    return node->value;
                }
                node = node->next;
            }
            return data[index]->value;
        }

        ~HashMap(){
            for(int i = 0; i < size; i++){
                delete data[i];
            }
            delete[] data;
        }
    
    private:
        Node** data;
        int size;

        /**
         * @brief DJB2 hash function
         * @param key can only be string
        */
        int hashFunction(std::string key){
            uint32_t hash = 5381;
            char c;
            for(int i = 0; i < key.length(); i++){
                c = key[i];
                hash = ((hash << 5) + hash) + c;
            }
            return hash % size;
        }

};

#endif