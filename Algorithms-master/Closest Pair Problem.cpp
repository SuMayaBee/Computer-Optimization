#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

struct co
{
    float x,y;
};

void mergee(co *p,int i,int mid,int j)
{
    co *q;
    int nn;
    nn=j-i+1;
    q=new co[nn];
    int c3=0;
    int c1=i;
    int c2=mid+1;
    while(c1<=mid && c2<=j)
    {
        if(p[c1].x<=p[c2].x)
        {
            q[c3]=p[c1];
            c3++;
            c1++;
        }
        else if(p[c1].x>p[c2].x)
        {
            q[c3]=p[c2];
            c3++;
            c2++;
        }
    }
    while(c1<=mid)
    {
        q[c3]=p[c1];
        c3++;
        c1++;
    }
    while(c2<=j)
    {
        q[c3]=p[c2];
        c3++;
        c2++;
    }
    for(int w=i,e=0;w<=j;w++,e++)
        p[w]=q[e];
}

void mergesort(co *p,int i,int j)
{
    if(i<j)
    {
        int mid;
        mid=(i+j)/2;
        mergesort(p,i,mid);
        mergesort(p,mid+1,j);
        mergee(p,i,mid,j);
    }
}

void mergeey(co *p,int i,int mid,int j)
{
    co *q;
    int nn;
    nn=j-i+1;
    q=new co[nn];
    int c3=0;
    int c1=i;
    int c2=mid+1;
    while(c1<=mid && c2<=j)
    {
        if(p[c1].y<=p[c2].y)
        {
            q[c3]=p[c1];
            c3++;
            c1++;
        }
        else if(p[c1].y>p[c2].y)
        {
            q[c3]=p[c2];
            c3++;
            c2++;
        }
    }
    while(c1<=mid)
    {
        q[c3]=p[c1];
        c3++;
        c1++;
    }
    while(c2<=j)
    {
        q[c3]=p[c2];
        c3++;
        c2++;
    }
    for(int w=i,e=0;w<=j;w++,e++)
        p[w]=q[e];
}

void mergesorty(co *p,int i,int j)
{
    if(i<j)
    {
        int mid;
        mid=(i+j)/2;
        mergesorty(p,i,mid);
        mergesorty(p,mid+1,j);
        mergeey(p,i,mid,j);
    }
}


float minn(float a,float b)
{
    if(a<b)
        return a;
    else
        return b;
}

float minimum(co *p,int i,int j)
{
    float dist=9999,res;
    for(int q=i;q<j;q++)
    {
        for(int w=q+1;w<=j;w++)
        {
            res=sqrt(((p[q].x-p[w].x)*(p[q].x-p[w].x))+((p[q].y-p[w].y)*(p[q].y-p[w].y)));
            if(res<dist)
                dist=res;
        }
    }
    return dist;
}

void daq(co *p,int i,int j,float *mind)
{
    if((j-i)>2)
    {
        int mid;
        float mind1,mind2;
        mid=(i+j)/2;
        daq(p,i,mid,&mind1);
        daq(p,mid+1,j,&mind2);
        float d;
        d=minn(mind1,mind2);
        int si=j-i+1;
        int cc=0;
        co *stp;
        stp=new co[si];
        for(int w=i;w<=j;w++)
        {
            if((p[w].x-p[mid].x)<d || (p[mid].x-p[w].x)<d )
            {
                stp[cc]=p[w];
                cc++;
            }
        }
        mergesorty(stp,0,cc-1);
        float dist=9999;
        for(int k=0;k<(cc-1);k++)
        {
         for(int l=k+1;l<cc && ((stp[k].y-stp[l].y)<d || (stp[l].y-stp[k].y)<d);l++)
         {
             dist=sqrt(((stp[k].x-stp[l].x)*(stp[k].x-stp[l].x))+((stp[k].y-stp[l].y)*(stp[k].y-stp[l].y)));
             if(dist<d)
                d=dist;
         }
        }
        *mind=d;
    }
    else
    {
        *mind=minimum(p,i,j);
    }

}

int main()
{
    int n;
    co *p;
    cout<<"\n Enter the number of points : ";
    cin>>n;
    p=new co[n];
    for(int i=0;i<n;i++)
    {
        cout<<"\n Enter the co-ordinates of point "<<i+1<<" :- \n";
        cin>>p[i].x>>p[i].y;
    }
    mergesort(p,0,n-1);
    float mind;
    daq(p,0,n-1,&mind);
    cout<<"\n Minimum distance is : "<<mind<<"\n";
    return 0;
}
