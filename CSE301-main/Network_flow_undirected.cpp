#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>graph;

bool bfs(int source, int dest, int v, vector<int>&previous)
{
    vector<bool>visited(v, false);
    queue<int>q;
    q.push(source);
    visited[source]=true;
    previous[source] = -1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=1; i<=v; i++)
        {
            if(!visited[i] && graph[u][i]>0)
            {
                q.push(i);
                visited[i]= true;
                previous[i] = u;
            }
        }
    }
    return visited[dest];
}

int ford(int source, int dest, int v)
{
    vector<int>previous(v);
    int maxFlow=0;
    while(bfs(source, dest, v, previous))
    {
        int minCap=INT_MAX;
        for(int u=dest; u!=source; u=previous[u])
        minCap = min(minCap, graph[previous[u]][u]);

        for(int u=dest; u!=source; u=previous[u])
        {
            graph[previous[u]][u] -= minCap;
            graph[u][previous[u]] += minCap;
        }
        maxFlow+=minCap;
    }
    return maxFlow;
}

int main()
{
    freopen("labTask.txt", "r", stdin);
    int v,e,x,y,w,source,dest;
    cin>>v;
    cin>>source>>dest>>e;
    graph.assign(v+1, vector<int>(v+1,0));

    for(int i=0; i<e; i++)
    {
        cin>>x>>y>>w;
        graph[x][y] = w;
        graph[y][x] = w;
    }
    cout<<"The Bandwith is: "<<ford(source, dest, v+1)<<endl;
    return 0;
}
