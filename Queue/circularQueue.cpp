#include<iostream>
using namespace std;

class Queue {

private:
    int front,rear,n;
    int* arr;

public:
    Queue() {
        front = -1; 
        rear = -1;
        cout<<"Enter number of Elements"<<endl;
        cin>>n;
        arr = new int[n];
        for (int i = 0 ;i <= n-1 ;i++) {
            arr[i] = 0;
        }
    }
    
    bool isEmpty() {
        if(front == -1 && rear == -1) 
            return true;
        else
            return false;    
    }

    bool isFull() {
        if( ((rear+1)%n) == front )   // we can write front == rear+1 but we need to code some mor condition for satisfing n-1 condition
            return true;
        else
            return false;    
    }

    int enQueue() {
        if(isFull()) {
            cout<<"\n Queue is Full"<<endl;
        }
        else if(rear == -1) {
            rear++;
            front++;
            cout<<"\n Enter value to be Insert = ";
            cin>>arr[rear];
        }
        else {
            rear = (rear+1)%n;
            cout<<"\n Enter value to be Insert = ";
            cin>>arr[rear];
        }

    }
    int deQueue() {
            if(isEmpty()) {
                cout<<"\n Queue is Empty"<<endl;
            }
            else if(front == rear) {
                front = -1;
                rear = -1;
                cout<<"\n Queue is deQueue"<<endl;
            }
            else {
                front = (front+1)%n;
                cout<<"\n Queue is deQueue"<<endl; 
            }
        }

    
    
    void print() {
        int i = front;
        while(i != rear) {
            cout<<arr[i]<<"-->";
            i = (i+1) % n;
        } ;
        cout<<arr[rear];
        cout<<endl;
    }
    
        
};

int main () {
    Queue s;
    int ch,pos;

    while (1)
    {
        printf("\n_________________________Menu______________________________\n");
        printf("1.EnQueuet\n");
        printf("2.DeQueue\n");
        printf("3.isEmpty()\n");
        printf("4.display\n");
        printf("5.Clear Screen\n");
        printf("6.Exit\n");
        printf("-------------------------\nEnter choice = ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: {
                s.enQueue();
                break;
            }
            case 2: {
                s.deQueue();
                break;
            }
            case 3: {
                cout<<s.isEmpty()<<endl;
                break;
            }
            case 4: {
                s.print();
                break;
            }
            case 5: {
                system("clear");
                break;
            }
            case 6: {
                return 0;
                break;
            }
            default:
            {
                printf("wrong choice");
            }
        }
    }

}

