#include <bits/stdc++.h>
using namespace std;
#define mx 100
struct rod{
    int len, price;
}rods[100];

vector<int>dp(mx, -1);
int q;
int rod_cut(struct rod rods[], int n)
{
    if(dp[n]>0)
    return dp[n];
    if(n==0)
    dp[n]=0;
    else
    {
        q=INT_MIN;
        for(int i=0; i<n; i++)
            q = max(q, rods[i].price+rod_cut(rods, n-i-1, dp));
    }
    dp[n]=q;
    return dp[n];
}
int main() {
    //freopen("rod.txt", "r", stdin);
    int n,num;
    cin>>num;
    for(int i=0; i<num; i++)
    {
        cin>>rods[i].len>>rods[i].price;
    }
    cin>>n;
    int res=rod_cut(rods, n);
    cout<<res;
    return 0;
}
