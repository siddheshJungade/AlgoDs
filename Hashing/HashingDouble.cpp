#include<iostream>
using namespace std;
#define SIZE 10
int Hash(int key){
    return key % SIZE;
}
int probe(int HT[],int key){
    int index = Hash(key);
    int i = 0 ;
        while(HT[(index+i) % SIZE] != 0 )
            i++;
    return (index+i)%SIZE;
}
void Insert(int HT[],int key){
    int index = Hash(key);
    if(HT[index] != 0){
        index = probe(HT,key);
    }
    HT[index] = key;
}
int search(int HT[],int key){
    int index = Hash(key);

    int i = 0 ; 
    while(HT[(index+i) % SIZE] != key)
        i++;
    return (index+i) % SIZE ;
}
int main(int argc, char const *argv[])
{
    int HT[10] = {0};
    Insert(HT,12);
    Insert(HT,32);
    Insert(HT,51);
    Insert(HT,24);
    cout << search(HT , 32) << endl;
    return 0;
}
