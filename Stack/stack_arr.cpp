#include <iostream>
using namespace std;

class Stack
{
public:
#define Max 5

    int a[Max], top = -1;

    void push(int data)
    {
        if (top == Max-1)
        {
            cout << "\nStack is full" << endl;
        }
        else
        {
            top++;
            a[top] = data;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "\nlist is empty" << endl;
        }
        else
        {
            top--;
        }
    }
    int print()
    {
        cout << "Stack is" << endl;
        for (int i = Max; i >= 0; i--)
        {
            cout << "-----------" << a[i] << "---------------" << endl;
        }
    }
} ;

int main()
{
    Stack s;
    int ch, data;
    printf("1.push or Incert\n");
    printf("2.pop\n");
    printf("3.display\n");
    printf("4.end\n");

    while (1)
    {
        printf("->>Enter choice =");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            cout << "\nEnter data :";
            cin >> data;
            s.push(data);
            break;
        }
        case 2:
        {
            s.pop();
            break;
        }
        case 3:
        {
            s.print();
            break;
        }
        case 4:
        {
            return 0;
        }
        default:
        {
            printf("wrong choice");
        }
        }
    }
}