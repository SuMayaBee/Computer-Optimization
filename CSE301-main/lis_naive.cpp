#include<bits/stdc++.h>
using namespace std;

void print_sol(vector<int>&prev, vector<int>&num, int i)
{
    if(prev[i]!=-1)
        print_sol(prev,num, prev[i]);
    cout<<num[i]<<" ";
}

int main()
{
    freopen("lis.txt", "r", stdin);
    int n;
    cin>>n;
    vector<int>num(n),l(n, 1),prev(n,-1);
    int maxLen=0,maxIdx=0;
    for(int i=0; i<n; i++)
        cin>>num[i];
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(num[j]<num[i] && l[j]+1 > l[i])
            {
                l[i]=l[j]+1;
                prev[i]=j;
            }

        }
        if(l[i]>maxLen)
        {
            maxLen=l[i];
            maxIdx = i;
        }
    }
    print_sol(prev, num, maxIdx);
    return 0;
}
