#include<iostream>
#include<stdlib.h>
using namespace std;

int *visited;

int dfstype(int q,int *sp,int **am,int **we,int n)
{
    int l;
    for(int j=0;j<n;j++)
            {
                if(am[q][j]==1)
                {
                    if(sp[j]>(sp[q]+we[q][j]) && visited[j]==0)
                    {
                        sp[j]=(sp[q]+we[q][j]);
                        visited[j]=1;
                        l=dfstype(j,sp,am,we,n);
                        if(l==-1)
                            return -1;
                    }
                    else if(sp[j]>(sp[q]+we[q][j]) && visited[j]==1)
                    {
                        cout<<"\n Negative cycle detected. \n";
                        return -1;
                    }
                }
            }
visited[q]=0;
return 1;
}

void bellmanford(int **am,int **we,int *sp,int n,int ed)
{
    visited=new int[n];
    int sta;
    cout<<"\n Enter the starting vertex number :- ";
    cin>>sta;
    sp[sta]=0;
    for(int i=0;i<(n-1);i++)
    {
        int l;
        for(int k=0;k<n;k++)
            visited[k]=0;
        visited[sta]=1;
        l=dfstype(sta,sp,am,we,n);
        if(l==-1)
            exit(0);
    }
}


int main()
{
int n;
cout<<"Enter the number of vertex :- ";
cin>>n;
int *sp;
sp=new int[n];
for(int i=0;i<n;i++)
    sp[i]=999;
int **am;
am=new int*[n];
for(int i=0;i<n;i++)
{
    am[i]=new int[n];
    for(int j=0;j<n;j++)
        am[i][j]=0;
}
int **we;
we=new int*[n];
for(int i=0;i<n;i++)
{
    we[i]=new int[n];
    for(int j=0;j<n;j++)
        we[i][j]=0;
}
int ed;
cout<<"\nEnter the number of edges:- ";
cin>>ed;
for(int i=0;i<ed;i++)
{
    int in,en;
    cout<<"\n Enter the starting and ending vertex :- ";
    cin>>in>>en;
    am[in][en]=1;
    cout<<"\n Enter its weight :- ";
    cin>>we[in][en];
}
bellmanford(am,we,sp,n,ed);
cout<<"\n";
for(int i=0;i<n;i++)
{
    cout<<i<<"->"<<sp[i]<<"\n";
}
return 0;
}
