#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& s, int num)
{
    while (num > 0)
    {
        cout << s[num] << " ";
        num -= s[num];
    }
    cout << endl;
}

int rod_cut(vector<int>& price, int n, vector<int>& s)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int j = 1; j <= n; j++)
    {
        int q = INT_MIN;
        for (int i = 0; i < j; i++)
        {
            if (q < price[i] + dp[j - i - 1])
            {
                q = price[i] + dp[j - i - 1];
                s[j] = i+1;
            }
        }
        dp[j] = q;
    }
    return dp[n];
}

int main()
{
    freopen("rod.txt", "r", stdin);
    int num, n;
    cin >> num;
    vector<int> price(num);
    vector<int> s(num + 1, -1);

    for (int i = 0; i < num; i++)
        cin >> price[i];

    cin >> n;

    if (n > num)
    {
        price.resize(n, 0);
        s.resize(n + 1, -1);
    }

    cout << rod_cut(price, n, s) << endl;
    print(s, n);
    return 0;
}
