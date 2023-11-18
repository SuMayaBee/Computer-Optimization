#include<bits/stdc++.h>
using namespace std;

struct edge{
    string u,v;
    int w;
};

vector<vector<int>>graph;
vector<edge>edges;
map<string,int>mp;
int pre[100],ranks[100];

bool compare(struct edge edge1, struct edge edge2)
{
    return edge1.w<edge2.w;
}

void read(int &v, int &e, int &sumWeight)
{
    //freopen("kruskal.txt", "r", stdin);
    int x,y,w,k=0;
    string a,b;
    cin>>v>>e;
    graph.assign(v, vector<int>(v, 0));

    for(int i=0; i<e; i++)
    {
        cin>>a>>b>>w;

        if(mp[a]==0)
        mp[a]=++k;

        if(mp[b]==0)
        mp[b]=++k;

        graph[mp[a]][mp[b]]=w;
        edges.push_back({a, b, w});
        sumWeight+=w;
    }
}

void makeSet(string s)
{
    pre[mp[s]]=mp[s];
    ranks[mp[s]]=0;
}

void link(int a, int b)
{
    if(ranks[a]>ranks[b])
    pre[b]=a;
    else
    {
        pre[a]=b;
        if(ranks[a]==ranks[b])
        ranks[b]++;
    }
}

int findSet(int a)
{
    if(a!=pre[a])
    pre[a]=findSet(pre[a]);

    return pre[a];
}

void unions(int a, int b)
{
    link(findSet(a), findSet(b));
}

int kruskal(int V)
{
    for(auto x : mp)
    makeSet(x.first);
    sort(edges.begin(), edges.end(), compare);
    int count=0, minSum=0;
    
    for(edge edge : edges)
    {
        if(findSet(mp[edge.u])!=findSet(mp[edge.v]))
        {
            unions(mp[edge.u], mp[edge.v]);
            count++;
            minSum+=edge.w;
        }
        if(count==V-1)
        break;
    }
    return minSum;
}
int main()
{
    int v,e,sumWeight=0;
    read(v,e, sumWeight);
    cout<<"Max savings: "<<sumWeight-kruskal(v);

    return 0;
}
