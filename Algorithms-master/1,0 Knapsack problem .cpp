#include<iostream>
using namespace std;

struct node{
    int ino;
    float w;
    float v;
    float vwr;
};

int main()
{
    node *nn;
    int n;
    float maxw;
    cout<<"\n Enter the number of items :- ";
    cin>>n;
    cout<<"\n Enter the maximum weight :-";
    cin>>maxw;
    nn=new node[n];
    for(int i=0;i<n;i++)
    {
        nn[i].ino=i+1;
       cout<<"\n Enter weight of item "<<i+1<<" :- ";
       cin>>nn[i].w;
       cout<<"\n Enter benefit of item "<<i+1<<" :- ";
       cin>>nn[i].v;
       nn[i].vwr=(nn[i].v)/(nn[i].w);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(nn[j].vwr<nn[j+1].vwr)
            {
                node temp=nn[j];
                nn[j]=nn[j+1];
                nn[j+1]=temp;
            }
        }
    }
    cout<<"\n\n (By v/w ratio) Items are :-";
    int gb1=0;
    float rp=maxw;
    for(int i=0;i<n;i++)
    {
        if(nn[i].w<=rp)
        {
            gb1=gb1+nn[i].v;
            rp=rp-nn[i].w;
            cout<<"Item "<<nn[i].ino<<",";
        }
    }
    cout<<"\nBenefit is :- "<<gb1<<"\n";

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(nn[j].v<nn[j+1].v)
            {
                node temp=nn[j];
                nn[j]=nn[j+1];
                nn[j+1]=temp;
            }
        }
    }
    cout<<"\n\n(By maximum v) Items are :-";
    int gb2=0;
    float rp2=maxw;
    for(int i=0;i<n;i++)
    {
        if(nn[i].w<=rp2)
        {
            gb2=gb2+nn[i].v;
            rp2=rp2-nn[i].w;
            cout<<"Item "<<nn[i].ino<<",";
        }
    }
    cout<<"\nBenefit is :- "<<gb2<<"\n";
    cout<<"\n\nMaximum benefit : ";

    if(gb1>gb2)
        cout<<gb1;
    else
        cout<<gb2;

return 0;
}
