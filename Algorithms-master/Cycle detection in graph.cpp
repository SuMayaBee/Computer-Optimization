#include<stdlib.h>
#include<iostream>
using namespace std;

struct node{
char c;
node *pt;
};

struct graph{
node *ver;
};

struct visited
{
    char c;
    int value;
};

int vis(visited *v,char ch,int n)
{
    for(int i=0;i<n;i++)
    {
        if(v[i].c==ch && v[i].value==0)
        {
            v[i].value=1;
            return 0;
        }
    }
    return 1;
}

int cvis(visited *v,char ch,int n)
{
    for(int i=0;i<n;i++)
    {
        if(v[i].c==ch && v[i].value==0)
        {
            return 0;
        }
    }
    return 1;
}

node* getad(graph g,char ch,int n)
{
    for(int i=0;i<n;i++)
    {
        if(g.ver[i].c==ch)
            return &(g.ver[i]);
    }
}

void detect(graph g,int n,visited *v,node *t)
{
while(t!=NULL)
{
    node *temp;
    temp=t;
    if(vis(v,t->c,n)==1)
        {
            cout<<"\n\n Cycle present.\n";
            exit(1);
        }
    else
        {
            temp=getad(g,temp->c,n);
            detect(g,n,v,temp->pt);
                for(int j=0;j<n;j++)
                {
                  if((v[j].c)==t->c)
                    v[j].value=0;
                }
        }
    t=t->pt;
    }
}

int main()
{
    graph g;
    visited *v;
    stackk st;
    st.top=-1;
    int n;
    cout<<"\nEnter the number of nodes : \n";
    cin>>n;
    g.ver=new node[n];
    v=new visited[n];
    st.ar=new char[n];
    for(int i=0;i<n;i++)
    {
        char ch;
        cout<<"\nEnter the name of node "<<i+1<<" : ";
        cin>>ch;
        g.ver[i].c=ch;
        g.ver[i].pt=NULL;
        v[i].c=ch;
        v[i].value=0;
    }
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        int k=0;
        cout<<"\nEnter the number of nodes connected to node "<<g.ver[i].c<<" : ";
        cin>>k;
        node *temp=&(g.ver[i]);
        for(int j=0;j<k;j++)
        {
            temp->pt=new node;
            char name;
            cout<<"\n Enter name of "<<j+1<<" connected node : ";
            cin>>name;
            (temp->pt)->c=name;
            (temp->pt)->pt=NULL;
            temp=temp->pt;
        }
    }
    node *tem;
    for(int i=0;i<n;i++)
    {
        cout<<"\n";
        tem=&(g.ver[i]);
        while(tem!=NULL)
        {
            cout<<tem->c<<"->";
            tem=tem->pt;
        }
        cout<<"NULL";
    }

    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                v[j].value=0;
            detect(g,n,v,&(g.ver[i]));
        }
    return 0;
}
