#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    char t[40];
    char p[20];
    int l1=0,l2=0;
    cout<<"\nEnter text :- ";
    gets(t);
    cout<<"\nEnter pattern :- ";
    gets(p);
    for(l1=0;t[l1]!='\0';l1++);
    for(l2=0;p[l2]!='\0';l2++);
    int *lps;
    lps=new int[l2];
    lps[0]=0;
    int i=0;
    for(int j=1;j<l2;)
    {
        if(p[i]==p[j])
            {
                lps[j]=i+1;
                i=i+1;
                j=j+1;
            }
        else
        {
            if(i==0)
            {
                lps[j]=0;
                j=j+1;
            }
            else
            {
                while(i!=0)
                {
                    i=lps[i-1];
                    if(p[i]==p[j])
                    {
                        lps[j]=i+1;
                        i=i+1;
                        j=j+1;
                        break;
                    }
                }
            }
        }
    }
    cout<<"\nLps:- ";
    for(int i=0;i<l2;i++)
        cout<<lps[i]<<" ";
    cout<<"\n";
    int j=0;
    for(int i=0;i<l1;i++)
    {
        if(p[j]==t[i] && j==(l2-1))
        {
            cout<<"\nPattern found at :- "<<i-l2+1;
            j=lps[j];
        }
        else if(p[j]==t[i])
        {
            j++;
        }
        else if(p[j]!=t[i])
        {
            while(j!=0)
            {
                j=lps[j-1];
                if(p[j]==t[i])
                {
                    j++;
                    break;
                }
            }
        }
    }
    return 0;
}
