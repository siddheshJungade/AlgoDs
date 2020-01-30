#include <iostream>
#include <string>
using namespace std;

// int main() {
//     string name;
//     cin>>name;
    
//     int length = name.length();
//     for(int i=0;i<=length-1;i++)
//     {
//         int count = 0;
//         int itr = length-1;
//         while(itr>=0)
//         {
//             if(name[i]==name[itr])
//                 count = count+1; 
        
//             itr--;   
//         }
//         cout<<"Number of occurrence of "<<name[i]<<" is:"<<count<<endl;
        
//     }
// 	return 0;
// }

int main()
{
    int n; cin>>n;
    char str[n];
   for(int i = 0 ;i<n ; i++)
   {
       cin>>str[i];
   }
   cout<<str;
}