
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
    
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int>num(n),sum(n),prev(n,0);
    for(int i=0; i<n; i++)
        cin>>num[i];
    sum[0]=num[0];
    for(int i=1; i<n; i++)
    {
        sum[i] = sum[i-1]+num[i];
        prev[i]=i-1;
        if(sum[i]<num[i])
        {
            sum[i]=num[i];
            prev[i]=0;
        }
    }

    print_interval(prev, num, n-1);
    return 0;
}








/*

15
9 -3 1 7 -15 2 3 -4 2 -7 6 -2 8 4 -9

*/
