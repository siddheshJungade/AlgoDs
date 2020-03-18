#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below
int main(int argc, char const *argv[])
{
    int arr[6][6], cal;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> arr[i][j];
        }
    }
    int result;
    bool flag = true;

    for (int i = 0; i < 6 - 2; i++)
    {
        for (int j = 0; j < 6 - 2; j++)
        {
            cal = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1] + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
            if (flag)
            {

                result = cal;

                flag = false;
            }

            if (result < cal)
            {
                result = cal;
            }
        }
    }

    cout << result;
}
