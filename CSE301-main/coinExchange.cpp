#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;

void print(vector<int>coins, int coin, int amount)
{
    if(!coin || !amount)
    return;

    if(dp[coin][amount]!=dp[coin-1][amount] && dp[coin][amount]!=dp[coin][amount-coins[coin-1]])
    {
        print(coins, coin-1, amount-coins[coin-1]);
        cout<<coins[coin-1]<<" ";
    }
    else
    print(coins, coin-1, amount);
}
int coinChange(vector<int>&coins, int coin, int amount)
{
    if(!coin)
    return amount;

    if(!amount)
    return 0;

    if(dp[coin][amount]!=INT_MAX)
    return dp[coin][amount];

    else if(coins[coin-1]>amount)
    {
        dp[coin][amount]=coinChange(coins, coin-1, amount);
    }
    else
    {
        dp[coin][amount]=min(coinChange(coins, coin-1, amount), 1+coinChange(coins, coin, amount-coins[coin-1]));
    }
    
    return dp[coin][amount];
}
int main()
{
    int coin, amount;
    cin>>coin;
    vector<int>coins(coin);
    for(int i=0; i<coin; i++)
    cin>>coins[i];
    cin>>amount;

    dp.assign(coin+1, vector<int>(amount+1, INT_MAX));
    
    cout<<coinChange(coins, coin, amount)<<endl;
    print(coins, coin, amount);
    return 0;
}
