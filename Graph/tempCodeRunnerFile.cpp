#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<string, int>>> &vec, int vertices, int edges, string source) {

    unordered_map<string, list<pair<string, int>>> adjacencyList;
    unordered_map<string, int> distances;
    unordered_map<string, bool> processed;

    for(int i=0; i<edges; i++) {
        string startNode = vec[i][0].first;
        string endNode = vec[i][1].first;
        int weight = vec[i][1].second;

        adjacencyList[startNode].push_back(make_pair(endNode, weight));
        adjacencyList[endNode].push_back(make_pair(startNode, weight));
    }  

    for(auto &i : adjacencyList) {
        distances[i.first] = INT_MAX;
    }

    distances[source] = 0;

    while(!adjacencyList.empty()) {
        string smallestNode = min_element(distances.begin(), distances.end(), 
        [](const pair<string, int> &p1, const pair<string, int> &p2) {
            return p1.second < p2.second;
        })->first;

        processed[smallestNode] = true;
        distances.erase(smallestNode);

        for(auto neighbor: adjacencyList[smallestNode]) {
            if(processed[neighbor.first]) continue;
            distances[neighbor.first] = min(distances[neighbor.first], distances[smallestNode] + neighbor.second);
        }
    }

    vector<string> result;
    for(auto &i : distances) {
        result.push_back(i.second);
    }

    return result;
}

int main() {

    int v, e;

    cin>>v>>e;
    
    string source;
    cin >> source;

    vector<vector<pair<string, int>>> graph(e, vector<pair<string, int>>(2));

    for(int i=0; i<e; i++) {
        cin>>graph[i][0].first>>graph[i][1].first>>graph[i][1].second;
    }


    vector<int> dist = dijkstra(graph, v, e, source);

    for(int i=0; i<dist.size(); i++) {
        cout<<dist[i]<<" ";
    }

    cout<<endl;

    return 0;
}