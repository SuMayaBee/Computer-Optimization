#include<bits/stdc++.h>
using namespace std;

struct edge{
    int src;
    int dest;
    int weight;
};

vector<vector<int>>graph;
vector<edge>edges;

bool compare(struct edge a, struct edge b)
{
    return a.weight<b.weight;
}

int find_set(vector<int>&parent, int idx)
{
    if(parent[idx]==-1)
    return idx;
    find_set(parent, parent[idx]);
}

void kruskal(int V)
{
    sort(edges.begin(), edges.end(), compare);
    vector<int>parent(V, -1);
    vector<edge>ans;
    int e=0;
    for(edge edge : edges)
    {
        int u = find_set(parent, edge.src);
        int v = find_set(parent, edge.dest);
        if(u!=v)
        {
            ans.push_back(edge);
            parent[u] = v;
            e++;
        }
        if(e==V-1)
        break;
    }
    for(auto x : ans)
    {
        cout<<x.src<<" "<<x.dest<<" "<<x.weight<<endl;
    }
    cout<<endl;
}
int main()
{
    freopen("kruskal.txt", "r", stdin);
    int v,e,x,y,w;
    cin>>v>>e;
    graph.assign(v, vector<int>(v, 0));
    for(int i=0; i<e; i++)
    {
        cin>>x>>y>>w;
        graph[x][y]=w;
        graph[y][x]=w;
        edges.push_back({x,y,w});
        edges.push_back({y,x,w});
    }
    kruskal(v);
    return 0;
}
