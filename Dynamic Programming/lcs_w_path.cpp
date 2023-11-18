#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;
vector<vector<char>>path;

void print_path(string &x, string &y, int i, int j)
{
    if (!i || !j)
        return;
    if (x[i-1]==y[j-1])
    {
        print_path(x, y, i - 1, j - 1);
        cout << x[i - 1] << " ";
    }
    else if(dp[i][j]==dp[i-1][j])
    {
        print_path(x, y, i - 1, j);
    }
    else
    {
        print_path(x, y, i, j - 1);
    }
}

int lcs(string x, string y)
{
    int m=x.size(), n=y.size();
    dp.resize(m+1, vector<int>(n+1));
    path.resize(m+1, vector<char>(n+1));

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(!i || !j)
                dp[i][j]=0;
            else if(x[i-1]==y[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
int main()
{
    string x,y;
    cin>>x>>y;
    int res = lcs(x,y);
    cout<<res<<endl;
    print_path(x, y, x.size(), y.size());
    return 0;
}