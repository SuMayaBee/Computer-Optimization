#include<bits/stdc++.h>
using namespace std;

int main()
{
    pair<int,int>point1,point2;
    int x,y;
    cin>>x>>y;
    point1.first=x;
    point1.second=y;
    cin>>x>>y;
    point2.first=x;
    point2.second=y;
    int res = point1.first*point2.second-point1.second*point2.first;
    res>0 ? cout<<"Point1 is clockwise to Point2":cout<<"Point1 is counterclockwise to Point2";
    cout<<endl;
    return 0;
}
