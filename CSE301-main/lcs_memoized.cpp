#include<bits/stdc++.h>
using namespace std;
#define mx 100

vector<vector<int>>dp;
vector<vector<char>>path;

/*void print_path(string &x, int i, int j)
{
    if (!i || !j)
        return;
    if (path[i][j] == '\\')
    {
        print_path(x, i-1, j-1);
        cout<<x[i-1];
    }
    else if(path[i][j] == '|')
    {
        print_path(x, i-1, j);
    }
    else if (path[i][j] == '-')
    {
        print_path(x, i, j-1);
    }
}*/

void print_path_2(string &x, string &y, int i, int j)
{
    if(!i || !j)
    return;

    else if(x[i-1]==y[j-1])
    {
        print_path_2(x, y, i-1, j-1);
        cout<<x[i-1];
    }
    else if(dp[i-1][j]>dp[i][j-1])
    print_path_2(x, y, i-1, j);
    else
    print_path_2(x, y, i, j-1);
}

int lcs(string &x, string &y, int i, int j)
{
    if(dp[i][j]!=INT_MIN)
    return dp[i][j];

    if(!i || !j)
        dp[i][j] = 0;

    else if(x[i-1]==y[j-1])
    {
        dp[i][j] = lcs(x, y, i-1, j-1)+1;
    }
    else
    {
        dp[i][j] = max(lcs(x,y,i-1,j), lcs(x,y,i,j-1));
    }
    return dp[i][j];
}

int main()
{
    string x,y;
    cin>>x>>y;
    int m=x.size(), n=y.size();
    dp.assign(m+1, vector<int>(n+1, INT_MIN));

    cout<<lcs(x,y,m,n)<<endl;
    print_path_2(x,y,m,n);

    return 0;
}
