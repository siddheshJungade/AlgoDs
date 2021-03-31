#include<iostream>
#include<algorithm>
using namespace std;

int partationFunction(int a[],int top , int end , int pivit) {
	int smale_ele_i = top;
	for(int j = top ; j < end ; j++) {
		if(a[j] < pivit){
			swap(a[smale_ele_i],a[j]);
			smale_ele_i++;
		}
	}
	swap(a[smale_ele_i],a[end]);
	return smale_ele_i;
}
void quickSort(int a[] , int top , int end){
		
		if(top < end){
			int pivit = a[end];
			int partation = partationFunction(a,top,end,pivit);
			quickSort(a ,top ,partation - 1);
			quickSort(a , partation+1,end);
		}
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int A[n];

    for (int i = 0; i < n; i++)
        cin >> A[i];

    quickSort(A,0, n - 1);
    
    for (int i = 0; i < n; i++)
        cout <<"\t"<< A[i] <<"\t";
}