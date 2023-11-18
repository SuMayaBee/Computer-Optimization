#include<bits/stdc++.h>
using namespace std;

// void print_sol(vector<int>&prev, vector<int>&num, int i)
// {
//     if(prev[i])
//         print_sol(prev,num, prev[i]);
//     cout<<num[i-1]<<" ";
// }

void print_sol(vector<int>&prev, vector<int>&num, int i) {
    if(prev[i] && prev[i]>prev[i-1]) {
        print_sol(prev, num, prev[i-1]);
       // cout<<num[i]<<" ";
       
    }   cout<<num[i]<<" ";
} 

int main()
{
    
    int n;
    cin>>n;
    vector<int>num(n),l(n, 1),prev(n,0);
    int maxLen=0,maxIdx=0;
    for(int i=0; i<n; i++)
        cin>>num[i];
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(num[j]<num[i] )
            {
                l[i]=l[j]+1;
                prev[i]=j+1;
            }

        }
        if(l[i]>maxLen)
        {
            maxLen=l[i];
            maxIdx = i;
        }
    }

    for(int i=0; i<n; i++) {
        cout<<prev[i]<<" ";
        
    }

    cout<<endl;

    //  for(int i=0; i<n; i++) {
    //     cout<<l[i]<<" ";
        
    // }

    cout<<endl;
    cout<<maxIdx<<endl;

  // print_sol(prev, num, maxIdx);
    
    // for(int i= maxIdx; i>0; i--) {
    //     if(prev[i] && prev[i]>prev[i-1]) {
    //    // print_sol(prev, num, prev[i-1]);
    //     cout<<num[prev[i]]<<" ";
       
    // } 

    // }

    for(int i=2; i<=maxIdx; i++) {
            
            if(prev[i]==prev[i-1]) continue;
        
            cout<<num[prev[i]-1]<<" ";
            
        
    }  cout<<num[maxIdx]<<endl;
  
    return 0;
}


/*

10
9 2 5 3 7 11 8 10 13 6

*/