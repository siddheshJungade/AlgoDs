#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n ; cin >> n; 
    vector<int> arr(n);
    unordered_map<int,int> map;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        map[arr[i]]++;
    }
    for(auto it : map){
        if(it.second == 1)
            cout << it.first << " ";
    }
    return 0;
}   
