#ifndef LINKEDLIST_H
#define LINKEDLIST_H

enum Scene
{
    Login = 0,
    Main_SV,
    Main_GV,
    Exit
};

template <class type>
class LinkedList
{
    public:
        struct Node
        {
            type data;
            Node *next;

            Node(type data)
            {
                this->data = data;
                this->next = nullptr;
            }
        };

        LinkedList()
        {
            head = nullptr;
            tail = nullptr;
        }

        ~LinkedList()
        {
            for (Node *temp = head; temp != nullptr; temp = head)
            {
                head = head->next;
                delete temp;
            }
        }

        void push_back(type data)
        {
            Node *temp = new Node(data);
            if (head == nullptr)
            {
                head = tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }

        void pop_back()
        {
            if (head == nullptr)
            {
                return;
            }
            else if (head == tail)
            {
                delete head;
                head = tail = nullptr;
            }
            else
            {
                Node *temp = head;
                while (temp->next != tail)
                {
                    temp = temp->next;
                }
                delete tail;
                tail = temp;
                tail->next = nullptr;
            }
        }

        type &back()
        {
            return tail->data;
        }

    private:
        Node *head;
        Node *tail;
};

#endif