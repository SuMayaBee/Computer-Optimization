#include<bits/stdc++.h>
using namespace std;

int bellmanFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
          vector<int> dist(n+1, 1e9);
          dist[src]=0;

          for(int i=0; i<=n; i++) {
            for(int j=0; j<m; j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];

                if(dist[u]!= 1e9 && (dist[u] + wt) < dist[v]) {
                    dist[v]=dist[u]+wt;

                }
            }
          }

          bool flag=0;
              for(int j=0; j<m; j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];

                if(dist[u]!= 1e9 && (dist[u] + wt) < dist[v]) {
                    flag=1;

                }
            }

            if(!flag) {
                return dist[dest];
            }else {
                return -1;
            }

}


int main() {
    int n, m;
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

    int src, dest;
    cout<<"Enter the source node:";
    cin>>src;
    cout<<"Enter the destination node:";
    cin>>dest;

    int distance = bellmanFord(n, m, src, dest, edges);

    if(distance != -1) {
        cout<<"Shortest distance from node "<<src<<" to node "<<dest<<" is: "<<distance<<endl;
    } else {
        cout<<"Negative cycle detected. Shortest distance not applicable."<<endl;
    }

    return 0;
}


/*
5
15
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


