#include<bits/stdc++.h>
using namespace std;


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {

  // Create an adjacency list to represent the graph
unordered_map<int, list<pair<int, int>>> adjacencyList;

// Add edges to the adjacency list
for(int i=0; i<edges; i++) {
    int startNode = vec[i][0];
    int endNode = vec[i][1];
    int weight = vec[i][2];

    adjacencyList[startNode].push_back(make_pair(endNode, weight));
    adjacencyList[endNode].push_back(make_pair(startNode, weight));
}  

// Initialize distances to all nodes as infinity
vector<int> distances(vertices, INT_MAX);

// Create a set to store nodes with their distances
set<pair<int, int>> nodeSet;

// Distance to the source node is 0
distances[source] = 0;
nodeSet.insert(make_pair(0, source));

// While there are still nodes to process
while(!nodeSet.empty()) {
    // Get the node with the smallest distance
    auto smallest = *(nodeSet.begin());

    int smallestDistance = smallest.first;
    int smallestNode = smallest.second;

    // Remove this node from the set
    nodeSet.erase(nodeSet.begin());

    // For each neighbor of the current node
    for(auto neighbor: adjacencyList[smallestNode]) {
        // If the current path to the neighbor is shorter than the previously known shortest path
        if(smallestDistance + neighbor.second < distances[neighbor.first]) {
            // Find the neighbor in the set
            auto found = nodeSet.find(make_pair(distances[neighbor.first], neighbor.first));

            // If the neighbor was found in the set, remove it
            if(found != nodeSet.end()) {
                nodeSet.erase(found);
            }

            // Update the shortest distance to the neighbor
            distances[neighbor.first] = smallestDistance + neighbor.second;

            // Add the neighbor with the new shortest distance to the set
            nodeSet.insert(make_pair(distances[neighbor.first], neighbor.first));
        }
    }
}   return distances;



}


int main() {

    int v, e, s;

    cin>>v>>e;

    vector<vector<int>> graph(e, vector<int>(3));

    for(int i=0; i<e; i++) {
        for(int j=0; j<3; j++) {
            
            cin>>graph[i][j];
            
        }
    }

    cout<<endl;

    

  vector<int> dist = dijkstra(graph, v, e, 0);

  for(int i=0; i<v; i++) {
    cout<<dist[i]<<" ";
  }

    cout<<endl;

    return 0;
}


/*

5 7
0 1 7
0 2 1
0 3 2
1 2 3
1 3 5
1 4 1
3 4 7

*/