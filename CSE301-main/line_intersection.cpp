#include<bits/stdc++.h>
using namespace std;

int direction(pair<int,int>&p1, pair<int,int>&p2, pair<int,int>&p3)
{
    p3.first-=p1.first;
    p3.second-=p1.second;
    p2.first-=p1.first;
    p2.second-=p1.second;

    return p3.first*p2.second-p3.second*p2.first;
}

bool on_segment(pair<int,int>&p1, pair<int,int>&p2, pair<int,int>&p3)
{
    if((min(p1.first, p2.first)<=p3.first) && (p3.first<=max(p1.first,p2.first)) && (min(p1.second,p2.second)<=p3.second) && (p3.second<=(max(p1.second,p2.second))))
    return true;
    return false;
}

bool segment_intersect(vector<pair<int,int>>&p)
{
    int d1 = direction(p[2], p[3], p[0]);
    int d2 = direction(p[2], p[3], p[1]);
    int d3 = direction(p[0], p[1], p[2]);
    int d4 = direction(p[0], p[1], p[3]);
    if(((d1>0 && d2<0) || (d1<0 && d2>0)) && ((d3>0 && d4<0) || (d3<0 && d4>0)))
    return true;
    else if(d1==0 && on_segment(p[2],p[3],p[0]))
    return true;
    else if(d2==0 && on_segment(p[2],p[3],p[1]))
    return true;
    else if(d3==0 && on_segment(p[0],p[1],p[2]))
    return true;
    else if(d4==0 && on_segment(p[0],p[1],p[3]))
    return true;
    else
    return false;
}
int main()
{
    vector<pair<int,int>>p(4);
    int x,y;
    for(int i=0; i<4; i++)
    {
        cin>>x>>y;
        p[i].first=x;
        p[i].second=y;
    }
    segment_intersect(p)?cout<<"Lines intersect":cout<<"Lines do not intersect";
    cout<<endl;
    return 0;
}
