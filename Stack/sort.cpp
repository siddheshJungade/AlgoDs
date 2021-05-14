// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/


/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
    int x;
    if(!s.empty()){
        x = s.top();
        s.pop();
        sort();
    }
    stack<int> temp;
    if(s.empty() or x > s.top())
        s.push(x);
    else {
        while(x < s.top()){
            temp.push(s.top());
            s.pop();
        }
        s.push(x);
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
    }
   //Your code here
}

