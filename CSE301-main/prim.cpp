#include<bits/stdc++.h>
using namespace std;
#define mx 100

vector<vector<int>> graph;
int pre[mx];
int keys[mx];
int visited[mx];

void prim(int V, int s)
{
    for(int i=0; i<V; i++)
    {
        keys[i] = INT_MAX;
        pre[i] = -1;
        visited[i]=0;
    }
    keys[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    for (int i = 0; i < V; i++)
        Q.push({keys[i],i});
    while (!Q.empty())
    {
        int u = Q.top().second;
        Q.pop();
        for (int i = 0; i < V; i++)
        {
            if (graph[u][i] && graph[u][i]<keys[i] && !visited[i])
            {
                keys[i] = graph[u][i];
                pre[i] = u;
            }
        }
        visited[u]=1;
    }
}

void printG(int v)
{
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        cout<<graph[i][j]<<" ";
        cout<<endl;
    }
}


int main()
{
    freopen("prim.txt", "r", stdin);
    int v, e, w;
    char x, y;
    cin >> v >> e;
    graph.assign(v, vector<int>(v, 0));
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y >> w;
        graph[x - 'a'][y - 'a'] = w;
        graph[y-'a'][x-'a']=w;
    }
    prim(v, 0);
    for(int x : keys)
    cout<<x<<" ";
    cout<<endl;
    for(int x : pre)
    cout<<x<<" ";
    
    return 0;
}
