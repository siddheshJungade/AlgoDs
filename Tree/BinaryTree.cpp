#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int key;
    Node *left;
    Node *right;
    Node *parent;

public:
    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    Node(int d)
    {
        data = d;
    }
    void setData(int d)
    {
        data = d;
    }
    int getData()
    {
        return data;
    }
};

class BinaryTree
{
private:
    Node *root;

public:
    BinaryTree() {
        root = NULL;
    }
    BinaryTree(Node *n) {
        root = n;
    }

    void insert(Node* n,int data) {
        if(root==NULL) {
            root = n;
            n->data = data;
            n->left = NULL;
            n->right = NULL; 
        }
        else 
        {
            Node *ptr = root;
            while(ptr != NULL )
            {
                if(ptr->left == NULL)
                    ptr = ptr->left;
                else
                    ptr = ptr->right;
                    
            }
            ptr->data = data;
        }
        
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
