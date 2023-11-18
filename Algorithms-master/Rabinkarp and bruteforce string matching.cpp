#include<iostream>
#include<cstdio>
using namespace std;

int rabinkarp(char *c,char *m,int i,int len,int pv,int pv2)
{
    int flag=-1;
    if(pv==pv2)
    {
        flag=i;
        for(int j=i;j<(i+len);j++)
        {
            if(c[j]!=m[j-i])
                return -1;
        }
    }
    return flag;
}

int stmatchs(char *c,char *m,int i,int len)
{
    for(int j=i;j<(i+len);j++)
    {
        if(c[j]!=m[j-i])
            return -1;
    }
    return i;
}

int main()
{
    char c[30];
    char m[10];
    int countt=0;
    cout<<"\n Enter the original string :- ";
    gets(c);
    cout<<"\n Enter the pattern to be matched :- ";
    gets(m);
    int len1=0,len2=0,pv=0;
    for(len1=0;c[len1]!='\0';len1++);
    for(len2=0;m[len2]!='\0';len2++)
    {
        pv=(pv+(int)m[len2])%23;
    }
    int l;
    cout<<"\n Enter the method which you want to use for pattern matching : \n";
    cout<<"\n1. Brute force method \n2. Rabin carp method \n :- ";
    cin>>l;
    if(l==1)
    {
        int k=0;
        for(int i=0;i<=(len1-len2);i++)
        {
            k=stmatchs(c,m,i,len2);
            if(k==i)
                {
                    cout<<"\n Found on index "<<k;
                    countt++;
                }
        }
        cout<<"\n Found "<<countt<<" times.\n";
    }
    if(l==2)
    {
        int k=0,pv2=0;
        for(int i=0;i<len2;i++)
            pv2=(pv2+(int)c[i])%23;
        for(int i=0;i<=(len1-len2);i++)
        {
            k=rabinkarp(c,m,i,len2,pv,pv2);
            if(k==i)
                {
                    cout<<"\n Found on index "<<k;
                    countt++;
                }
            if((i+len2)<len1)
                pv2=(pv2-(int)c[i]+(int)c[i+len2])%23;
        }
        cout<<"\n Found "<<countt<<" times.\n";
    }
    return 0;
}
