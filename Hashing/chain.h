#ifndef Chains_h
#define Chains_h
#include<iostream>
using namespace std;
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void SortedInsert(struct Node **H, int x)
{
    struct Node *t, *q = NULL, *p = *H;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (*H == NULL)
        *H = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == *H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}
struct Node *Search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void Delete(struct Node *p , int key){
    struct Node *temp = p;
    while (p != NULL)
    {
        if (key == p->data)
            break;

        temp = p;
        p = p->next;
    }
    if(temp != NULL and p != NULL){
        temp->next = p->next;
        delete p;
    } else 
        cout << "NO Element Found \n" ;
}
#endif /* Chains_h */