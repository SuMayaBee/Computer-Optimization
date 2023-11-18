#include<iostream>
#include<cstdio>
using namespace std;

int rabinkarp(char *c,char *m,int i,int len,int pv,int pv2)
{
    int flag=0;
    if(pv==pv2)
    {
        flag=1;
        for(int j=i;j<(i+len);j++)
        {
            if(c[j]!=m[j-i])
                return 0;
        }
    }
    return flag;
}

int main()
{
    char c[30];
    char m[10];
    cout<<"\n Enter the original string :- ";
    gets(c);
    cout<<"\n Enter the pattern to be matched :- ";
    gets(m);
    int len1=0,len2=0,pv=0;
    for(len1=0;c[len1]!='\0';len1++);
    for(len2=0;m[len2]!='\0';len2++)
    {
        pv=pv+(int)m[len2];
    }
    int k=0,pv2=0;
    for(int i=0;i<len2;i++)
        pv2=pv2+(int)c[i];
    for(int i=0;i<=(len1-len2);i++)
    {
        k=rabinkarp(c,m,i,len2,pv,pv2);
        if(k==1)
            break;
        if((i+len2)<len1)
            pv2=pv2-(int)c[i]+(int)c[i+len2];
    }
    if(k==1)
        cout<<"\n Pattern found. \n";
    else
        cout<<"\n Pattern not found. \n";
}
