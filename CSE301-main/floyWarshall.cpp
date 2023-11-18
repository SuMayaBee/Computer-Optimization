#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>p;

void floydWarshall(vector<vector<int>>&graph, vector<vector<int>>&D, int v)
{
    D.resize(v, vector<int>(v));
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            if(i==j)
            D[i][j] = 0;
            else
            D[i][j] = graph[i][j];
        }
    }
    
    for(int k=0; k<v; k++)
    {
        for(int i=0; i<v; i++)
        {
            for(int j=0; j<v; j++)
            {
                if(D[i][k]+D[k][j]<D[i][j] && D[i][k]!=INT_MAX && D[k][j]!=INT_MAX)
                {
                    D[i][j] = D[i][k]+D[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }
}

void print(vector<vector<int>>&graph, int v)
{
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

void p_init(vector<vector<int>>&graph, int v)
{
    p.resize(v, vector<int>(v));
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            if(i==j || graph[i][j]==INT_MAX)
            p[i][j] = -1;
            else if(i!=j && graph[i][j]<INT_MAX)
            p[i][j] = i;
        }
    }
}

void path(int s, int t)
{
    if(p[s][t]==-1)
    {
        cout<<"No path"<<endl;
        return;
    }
    else if(p[s][t]==s)
    cout<<s<<" ";
    else
    {
        path(s, p[s][t]);
        path(p[s][t], t);
    }
}

int main()
{
    //freopen("floyd.txt", "r", stdin);
    int v,e,x,y,w,src,dest;
    cin>>v>>e;

    vector<vector<int>>graph(v, vector<int>(v, INT_MAX));
    vector<vector<int>>D(v, vector<int>(v, 0));
    for(int i=0; i<e; i++)
    {
        cin>>x>>y>>w;
        if(x==y)
            graph[x][y] = 0;
        else
            graph[x][y] = w;
    }
    p_init(graph, v);
    floydWarshall(graph, D, v);
    print(D, v);
    cout<<endl;
    src=4, dest=1;
    path(src, dest);
    cout<<dest<<endl;
    return 0;
}
