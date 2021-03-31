#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    int key;
    Node *next;

    Node()
    {
        prev = NULL;
        data = 0;
        key = 0;
        next = NULL;
    }
    Node(int d, int k)
    {
        data = d;
        key = k;
    }
};

class DoublyLL
{
private:
    Node *top = NULL;

public:
    DoublyLL()
    {
        top = NULL;
    }
    DoublyLL(Node *n)
    {
        top = n;
    }

    // Node exist or not ??

    Node *nodeExist(int k)
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

    // 1.insert Node

    void appendNode(Node *n)
    {
        if (nodeExist(n->key) != NULL)
            cout << "\nNode Exist" << endl;
        else
        {
            if (top == NULL)
            {
                top = n;
                cout << "\ndoubaly LL IS CREATED" << endl;
            }
            else
            {
                Node* ptr = top;

                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->prev = ptr;
                cout<<"\nNode appended"<<endl;
            }
        }
    }

    void prependNode(Node *n)
    {
        if (nodeExist(n->key) != NULL)
            cout << "\nNode Exist" << endl;
        else
        {
            if (top == NULL)
            {
                top = n;
                cout << "\n LL is created" << endl;
            }
            else
            {
                n->next = top;
                top->prev = n;
                top = n;
            }
        }
    }

    // 3. at given position

    void atPosition(int k, Node *n)
    {
        Node *key_exist = nodeExist(k);

        if (key_exist == NULL)
        {
            cout << "\n key dosent exist" << endl;
        }
        else
        {
            if (nodeExist(n->key) != NULL)
                cout << "\nnode Exist" << endl;
            else
            {
                Node *ptr = top;

                while (ptr->key != k)
                    ptr = ptr->next;

                n->next = ptr->next;
                n->prev = ptr;
                ptr->next = n;
            }
        }
    }

    //  4. delete Node

    void deleteNode(int k)
    {
        if (nodeExist(k) == NULL)
            cout << "\nnode not exist" << endl;

        else
        {
            Node *ptr = top;
            Node *temp;
            Node *nextNode;
            while (ptr->key != k)
            {
                ptr = ptr->next;
            }

            temp = ptr->prev;
            nextNode = ptr->next;

            temp->next = nextNode;
            nextNode->prev = temp;

            free(ptr);
        }
    }

    // print list

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
                cout << "<--(" << ptr->key << "," << ptr->data << ") -->";
                ptr = ptr->next;
            }
            cout << endl;
            while(ptr != NULL )
            {
               cout << "<--(" << ptr->key << "," << ptr->data << ") -->";
               ptr = (*ptr).prev; // access data member syntax in C++ same as ptr->prev 
            }
            cout<< endl;
        }
    }
};

int main()
{
    DoublyLL s;
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
