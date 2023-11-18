#include<bits/stdc++.h>
using namespace std;

int chocoCut(vector<vector<int>>choco, int m, int n)
{
    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int maxRev = INT_MIN;

            for(int k=1; k<i; k++)
            maxRev = max(maxRev, dp[k][j]+dp[i-k][j]);

            for(int k=1; k<j; k++)
            maxRev = max(maxRev, dp[i][k]+dp[i][j-k]);

            dp[i][j] = maxRev+choco[i-1][j-1];
        }
    }
    return dp[m][n];
}
int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>>choco(m, vector<int>(n));
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        cin>>choco[i][j];
    }
    cout<<chocoCut(choco, m,n);
    return 0;
}
