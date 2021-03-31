#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node {
    int data;
    struct Node *next;
}
*front = NULL , *rear = NULL ;
void enqueue(int x){
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
        cout << "Queue is Full \n";
    else {
        t->data = x;
        t->next = NULL ;
        if(front == NULL)
            front = rear = t;
        else {
            rear->next = t;
            rear = t;
        }
    }
}
void deQueue(){
    int x = -1;
    struct Node *t;
    if(front == NULL)
        cout << "Queue is empty";
    else{
        x = front->data;
        t= front;
        front = front->next;
        delete t;
    }
    cout << x << " is deleted" << "\n";
}
void Display(){
    struct Node *p = front;
    while(p){
        cout << p->data << "-->";
        p = p->next;
    }
    cout << "\n";
}
int main(int argc, char const *argv[])
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    Display();
    deQueue();
    Display();
    
    return 0;
}
