# [Undirected Graph Cycle](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)  
### Problem: Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether the graph contains any cycle or not. The Graph is represented as an adjacency list, where adj[i] contains all the vertices that are directly connected to vertex i.


**NOTE**: The adjacency list represents undirected edges, meaning that if there is an edge between vertex i and vertex j, both j will be adj[i] and i will be in adj[j].

**Examples**:

**Input**: adj = [[1], [0,2,4], [1,3], [2,4], [1,3]] 

**Output**: 1

**Explanation**:

![image](https://github.com/user-attachments/assets/881ac43f-5d7c-44de-877a-6ee457f7db0c)

1->2->3->4->1 is a cycle.

# C++ Solution:
## 1. Using BFS
```cpp
class Solution {
    private:
    bool detectCycles(int src, vector<vector<int>> &adj, vector<int> &vis){
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int adjNode : adj[node]) {
                if (!vis[adjNode]) {  
                    vis[adjNode] = 1;
                    q.push({adjNode, node});
                } 
                else if (adjNode != parent) {
                    return true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(detectCycles(i,adj,vis)) return true;
            }
        }
        
        return false;
    }
};
```
--- 
## 2. Using DFS
```cpp
class Solution {
    bool dfs(int node, int parent,vector<vector<int>>& adj, vector<int> &vis){
        vis[node] = 1;
        for(int adjNode: adj[node]){
            if(!vis[adjNode]){
               if (dfs(adjNode, node, adj, vis) == true) return true;
            }
            else if( adjNode != parent) return true;
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n,0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {  
                if (dfs(i, -1, adj, vis)) 
                    return true;
            }
        }
        return false; 
    }
};
```
<p>
  
  **Time Complexity**: O(N + 2E) + O(N).
  
  **Space Complexity**: O(N) + O(N).
</p>
