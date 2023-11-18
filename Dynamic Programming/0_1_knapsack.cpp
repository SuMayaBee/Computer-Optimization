#include<bits/stdc++.h>
#define mx 100
using namespace std;

struct item{
    int weight;
    int value;
}items[100];

int dp[mx][mx];
void knapsack(int n, int W)
{
    for(int i=0; i<=n; i++)
    {
        for(int w=0; w<=W; w++)
        {
            if(!i || !w)
                dp[i][w]=0;
            else if(items[i-1].weight>w)
                dp[i][w] = dp[i-1][w];
            else
                dp[i][w] = max(items[i-1].value+dp[i-1][w-items[i-1].weight], dp[i-1][w]);
        }
    }

    for(int i=0; i<=n; i++)
    {
        for(int w=0; w<=W; w++)
            cout<<dp[i][w]<<" ";
        cout<<endl;
    }
}

void print(int i, int w)
{
    if (i==0 || w==0)
        return;
    if (items[i-1].weight<=w && dp[i][w]==items[i-1].value+dp[i-1][w-items[i-1].weight])
    {
        print(i-1, w-items[i-1].weight);
        cout<<"item: "<<i<<endl;
    }
    else
    print(i-1, w);
}

int main()
{
    //freopen("0/1knapsack.txt", "r", stdin);
    int n,W;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>items[i].weight>>items[i].value;
    cin>>W;
    knapsack(n, W);
    print(n,W);
    return 0;
}

/*

4
2 12
1 10
3 20
2 15
5

*/