#include<iostream>
#include<cstdio>
using namespace std;

int stmatch(char *c,char *m,int i,int len)
{
int flag=1;
    for(int j=i;j<(i+len);j++)
    {
        if(c[j]!=m[j-i])
        {
          flag=0;
          break;
        }
    }
return flag;
}

int main()
{
    char c[30],m[10];
    int len1=0,len2=0;
    cout<<"\n Enter the string : ";
    gets(c);
    cout<<"\n Enter word to be match : ";
    gets(m);
    for(len1=0;c[len1]!='\0';len1++);
    for(len2=0;m[len2]!='\0';len2++);
    int k=0;
    for(int i=0;i<=(len1-len2);i++)
    {
        k=stmatch(c,m,i,len2);
        if(k==1)
            break;
    }
if(k==0)
    cout<<"\n Match not found. \n";
else if(k==1)
    cout<<"\n Match found. \n";
    return 0;
}
