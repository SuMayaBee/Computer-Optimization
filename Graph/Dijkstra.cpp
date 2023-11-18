#include <iostream>
#include <limits.h>
#include <map>
#include <set>

using namespace std;

map<int, map<int, int>> graph;
map<int, int> dist;
map<int, int> parent;
set<pair<int, int>> pq;

void addEdge(int u, int v, int weight) {
  graph[u][v] = weight; 
}

void dijkstra(int src, int dest) {
  for(auto it = graph.begin(); it != graph.end(); ++it) {
    dist[it->first] = INT_MAX;
  }
  
  dist[src] = 0;
  pq.insert({0, src});

  while(!pq.empty()) {
    pair<int, int> top = *pq.begin();
    int distance = top.first;
    int u = top.second;
    pq.erase(pq.begin());

    for(auto it = graph[u].begin(); it != graph[u].end(); ++it) {
      int v = it->first;
      int w = it->second;

      if(distance + w < dist[v]) {
        dist[v] = distance + w;
        parent[v] = u;
        pq.insert({dist[v], v});
      }
    }
  }
}

int main() {
  int V;
  cin >> V;

  int E;
  cin >> E;

  int src, dest;

  for(int i=0; i<E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    addEdge(u, v, w); 
  }

  cin >> src >> dest;
  dijkstra(src, dest);
  cout << "Distance to " << dest << ": " << dist[dest] << endl;
  
  return 0;
}