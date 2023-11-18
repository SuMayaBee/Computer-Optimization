#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>graph;

bool bfs(int source, int sink, int v, vector<vector<int>>&residual, vector<int>&previous)
{
    vector<int>visited(v, false);
    queue<int>q;
    q.push(source);
    visited[source]=true;
    previous[source]=-1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0; i<v; i++)
        {
            if(!visited[i] && residual[u][i])
            {
                q.push(i);
                visited[i]=true;
                previous[i]=u;
            }
        }
    }
    return visited[sink];
}

int fordFul(int source, int sink, int v)
{
    vector<vector<int>>residual(v,vector<int>(v));

    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        residual[i][j] = graph[i][j];
    }
    vector<int>previous(v);
    int max=0;

    while(bfs(source, sink, v, residual, previous))
    {
        int minCap = INT_MAX;
        for(int i=sink; i!=source; i=previous[i])
        {
            int u = previous[i];
            minCap = min(minCap, residual[u][i]);
        }
        max+=minCap;
        for(int i=sink; i!=source; i=previous[i])
        {
            int u = previous[i];
            residual[u][i] -= minCap;
            residual[i][u] += minCap;
        }
    }
    return max;
}

int main()
{   
    //freopen("ford.txt", "r", stdin);
    int v,e,x,y,w;
    cin>>v>>e;
    graph.assign(v, vector<int>(v, 0));

    for(int i=0; i<e; i++)
    {
        cin>>x>>y>>w;
        graph[x][y] = w;
    }
    cout<<fordFul(0,5,v);
    return 0;
}
