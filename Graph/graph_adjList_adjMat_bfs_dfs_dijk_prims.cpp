#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> createAdjList(int vertex, int edges){
  vector<vector<pair<int, int>>> adjList(vertex);
  
  int u, v, w;
  for(int i=0; i<edges; i++){
    cin >> u >> v >> w;
    adjList[u].push_back({v, w});
    adjList[v].push_back({u, w});
  }
  return adjList;
}

// void printAdjList(vector<vector<pair<int, int>>>& adjList){
//   int vertex = adjList.size();
//   for(int i=0; i<vertex; i++){
//     cout << i << " -> ";
//     for(int j=0; j<adjList[i].size(); j++){
//       cout << "(" << adjList[i][j].first << "," << adjList[i][j].second << ") ";
//     }
//     cout << endl;
//   }
// }

vector<int> bfs(vector<vector<int>>& adjList){
  int vertex = adjList.size();
  vector<int> ans;
  queue<int> q;
  vector<bool> visited(vertex, 0);
  q.push(0);
  visited[0] = 1;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    ans.push_back(node);
    
    for(int i=0; i<adjList[node].size(); i++){
      if(!visited[adjList[node][i]]){
        q.push(adjList[node][i]);
        visited[adjList[node][i]] = 1;
      }
    }
  }
  return ans;
}

void dfsHelper(int node, vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& ans){
  visited[node] = 1;
  ans.push_back(node);
  for(int i=0; i<adjList[node].size(); i++){
    if(!visited[adjList[node][i]]){
      dfsHelper(adjList[node][i], adjList, visited, ans);
    }
  }
}

vector<int> dfs(vector<vector<int>>& adjList){
  int vertex = adjList.size();
  vector<bool> visited(vertex, 0);
  vector<int> ans;
  int node = 0;
  dfsHelper(node, adjList, visited, ans);
  return ans;
}

int prims(vector<vector<pair<int, int>>> adjList){
  int vertex = adjList.size();
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<bool> visited(vertex, 0);
  int ans = 0;
  pq.push({0,0});
  while(!pq.empty()){
    auto [wt, u] = pq.top();
    pq.pop();
    
    if(visited[u]) continue;
    ans += wt;
    visited[u] = 1;
    
    for(auto [v, w]: adjList[u]){
      if(!visited[v]){
        pq.push({w, v});
      }
    }
  }
  cout << ans;
  return ans;
}

vector<int> dijkstra(vector<vector<pair<int, int>>>& adjList){
  int vertex = adjList.size();
  vector<int> distance(vertex, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0,0});
  distance[0] = 0;
  
  while(!pq.empty()){
    auto [dist_u, u] = pq.top();
    pq.pop();
    
    if(dist_u > distance[u]) continue;
    
    for(auto [v, wt]: adjList[u]){
      if(distance[u] + wt < distance[v]){
        distance[v] = distance[u] + wt;
        pq.push({distance[v], v});
      }
    }
  }
  return distance;
}

int main () {
  int vertex, edges;
  cin >> vertex >> edges;
  vector<vector<pair<int, int>>> adjList = createAdjList(vertex, edges);
  // vector<int> ans = bfs(adjList);
  // for(int i=0; i<ans.size(); i++){
  //   cout << ans[i] << " ";
  // }
  // printAdjList(adjList);
  // vector<int> dfsTraversal = dfs(adjList);
  // for(auto i: dfsTraversal){
  //   cout << i << " ";
  // }
  // prims(adjList);
  vector<int> dijAns = dijkstra(adjList);
  for(auto i: dijAns){
    cout << i << " ";
  }
  
  
  return 0;
}