#include<iostream>
#include<string>
#include<stack>
using namespace std;

int presedence(char x){
     if(x == '+' or x == '-')
        return 1;
    else if(x == '/' or x == '*')
        return 2;
    return 0;
}
bool isOperand(char x){
    if(x == '+' or x == '-' or x == '/' or x == '*')
        return false;
    else return true;
}

string convert(string s){
    stack<char> st;
    string postfix;
    int i = 0 ; 
    while(s[i] != '\0'){
        if(isOperand(s[i])){ 
            postfix += s[i]; 
            i++;
        } else {
            if(st.empty() or presedence(s[i]) > presedence(st.top()) ){
                st.push(s[i]);
                i++;
            } else {
                    postfix += st.top();
                    st.pop();
            }
        }
    }
    while(not st.empty()){
        postfix += st.top();
        st.pop();
    }
    return postfix;
}
int results(int a , int b , char opr){
    switch (opr)
    {
    case '+': return a+b;
            break;
    case '-': return a-b;
            break;
    case '/': return a/b;
            break;
    case '*': return a*b;
            break;
    default: cout << "Error ocers" << endl;
        break;
    }
}
int Eval(string ans){
    stack<char> s;
    int a ,b ,r;
    for(int i = 0 ; ans[i] != '\0' ; i++){
        if(isOperand(ans[i]))
            s.push(ans[i]);
        else {
            b = (int)s.top()-'0'; s.pop();
            a = (int)s.top()-'0'; s.pop();
            r = results(a,b,ans[i]);
            s.push(r + '0');
        }
    }
    return s.top() - '0';
}

int main(int argc, char const *argv[])
{
    string s; cin >> s;
    string ansString = convert(s); 
    cout << ansString << "\n";
    cout << Eval(ansString);
    return 0;
}
