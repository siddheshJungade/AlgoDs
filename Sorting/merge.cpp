#include<iostream>
using namespace std;

int merge(int a[],int top , int mid , int end) {
	int left = mid - top + 1;
	int right = end - mid ;
	int arr_left[left] , arr_right[right];
	
	for(int i = 0 ; i < left ; i++)
		arr_left[i] = a[top + i];
	for(int i = 0 ; i < right ; i++)
		arr_right[i] = a[mid + 1 + i];
	
	int i = 0;
	int j = 0 ; 
	int k = top;
	while(i < left and j < right) {
		if(arr_left[i] < arr_right[j]){
			a[k] = arr_left[i];
			i++;k++;
		} else {
			a[k] = arr_right[j];
			j++;k++;
		}		
	}
	while(i < left){
		a[k] = arr_left[i];
		i++;k++;
	}
	while(j < right) {
		a[k] = arr_right[j];
		j++;k++;
	}
}
void mergeSort(int a[] , int top , int end){
		if(top < end){
			int mid = (top + end) / 2;
			mergeSort(a,top,mid);
			mergeSort(a,mid+1,end);
			merge(a,top,mid,end);
		}
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int A[n];

    for (int i = 0; i < n; i++)
        cin >> A[i];

    mergeSort(A,0, n - 1);
	
    for (int i = 0; i < n; i++)
        cout <<"\t"<< A[i] <<"\t";
}