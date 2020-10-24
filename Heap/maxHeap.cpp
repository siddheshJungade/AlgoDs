#include <iostream>
#include <climits>
using namespace std;

class MaxHeap {
    int *heapArr;
    int heap_size;
    int capecity;
public:
    MaxHeap(int size);
    int parentNode(int i){ return (i-1)/2;}
    int leftChildNode(int i){ return (i*2)+1;}
    int rightChildNode(int i){ return (i*2)+2;}
    void maxHeapify(int i );
    int extractMax();
    int getMax() { return heapArr[0];};
    void incerase(int i , int new_val);
    void insertKey(int k);
    void deletekey(int k);
    void display();
};

MaxHeap::MaxHeap(int size) {
    heap_size = 0;
    heapArr = new int[capecity];
    capecity = size;
}

void MaxHeap::maxHeapify(int i){
    int left = leftChildNode(i);
    int right = rightChildNode(i);
    int largest = i;
    if(left < heap_size and heapArr[left] > heapArr[i])
        largest = left;
    if(right < heap_size and heapArr[right] > heapArr[i])
        largest = right;

    if(largest != i){
        swap(heapArr[largest],heapArr[i]);
        maxHeapify(largest);
    }    
}

void MaxHeap::insertKey(int k){
    if(heap_size == capecity)
        cout << "Heap is full \n";
    
    heap_size++;
    int i = heap_size-1;
    heapArr[i] = k;
    while(i != 0 and heapArr[parentNode(i)] <= heapArr[i]){
        swap(heapArr[parentNode(i)],heapArr[i]);
        i = parentNode(i);
    }
}

void MaxHeap::deletekey(int k) {
    incerase(k,INT_MAX);
    extractMax();
}

int MaxHeap::extractMax(){
    if(heap_size < 0)
        return INT_MIN;
    if (heap_size == 1 )
        return heapArr[0];
    
    int root = heapArr[0];
    heapArr[0] = heapArr[heap_size -1];
    heap_size--;
    maxHeapify(0);
    return root;
}

void MaxHeap:: incerase(int i , int new_val){
    heapArr[i] = new_val;
    while (heapArr[i] != 0 and heapArr[parentNode(i)] < heapArr[i]) {
        swap(heapArr[parentNode(i)],heapArr[i]);
        i = parentNode(i);
    }   
}

void MaxHeap::display() {
    cout << "heap elements are " << "\n";
    for (int i = 0; i < heap_size; i++)
        cout << heapArr[i] << " ";
    cout << "\n";
}


int main(){
    cout << "enetr Size of heap :";
    int size; cin >> size;
    MaxHeap h(size);
    while(1){
        cout << "------menu-----------" << "\n";
        cout << "1.insert"<<"\n";
        cout << "2.delete"<< "\n";
        cout << "3.extract max element" << "\n";
        cout << "4.get max element " << "\n";
        cout << "5.change element size" << "\n";
        cout << "6.deispaly"<<"\n";
        cout << "7.exit" << "\n" <<"-----";
        cout << "Enter your choice :";
        int c; cin >> c;   
        switch(c){
            case 1:
                int k; cin >> k;
                h.insertKey(k);
                break;
            case 2:
                cin >> k;
                h.deletekey(k);
                break;
            case 3:
                h.extractMax();
                break;
            case 4:
                cout << "min element is" <<h.getMax() << "\n" ;
                break;
            case 5:
                cin >> k;int new_val; cin >> new_val;
                h.incerase(k,new_val);
                break;
            case 6:
                h.display();
                break;
            case 7:
                return 0;
        }
    }
    return 0;
}