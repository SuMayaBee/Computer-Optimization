#include<stdlib.h>
#include<iostream>
using namespace std;

struct sett{
char chh;
int setno;
};

struct node{
char c;
node *pt;
};

struct edge{
char s;
char d;
int weight;
};

struct graph{
node *ver;
};

int findset(sett *se,char ch,int n)
{
    for(int i=0;i<n;i++)
    {
        if(se[i].chh==ch)
            return se[i].setno;
    }
    return -1;
}

void unionn(sett *se,char ch1,char ch2,int n)
{
    int f1=findset(se,ch1,n);
    int f2=findset(se,ch2,n);
    for(int i=0;i<n;i++)
    {
        if(se[i].setno==f2)
             se[i].setno=f1;
    }
}

int main()
{
    graph g;
    edge *ed,*ed2;
    edge temp;
    sett *se;
    int n,l=0,r=0;
    cout<<"\nEnter the number of nodes : \n";
    cin>>n;
    se=new sett[n];
    int nn=n*(n-1)/2;
    ed=new edge[nn];
    for(int i=0;i<nn;i++)
    {
        ed[i].s='\0';
        ed[i].d='\0';
        ed[i].weight=-1;
    }
    g.ver=new node[n];
    for(int i=0;i<n;i++)
    {
        char ch;
        cout<<"\nEnter the name of node "<<i+1<<" : ";
        cin>>ch;
        g.ver[i].c=ch;
        g.ver[i].pt=NULL;
        se[i].chh=ch;
        se[i].setno=i;
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
            ed[l].s=g.ver[i].c;
            temp->pt=new node;
            char name;
            cout<<"\n Enter name of "<<j+1<<" connected node : ";
            cin>>name;
            ed[l].d=name;
            cout<<"\n Enter its weight : ";
            cin>>ed[l].weight;
            (temp->pt)->c=name;
            (temp->pt)->pt=NULL;
            temp=temp->pt;
            l++;
        }
    }

    for(int i=0;i<l;i++)
    {
        for(int j=0;j<l-1;j++)
        {
            if(ed[j].weight>ed[j+1].weight)
            {
              temp=ed[j];
              ed[j]=ed[j+1];
              ed[j+1]=temp;
            }
        }
    }
    ed2=new edge[l];
    for(int i=0;i<l;i++)
    {
        ed2[i].s='\0';
        ed2[i].d='\0';
        ed2[i].weight=-1;
    }
    for(int i=0;i<l;i++)
    {
        if(findset(se,ed[i].s,n)!=findset(se,ed[i].d,n))
        {
            ed2[r].s=ed[i].s;
            ed2[r].d=ed[i].d;
            ed2[r].weight=ed[i].weight;
            unionn(se,ed[i].s,ed[i].d,n);
            r++;
        }
    }
    cout<<"\n";
    for(int i=0;i<r;i++)
        cout<<ed2[i].s<<"->"<<ed2[i].d<<"\n";

    return 0;
}

