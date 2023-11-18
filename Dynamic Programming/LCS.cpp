#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;
vector<vector<char>>path;

void print_path(string &x, int i, int j)
{
    if (!i || !j)
        return;
    if (path[i][j] == '\\')
    {
        print_path(x, i - 1, j - 1);
        cout << x[i - 1] << " ";
    }
    else if(path[i][j] == '|')
    {
        print_path(x, i - 1, j);
    }
    else if (path[i][j] == '-')
    {
        print_path(x, i, j - 1);
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
                path[i][j]='\\';
            }
            else
            {
                if(dp[i-1][j]>=dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                    path[i][j]='|';
                }
                else
                {
                    dp[i][j]= dp[i][j-1];
                    path[i][j] = '-';
                }
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
    print_path(x, x.size(), y.size());
    cout<<endl;

    for(int i=0; i<=x.size(); i++)
    {
        for(int j=0; j<=y.size(); j++)
        {
            cout<<path[i][j]<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

// ABCBDAB
// BDCABA

/*

vector<vector<int>>dp;
vector<vector<int>>path;
dp.resize(m+1, vector<int>(n+1));


*/