#include<iostream>
#include<stdlib.h>
using namespace std;

void nqueen(int **bo,int n,int k)
{
    int c1,c2;
    int **bo2;
    bo2=new int*[n];
    for(int i=0;i<n;i++)
    {
        bo2[i]=new int[n];
        for(int j=0;j<n;j++)
            bo2[i][j]=bo[i][j];
    }
    for(int i=0;i<n;i++)
    {
        if(bo[k][i]==0)
        {
            bo[k][i]=1;
            for(int j=0;j<n;j++)
                {
                    if(j!=i)
                        bo[k][j]=2;
                }
            for(int j=0;j<n;j++)
                {
                    if(j!=k)
                        bo[j][i]=2;
                }
            c1=k+1;
            c2=i-1;
            while(c1>=0 && c2>=0 && c1<n && c2<n)
            {
                bo[c1][c2]=2;
                c1++;
                c2--;
            }
            c1=k+1;
            c2=i+1;
            while(c1<n && c2<n)
            {
                bo[c1][c2]=2;
                c1++;
                c2++;
            }
            if(k<(n-1))
                {
                    nqueen(bo,n,k+1);
                    for(int q=0;q<n;q++)
                    {
                        for(int w=0;w<n;w++)
                            bo[q][w]=bo2[q][w];
                    }
                }
            else if(k==(n-1))
            {
                for(int y=0;y<n;y++)
                {
                    cout<<"\n";
                    for(int u=0;u<n;u++)
                    {
                        if(bo[y][u]!=1)
                            bo[y][u]=0;
                        cout<<bo[y][u]<<" ";
                    }
                }
                exit(0);
            }
        }
    }
}

int main()
{
    int n;
    do
    {
    cout<<"\n Enter the number of queens : ";
    cin>>n;
    }while(n<=3);
    int **bo;
    bo=new int*[n];
    for(int i=0;i<n;i++)
    {
        bo[i]=new int[n];
        for(int j=0;j<n;j++)
            bo[i][j]=0;
    }
    cout<<"\n Chess board would be like :- \n";
    nqueen(bo,n,0);
    return 0;
}
