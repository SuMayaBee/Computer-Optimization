#include<bits/stdc++.h>
using namespace std;
//#define minWeight 0

bool cmp(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n) {
    for(int i=0; i<n; i++) {
        parent[i] = i;
        rank[i] =0;
    }
}

int findParent(vector<int> &parent, int node) {
    if(parent[node]==node) {
        return node;
    }

    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u= findParent(parent, u);
    v= findParent(parent, v);
    if(rank[u]<rank[v]) {
        parent[u]=v;
    } else if(rank[u]>rank[v]) {
        parent[v]=u;
    } else {
        parent[v]= u;
        rank[u]++;
    }
}

void minimumSpanningTree(vector<vector<int>>&edges, int n, int &minWeight) {
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    minWeight = 0;
    //int a=0;
    // mst(n, vector<int>(3));

    for(int i=0; i<edges.size(); i++) {
        int u= findParent(parent, edges[i][0]);
        int v= findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        if(u!=v) {
            minWeight += wt;
            cout<<u<<" "<<v<<" "<<wt<<endl;
            unionSet(u, v, parent, rank);
        }
    } // return minWeight + a;
}


int main() {

    int n, m, mw;
    cout<<"Enter the number of nodes:";
    cin>>n;
    cout<<"Enter the number of edges:";
    cin>>m;

    vector<vector<int>> edges(m, vector<int>(3));
    // node1 node2 weight

    for(int i=0; i<m; i++) {
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }

    cout<<endl;

     minimumSpanningTree(edges, n, mw);
      cout<<endl;

    cout<<mw<<endl;



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
*/