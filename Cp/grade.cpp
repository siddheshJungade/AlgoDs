#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

vector<int> gradingStudents(vector<int> grades) {
    int n;cin>>n;
    int count = 0;
    for(int i = 0 ; i<n ;i++) {
        if(grades[i]>=40) { 
            while(grades[i]%5 == 0){
                count++;
                grades[i]++;
            }
            if(count<=2) {
                grades[i] = grades[i] - count;
            }
        }
    }
    return grades;
}

int main()
{
    vector<int > a;

}
