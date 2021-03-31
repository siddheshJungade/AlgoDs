#include <iostream>
#include "chain.h"
using namespace std;


int Hash(int key)
{
    return key % 10;
}
void insert(struct Node *HT[], int key)
{
    int index = Hash(key);
    SortedInsert(&HT[index], key);
}

int main(int argc, char const *argv[])
{
    struct Node *HT[10];

    for (int i = 0; i < 10; i++)
        HT[i] = NULL;

    while (1)
    {
        cout << "---------------Card------------------\n";
        cout << "1. Insert" << "\n";
        cout << "2. Search" << "\n";
        cout << "3. Delete" << "\n";
        cout << "4. Exit" << "\n";
        cout << "Enter Your Choice :";
        char choice;
        cin >> choice;

        switch (choice)
        {
        case '1':
            cout << "NO of elements to insert :";
            int n;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int input;
                cin >> input;
                insert(HT, input);
            }
            break;
        case '2':
        {
            try
            {
                cout << "Enter element you want to Search :";
                int s;
                cin >> s;
                struct Node *search = Search(HT[Hash(s)], s);
                if (search == NULL)
                    throw search;
                cout << search->data << "\n";
            }
            catch (struct Node *e)
            {
                cout << "\n Value not Found " << endl;
            }
            break;
        }
        case '3':
                cout << "Enter element you want to Deleted :";
                int s;
                cin >> s;
                Delete(HT[Hash(s)],s);
                break;
        case '4': return 0;
                  break;
        }
        
    }

    return 0;
}
