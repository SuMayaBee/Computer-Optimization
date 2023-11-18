#include<bits/stdc++.h>
using namespace std;
#define mx 1000

int graph[mx][mx]={0};
int dis[mx];
int pre[mx];

void dfs(int u, int v, stack<int>&st, vector<bool>&visited)
{
    visited[u]=true;

    for(int i=0; i<v; i++)
    {
        if(graph[u][i] && !visited[i])
        dfs(i,v,st,visited);
    }
    st.push(u);
}

stack<int> toposort(int v)
{
    vector<bool>visited(v, false);
    stack<int>st;

    for(int i=0; i<v; i++)
    {
        if(!visited[i])
        dfs(i,v,st, visited);
    }
    return st;
}

void initSource(int s, int v)
{
    for(int i=0; i<v; i++)
    {
        dis[i] = INT_MAX;
        pre[i] = -1;
    }
    dis[s] = 0;
}

void relax(int u, int v)
{
    if(dis[v]>dis[u]+graph[u][v]){
    dis[v] = dis[u] + graph[u][v];
    pre[v] = u;
    }
}

void belman_dag(int s, int v)
{
    stack<int>st = toposort(v);
    initSource(s,v);
    while(!st.empty())
    {
        int u = st.top();
        st.pop();
        for(int i=0; i<v; i++)
        {
            if(graph[u][i])
            relax(u,i);
        }
    }
}
void print(int i)
{
    if(i==-1)
    return;
    print(pre[i]);
    cout<<i<<" ";
}
int main()
{   
    //freopen("input.txt", "r", stdin);
    int v,e,x,y,w;

    cin>>v>>e;
    for(int i=0; i<e; i++)
    {
        cin>>x>>y>>w;
        graph[x][y] = w;
    }
    belman_dag(0,v);
    print(5);
    return 0;
}
