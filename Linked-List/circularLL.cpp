#include <iostream>
#include <stdlib.h>
using namespace std;

/* code is for circular linked-list */

class Node
{
public:
    int key;
    int data;
    Node *next;

    Node()
    {
        data = 0;
        key = 0;
        next = NULL;
    }
    Node(int d, int k)
    {
        key = k;
        data = d;
    }
};

class CircularLinkedList
{
public:
    Node *top;

    CircularLinkedList()
    {
        top = NULL;
    }
    CircularLinkedList(Node *n)
    {
        top = n;
    }
    // 1. check if node exist using key
    Node* nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = top;
        if (ptr == NULL)
        {
            return temp;
        }
        else
        {
            do
            {
                if (ptr->key == k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            } while (ptr != top);
            return temp;
        }
    }

    // 2 append a node to the list

    void appendNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "\n @@@@Node exist@@@" << endl;
        }
        else
        {
            if (top == NULL)
            {
                top = n;
                top->next = top;
                cout << "\nnode appented LINKED LIST is created" << endl;
            }
            else
            {
                Node *ptr = top;
                while (ptr->next != top)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->next = top;

                cout << "\nNode appented" << endl;
            }
        }
    }

    // 3.prepand Node -Attach a Node at the top;
    void prependNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "\n @@@@Node exist@@@" << endl;
        }
        else
        {
            n->next = top;
            top = n;
        }
    }

    // 4. Insert a Node aftrer particular node
    void atPosition(int k, Node *n)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {

            cout << "\n @@@@Node not exist@@@" << endl;
        }
        else
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "\n @@@@Node exist@@@" << endl;
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
            }
        }
    }

    void deleteNode(int k)
    {
        if (top == NULL)
        {
            cout << "\n Empty list" << endl;
        }
        else
        {
            if (top->key == k)
            {
                Node *temp = top;
                top = top->next;
                free(temp);
                cout << "\n Node Unlinked with key value :" << k << endl;
            }
            else
            {
                Node *prevPtr = top;
                Node *temp = NULL;
                Node *currentPtr = top->next;

                while (prevPtr->key != k)
                {
                    temp = prevPtr;
                    prevPtr = prevPtr->next;
                }
                if (temp != NULL)
                {
                    temp->next = prevPtr->next;
                    temp = prevPtr;
                    free(temp);
                }
            }
        }
    }

    // 6.print list

    void printList()
    {
        if (top == NULL)
        {
            cout << "\nNode doesnot exist" << endl;
        }
        else
        {
            cout << endl
                 << "singly Linked List Values :";
            Node *ptr = top;
            while (ptr->next != top)
            {
                cout << "(" << ptr->key << "," << ptr->data << ") -->";
                ptr = ptr->next;
            }
            cout << "(" << ptr->key << "," << ptr->data << ") -->";

            cout << endl;
        }
    }
};

int main()
{
    CircularLinkedList s;
    int key1, k1, data1;
    while (1)
    {

        cout << "1.append()" << endl;
        cout << "2.prepend()" << endl;
        cout << "3.insert()" << endl;
        cout << "4.delete()" << endl;
        cout << "5.print()" << endl;

        Node *n1 = new Node();
        char option;
        cout << "\nEnter your choice" << endl;
        cin >> option;
        switch (option)
        {
        case '1':
            cout << "enter yor data :" << endl;
            cin >> data1;
            cin >> key1;
            n1->key = key1;
            n1->data = data1;
            s.appendNode(n1);
            break;

        case '2':
            cout << "enter yor data :" << endl;
            cin >> data1;
            cin >> key1;
            n1->key = key1;
            n1->data = data1;
            s.prependNode(n1);
            break;

        case '3':
            cout << "enter key which is in list : ";
            cin >> k1;
            cout << "enter data : ";
            cin >> data1;
            cout << "Enter key : ";
            cin >> key1;
            n1->key = key1;
            n1->data = data1;
            s.atPosition(k1, n1);
            break;

        case '4':
            cout << "enter a key to delete :";
            cin >> k1;
            s.deleteNode(k1);
            break;
        case '5':
            s.printList();
            break;
        case '6':
            return 0;
            break;
        }
    }
}
