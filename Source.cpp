#include <cstddef>
#include<iostream>
using namespace std;

template <class DT>
class SOLListNode
{
public:
    DT data;
    SOLListNode<DT>* next;

    SOLListNode() {}
    SOLListNode(const DT& newData, SOLListNode<DT>* link)
    {
        data = newData;
        next = link;
    }
};

template <class DT>
class SOLList {

public:
    // Constructor & Copy constructor
    SOLList()
    {
        head = NULL;
    }
    SOLList(const SOLList<DT>& oldList)
    {
        SOLListNode<DT>* newHead;
        newHead = oldList->head;
    }
    // Destructor
    ~SOLList()
    {
        SOLListNode<DT> *temp;
        while (head != NULL)
        {
            temp = head->next;
            delete head;
            head = temp;
        }
    }

    void insert(const DT &newData)
    {
        SOLListNode<newData, head->next> newNode;

        SOLListNode<DT>* temp = NULL;

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        while (head->next != NULL)
        {
            if (head->data == newData)
            {
                return;
            }
            else
            {
                if (temp != NULL && newNode != NULL)
                {
                    temp->next = newNode->next;
                }
                newNode = newNode->next;
            }
        }
        newNode->next = NULL;
        head->next = newNode;

    }

    //The operation showSOLL prints the values in the self-organizing linked list in a linked list
    //form.
    void ShowSOLL()
    {
        SOLListNode<DT>* temp = head;

        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        // temporary pointer pointing to head 

        cout << "List: ";

        while (temp != NULL)
        {
            cout << temp->data;
            if (temp->next != NULL)
            {
                cout << " ";
            }
            temp = temp->next;
        }
        cout << "\n\n";
    }

    //linear search using the move-to-front self-organizing heuristic
    bool search_mtf(const DT &key)
    {
        SOLListNode<DT>* temp = head;
        SOLListNode<DT>* previous = NULL;
        bool found = false;

        while (temp != NULL && found == false)
        {
            if (temp->data == key)
            {
                if (previous != NULL && temp != NULL)
                {
                    previous->next = temp->next;
                }
                temp->next = head;
                head = temp;
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

    //linear search using the transpose self - organizing heuristic
    bool search_t(const DT& key)
    {
        SOLListNode<DT>* temp = head;
        SOLListNode<DT>* previous = NULL;
        SOLListNode<DT>* previous2 = NULL;

        bool found = false;

        while (temp != NULL && found == false)
        {
            if (temp->data == key)
            {

                if (previous != NULL && temp != NULL)
                {
                    previous->next = temp->next;
                }
                if (temp != NULL && previous2 != NULL)
                {
                    temp->next = previous2->next;
                }

                found = true;
            }
            else
            {
                if (previous != NULL)
                {
                    previous2 = previous;
                }
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
        SOLListNode<DT>* previous = NULL;
        bool found = false;

        while (temp != NULL && found == false)
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

private:
    SOLListNode<DT>* head;
};



//The insert operation scans the entire list to verify that the item is not already present and
//then inserts the item at the end of the list.


int main()
{
    cout << "Test cases\n";

    SOLList< char > list;
    list.insert('E');
    list.ShowSOLL();

}