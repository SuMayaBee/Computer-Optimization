#include<bits/stdc++.h>
using namespace std;

void print_interval(vector<int>&prev, vector<int>&num, int i)
{
    if(prev[i]>0)
    {
        print_interval(prev, num, prev[i]);
        cout<<num[i-1]<<" ";
    }
}
int main()
{
    freopen("msi.txt", "r", stdin);
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int>num(n),pre(n),prev(n,0);
    for(int i=0; i<n; i++)
        cin>>num[i];
    pre[0]=num[0];
    for(int i=1; i<n; i++)
    {
        pre[i] = pre[i-1]+num[i];
        prev[i]=i-1;
        if(pre[i]<num[i])
        {
            pre[i]=num[i];
            prev[i]=0;
        }
    }

    print_interval(prev, num, n-1);
    return 0;
}
