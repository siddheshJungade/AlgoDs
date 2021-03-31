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
        if(rear == sizeof(arr)-1)   // it can be done as (rear == n-1) also
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
            rear++;
            cout<<"\n Enter value to be Insert = ";
            cin>>arr[rear];
        }

    }
    int deQueue() {
        if(isEmpty()) {
            cout<<"\n Queue is Empty"<<endl;
        }
        else {
            front++;
            cout<<"\n Queue is deQueue"<<endl;
        }

    }
    
    void print() {
        for(int i = front; i<=rear; i++)
                cout<<arr[i]<<"-->";
        cout<<endl;
    }
        
};

int main () {
    Queue s;
    int ch,pos;

    while (1)
    {
        printf("\n___________________Menu______________________________\n");
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

