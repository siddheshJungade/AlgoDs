    int maxDivide(int a, int b)
    {
        while (a % b == 0)
            a = a / b;
        return a;
    }

    // Function to check if a number is ugly or not
    int isUgly(int no)
    {
        no = maxDivide(no, 2);
        no = maxDivide(no, 3);
        no = maxDivide(no, 5);

        return (no == 1) ? 1 : 0;
    }
    ull getNthUglyNo(int n)
    {
        ull dp[n + 1];
        dp[0] = 1;
        ull j = 2;
        ull i = 1;
        while (i <= n)
        {
            if (isUgly(j))
            {
                dp[i] = j;
                cout << dp[i] << " ";
                i++;
            }
            j++;
        }
        return dp[n - 1];
        // code here
    }