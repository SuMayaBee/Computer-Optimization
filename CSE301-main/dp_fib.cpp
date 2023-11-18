#include<bits/stdc++.h>
using namespace std;
#define mx 100

long long int fibNum[mx];

long long int fib(long long int n)
{
    if(n<=1)
    fibNum[n]=n;
    else if(fibNum[n]<0)
    {
        fibNum[n]=fib(n-1)+fib(n-2);
    }
    return fibNum[n];
}
int main()
{
    long long int n;
    memset(fibNum, -1, sizeof(fibNum));
    cin>>n;
    long long int res=fib(n);
    cout<<res;
    return 0;
}

