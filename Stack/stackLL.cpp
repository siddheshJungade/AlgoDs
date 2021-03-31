#include <iostream>
using namespace std;


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

class StackLinkedList
{
public:
    Node *top;

    StackLinkedList()
    {
        top = NULL;
    }
    StackLinkedList(Node *n)
    {
        top = n;
    }
    // 1. check if node exist using key
    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = top;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    // 2.prepand Node -Attach a Node at the top;
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


    void deleteNode()
    {
        if (top == NULL)
        {
            cout << "\n Empty list" << endl;
        }
        else
        {
                Node* temp = top;
                top = top->next;
                free(temp);
                cout << "\n value is deleted from stack Linked list" << endl;
        }
    }

    // 3.print list

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
            while (ptr != NULL)
            {
                cout << "(" << ptr->key << "," << ptr->data << ") -->";
                ptr = ptr->next;
            }
            cout << endl;
        }
    }


};

int main()
{
    StackLinkedList s;
    int key1, k1, data1;
    while (1)
    {

        cout << "1.prepend()" << endl;
        cout << "2.delete()" << endl;
        cout << "3.print()" << endl;

        Node *n1 = new Node();
        char option;
        cout << "\nEnter your choice :";
        cin >> option;
        switch (option)
        {
        case '1':
            cout << "enter yor data :"; cin >> data1;
            cout << "Enter Unique Key :" ; cin >> key1;
            n1->key = key1;
            n1->data = data1;
            s.prependNode(n1);
            break;

        case '2':
            s.deleteNode();
            break;
        case '3':
            s.printList();
            break;
        case '4':
            return 0;
            break;
        }
    }
}
