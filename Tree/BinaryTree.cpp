#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *left;
    Node *right;

public:
    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    Node(int d)
    {
        data = d;
    }
    void setData(int d)
    {
        data = d;
    }
    void getData()
    {
        return data;
    }
}

class BinaryTree
{
private:
    Node *root;

public:
    void setData(int d)
    {
        root.setData(int d)
    }
}

int
main(int argc, char const *argv[])
{

    return 0;
}
