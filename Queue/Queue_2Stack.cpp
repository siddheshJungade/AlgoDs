#include<iostream>
#include<stack>
using namespace std;

stack<int> e_stk;
stack<int> d_stk;

void enque(int x){
    e_stk.push(x);
}
void deQueue(){
    if(!d_stk.empty()){
        cout << d_stk.top() << " ";
        d_stk.pop();
    } else {
        while(!e_stk.empty()){
            d_stk.push(e_stk.top());
            e_stk.pop();
        }
        cout << d_stk.top() << " ";
        d_stk.pop();
    }
}

int main() 
{
    enque(10);
    enque(20);
    enque(30);
    enque(40);
    deQueue();
    deQueue();
}