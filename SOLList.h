#pragma once
#include <cstddef>
#include<iostream>
#include"SOLListNode.h"
using namespace std;
template <class DT>
class SOLList {

public:
    // Constructor & Copy constructor
    SOLList()
    {
        head = nullptr;
        tail = nullptr;
    }
    SOLList(const SOLList<DT>& oldList)
        :head(oldList->head), tail(oldList->tail)
    {
        SOLListNode<DT>* newHead;
        newHead = oldList->head;
    }
    // Destructor
    ~SOLList()
    {
        if (!isEmpty())
        {
            SOLListNode<DT>* current{ head };
            SOLListNode<DT>* temp{ nullptr };
            while (current != nullptr)
            {
                temp = current;
                current = current->next;
                delete temp;
            }
        }
        cout << "\nList has been deleted.\n";
    }

    void insert(const DT& newData) 
    {

        SOLListNode<DT>* newNode{ getNewNode(newData) };

        if (isEmpty())
        {
            head = tail = newNode;
            return;
        }

        SOLListNode<DT>* temp = head;
        SOLListNode<DT>* temp2 = nullptr;
        while (temp->next != nullptr)
        {
            if (temp->data == newData)
            {
                return;
            }
            else
            {
                if (temp != nullptr)
                {
                    temp2 = temp;
                    temp = temp->next;
                }
            }
        }
        temp->next = newNode;

    }

    //The operation showSOLL prints the values in the self-organizing nexted list in a nexted list
    //form.
    void ShowSOLL()
    {
        SOLListNode<DT>* temp = head;

        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        cout << "List: ";

        while (temp != nullptr)
        {
            cout << temp->data;
            if (temp->next != nullptr)
            {
                cout << " ";
            }
            temp = temp->next;
        }
        cout << "\n";
    }

    //linear search using the move-to-front self-organizing heuristic
    bool search_mtf(const DT& key)
    {
        SOLListNode<DT>* temp = head;
        SOLListNode<DT>* previous = nullptr;
        bool found = false;

        while (temp != nullptr && found == false)
        {
            if (temp->data == key)
            {
                if (temp == head)
                {
                    found = true;
                }
                else if (previous != nullptr && temp != nullptr)
                {
                    previous->next = temp->next;
                    temp->next = head;
                    head = temp;
                    found = true;
                }
            }
            else
            {
                previous = temp;
                temp = temp->next;
            }
        }
        return found;
    }

    //linear search using the transpose self - organizing heuristic
    bool search_t(const DT& key)
    {
        SOLListNode<DT>* temp = head;
        SOLListNode<DT>* previous = nullptr;
        SOLListNode<DT>* previous2 = nullptr;

        bool found = false;

        while (temp != nullptr && found == false)
        {
            if (temp->data == key)
            {
                if (previous == head)
                {
                    if (previous != nullptr && temp != nullptr)
                    {
                        previous->next = temp->next;
                        temp->next = previous;
                        head = temp;
                    }
                }
                else
                {
                    if (previous != nullptr && temp != nullptr)
                    {
                        previous->next = temp->next;
                    }
                    if (temp != nullptr && previous2 != nullptr)
                    {
                        temp->next = previous2->next;
                        previous2->next = temp;
                    }
                }

                found = true;
            }
            else
            {
                previous2 = previous;
                previous = temp;
                temp = temp->next;
            }
        }
        return found;
    }

    //linear search using no self-organizing heuristic
    bool search(const DT& key)
    {
        SOLListNode<DT>* temp = head;
        SOLListNode<DT>* previous = nullptr;
        bool found = false;

        while (temp != nullptr && found == false)
        {
            if (temp->data == key)
            {
                found = true;
            }
            else
            {
                previous = temp;
                temp = temp->next;
            }
        }
        return found;
    }

    bool isEmpty()
    {
        return (head == nullptr);
    }

private:
    SOLListNode<DT>* head{};
    SOLListNode<DT>* tail{};

    SOLListNode<DT>* getNewNode(const DT& newData)
    {
        return new SOLListNode<DT>{ newData };
    }
};;