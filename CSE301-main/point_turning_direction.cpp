#include<bits/stdc++.h>
using namespace std;

int direct(pair<int,int>&x, pair<int,int>&y)
{
    int res = x.first*y.second-x.second*y.first;
    return res;
}

int main()
{
    pair<int,int>p[3];
    int x,y;
    for(int i=0; i<3; i++)
    {
        cin>>x>>y;
        p[i].first=x;
        p[i].second=y;
    }
    for(int i=1; i<3; i++)
    {
        p[i].first-=p[0].first;
        p[i].second-=p[0].second;
    }
    int res = direct(p[2], p[1]);
    res>0 ? cout<<"We make a right turn at point1":cout<<"we make a left turn at point1";
    cout<<endl;
    return 0;
}
