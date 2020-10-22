#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class MinHeap
{
    int *heapArr;
    int capacity;
    int heap_size;

public:
    MinHeap(int size);
    void minHeapify(int i);
    void insertKey(int k);
    void deletekey(int k);
    void decreaseKey(int i, int new_val);
    int parentNode(int i) { return (i - 1) / 2; };
    int leftChildNode(int i) { return (i * 2) + 1; }
    int rightChildNode(int i) { return (i * 2) + 2; }
    int extractMin(); // extract root(minimum element);
    int getMin() { return heapArr[0]; }
    void display();
};

MinHeap::MinHeap(int size)
{
    heap_size = 0;
    capacity = size;
    heapArr = new int[capacity];
}

void MinHeap::minHeapify(int i)
{
    int l = leftChildNode(i);
    int r = rightChildNode(i);
    int smallest = i;
    if (l < heap_size and heapArr[l] < heapArr[i])
        smallest = l;
    else if (r < heap_size and heapArr[r] < heapArr[i])
        smallest = r;
    if (smallest != i)
    {
        swap(heapArr[i], heapArr[smallest]);
        minHeapify(smallest);
    }
}

void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << " !  Heap is full " << "\n";
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    heapArr[i] = k;
    while (i != 0 and heapArr[parentNode(i)] > heapArr[i])
    {
        swap(heapArr[parentNode(i)], heapArr[i]);
        i = parentNode(i);
    }
}

void MinHeap::deletekey(int k)
{
    decreaseKey(k, INT_MIN);
    extractMin();
}

void MinHeap::decreaseKey(int i, int new_val)
{
    heapArr[i] = new_val;
    while (heapArr[i] != 0 and heapArr[parentNode(i)] > heapArr[i])
    {
        swap(heapArr[parentNode(i)], heapArr[i]);
        i = parentNode(i);
    }
}

int MinHeap::extractMin()
{
    if (heap_size < 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return heapArr[0];
    }
    int root = heapArr[0];
    heapArr[0] = heapArr[heap_size - 1];
    heap_size--;
    minHeapify(0);
    return root;
}

void MinHeap::display()
{
    cout << "heap elements are " << "\n";
    for (int i = 0; i < heap_size; i++)
        cout << heapArr[i] << " ";
    cout << "\n";
}
int main(int argc, char const *argv[])
{
    cout << "enetr Size of heap :";
    int size; cin >> size;
    MinHeap h(size);
    while(1){
        cout << "------menu-----------" << "\n";
        cout << "1.insert"<<"\n";
        cout << "2.delete"<< "\n";
        cout << "3.extract min element" << "\n";
        cout << "4.get min element " << "\n";
        cout << "5.decrease element size" << "\n";
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
                h.extractMin();
                break;
            case 4:
                cout << "min element is" <<h.getMin() << "\n" ;
                break;
            case 5:
                cin >> k;int new_val; cin >> new_val;
                h.decreaseKey(k,new_val);
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
