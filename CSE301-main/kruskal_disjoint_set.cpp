#include<bits/stdc++.h>
using namespace std;
#define mx 100

struct edge{
    int u;
    int v;
    int w;
};

vector<vector<int>>graph;
vector<edge>edges;
int parent[mx];
int ranks[mx];

bool compare(struct edge a, struct edge b)
{
    return a.w<b.w;
}
void make_set(int i)
{
    parent[i] = i;
    ranks[i]=0;
}

int find_set(int i)
{
    if(i!=parent[i])
    parent[i] = find_set(parent[i]);

    return parent[i];
}

void link(int u, int v)
{
    if(ranks[u]>ranks[v])
    parent[v] = u;
    else
    {
        parent[u]=v;
        if(ranks[u]==ranks[v])
        ranks[v]++;
    }
}
void unions(int u, int v)
{
    link(find_set(u), find_set(v));
}

void kruskal(int V)
{
    for(int i=0; i<V; i++)
    make_set(i);
    sort(edges.begin(), edges.end(), compare);
    int count=0, sum=0;
    for(edge edge : edges)
    {
        if(find_set(edge.u)!=find_set(edge.v))
        {
            unions(edge.u, edge.v);
            count++;
            sum+=edge.w;
            cout<<(char)(edge.u+'a')<<" "<<(char)(edge.v+'a')<<endl;
        }
        if(count==V-1)
        break;
    }
    cout<<"Sum of spanning tree: "<<sum<<endl;
}

int main()
{
    freopen("kruskal_set.txt", "r", stdin);
    int v,e,x,y,w;
    char a,b;
    cin>>v>>e;
    graph.assign(v, vector<int>(v, 0));
    for(int i=0; i<e; i++)
    {
        cin>>a>>b>>w;
        graph[a-'a'][b-'a'] = w;
        edges.push_back({a-'a',b-'a',w});
    }
    kruskal(v);
    return 0;
}
