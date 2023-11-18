#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    char t1[30],t2[30],t3[30];
    int len1=0,len2=0,k=0;
    cout<<"\n Enter the string 1 : ";
    gets(t1);
    cout<<"\n Enter the string 2 : ";
    gets(t2);
    for(len1=0;t1[len1]!='\0';len1++);
    for(len2=0;t2[len2]!='\0';len2++);
    len1++;
    len2++;
    int **m;
    int **s;
    m=new int*[len2];
    s=new int*[len2];
    for(int i=0;i<len1;i++)
     {
         m[i]=new int[len1];
         s[i]=new int[len1];
     }
    for(int j=0;j<len1;j++)
    {
        m[0][j]=0;
        s[0][j]=0;
    }
     for(int i=0;i<len2;i++)
     {
         m[i][0]=0;
         s[i][0]=0;
     }

     for(int i=0;i<(len2-1);i++)
     {
         for(int j=0;j<(len1-1);j++)
         {
             if(t2[i]==t1[j])
             {
                 m[i+1][j+1]=m[i][j]+1;
                 s[i+1][j+1]=2;
             }
             else
             {
                 if(m[i+1][j]==m[i][j+1])
                 {
                     m[i+1][j+1]=m[i][j+1];
                     s[i+1][j+1]=3;
                 }
                 else if(m[i+1][j]>m[i][j+1])
                 {
                     m[i+1][j+1]=m[i+1][j];
                     s[i+1][j+1]=1;
                 }
                 else if(m[i+1][j]<m[i][j+1])
                 {
                     m[i+1][j+1]=m[i][j+1];
                     s[i+1][j+1]=3;
                 }
             }

         }
     }
    cout<<"\n Matrix 1 is:- \n";
     for(int i=0;i<len2;i++)
     {
         cout<<"\n";
         for(int j=0;j<len1;j++)
            cout<<m[i][j]<<" ";
     }
    cout<<"\n Matrix 2 is:- \n";
     for(int i=0;i<len2;i++)
     {
         cout<<"\n";
         for(int j=0;j<len1;j++)
            cout<<s[i][j]<<" ";
     }
     int r;
     r=s[len2-1][len1-1];
     int i=len2-1;
     int j=len1-1;
     while(1)
     {
         if(s[i][j]==2)
         {
             t3[k]=t1[j-1];
             k=k+1;
             i=i-1;
             j=j-1;
         }
         else if(s[i][j]==1)
         {
             j=j-1;
         }
         else if(s[i][j]==3)
         {
             i=i-1;
         }
         r=s[i][j];
         if(r==0)
            break;
     }
     k--;
     cout<<"\n Longest common subsequence is:- ";
     while(k>=0)
        {
            cout<<t3[k];
            k--;
        }
    return 0;
}
