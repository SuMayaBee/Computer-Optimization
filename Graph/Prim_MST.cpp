#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g){
    
   unordered_map<int, list<pair<int, int>>> adj;
   
   for(int i=0; i<g.size(); i++) {
    int u = g[i].first.first;
    int v = g[i].first.second;
    int w = g[i].second;
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));

   }

   vector<int> key(n+1);
   vector<bool> mst(n+1);
   vector<int> parent(n+1);

   for(int i=0; i<=n; i++) {
    key[i]=INT_MAX;
    mst[i]=false;
    parent[i]=-1;
   }

   // Starting the algo

   key[1]=0;
   parent[1]=-1;

   for(int i=0; i<n; i++) {
    int mini = INT_MAX;
    int u;

    // find the min node
    for(int v=1; v<=n; v++) {
        if(mst[v]==false && key[v]<mini) {
            u=v;
            mini=key[v];
        }
    }
    
    //mark min node as true;
    mst[u] = true;

    //check its adj nodes
    for(auto it: adj[u] ) {
        int v = it.first;
        int w = it.second;
        if(mst[v]==false && w<key[v]) {
            parent[v]=u;
            key[v]=w;
        }
    }

   }

   vector<pair<pair<int, int>, int>> result;
   for(int i=2; i<=n; i++) {
    result.push_back(make_pair(make_pair(parent[i], i), key[i]));
   }


return result;

}

int main() {

    int n, m;
    cout<<"Enter the number of nodes: ";
    cin>>n; 
    cout<<"Enter the number of edges:  ";
    cin>>m;

    vector<pair<pair<int, int>, int>> g(m);

    for(int i=0; i<m; i++) {
        cin>>g[i].first.first>>g[i].first.second>>g[i].second;
    }

    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, g);

    // Print the MST
    cout<<"Minimum Spanning Tree:\n";
    for(auto &edge: mst) {
        cout<<edge.first.first<<" - "<<edge.first.second<<" - "<<edge.second<<"\n";
    }


    return 0;
}

/*
Enter the number of nodes: 5
Enter the number of edges:  15
1 2 21
1 4 16
2 1 12
2 3 13
2 4 18
2 5 15
3 2 13
3 5 17
4 1 16
4 2 18
4 5 19
5 1 18
5 2 15
5 3 17
5 4 19
Minimum Spanning Tree:
1 - 2 - 12
2 - 3 - 13
1 - 4 - 16
2 - 5 - 15
*/