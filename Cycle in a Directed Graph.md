# [Cycle in a Directed Graph](https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph)
**Difficulty**: Medium  
**Problem**:
Given a Directed Graph with `V` vertices (Numbered from `0` to `V-1`) and `E` edges, check whether it contains any cycle or not.  
The graph is represented as an adjacency list, where `adj[i]` contains a list of vertices that are directly reachable from vertex `i`. Specifically, `adj[i][j]` represents an edge from vertex `i` to vertex `j`.  

**Example 1**:  
**Input**:  

![image](https://github.com/user-attachments/assets/f91f6b6a-00f4-4473-99c5-cf70dbf3127d)  

**Output**: 1  
**Explanation**: 3 -> 3 is a cycle  

**Constraints**:  
1 ≤ V, E ≤ 105  

## Solution: 

1. **DFS**  
   `C++` `DFS` `Recursion` `Backtracking`  

```cpp
class Solution {
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis){
        vis[node] = 1, pathVis[node] = 1;
        for(auto adjNode: adj[node]){
            if(vis[adjNode] == 0){
                if(dfs(adjNode, adj, vis, pathVis) == true) return true;
            }
            else if(pathVis[adjNode]) return true;
        }
        pathVis[node] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int> vis(V, 0);
        vector<int> pathVis(V,0);
        for(int i=0; i<V; i++){
            if(vis[i] == 0){
                if(dfs(i, adj, vis, pathVis) == true) return true;
            }
        }
        return false;
    }
};
```


2. **Using Kahn’s Algorithm (BFS-Based Topological Sorting)**.  
   `C++` `Kahn’s Algorithm` `BFS` `Topological Sorting`  
```cpp
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        int m = adj.size();
        vector<int> indegree(m, 0);
        for (int i = 0; i < m; i++) {
            for (int it : adj[i]) 
                indegree[it]++;
        }
        queue<int> q;
        for (int i = 0; i < m; i++) {
            if (indegree[i] == 0) 
                q.push(i);
        }
        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (int it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) 
                    q.push(it);
            }
        }
        return count < m;
    }
};
```
