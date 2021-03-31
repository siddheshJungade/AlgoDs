#include<iostream>
#include<stack>
using namespace std;
stack<char> st;

void insertAtBottom(int x) {
    if(st.size() > 0){
        int topInStack = st.top();
        st.pop();
        insertAtBottom(x);
        st.push(topInStack);
    }
}

void reverse() {
    if(st.empty())
        return;
    else {
        int x = st.top();
        st.pop();
        reverse();
        insertAtBottom(x);
    }
}

int main() {
    st.push('1');
    st.push('2');
    st.push('3');
    st.push('4');
    
    reverse();
    
    while(!st.empty()) 
    { 
        cout << st.top() << "\n";
        st.pop(); 
    } 
}