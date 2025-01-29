# BFS of Graph
## Problem:
Given a undirected graph represented by an adjacency list adj, which is a vector of vectors where each adj[i] represents the list of vertices connected to vertex i. Perform a Breadth First Traversal (BFS) starting from vertex 0, visiting vertices from left to right according to the adjacency list, and return a list containing the BFS traversal of the graph.

**Note**: Do traverse in the same order as they are in the adjacency list.

**Examples**:

![image](https://github.com/user-attachments/assets/6ac0f6c0-d0a6-4c03-971e-d37e3ee95148)

**Output**: [0, 2, 3, 1, 4]

**Explanation**: Starting from 0, the BFS traversal will follow these steps: 

Visit 0 → Output: 0 

Visit 2 (first neighbor of 0) → Output: 0, 2 

Visit 3 (next neighbor of 0) → Output: 0, 2, 3 

Visit 1 (next neighbor of 0) → Output: 0, 2, 3, 

Visit 4 (neighbor of 2) → Final Output: 0, 2, 3, 1, 4

**Constraints**: 

1 ≤ adj.size() ≤ 104

1 ≤ adj[i][j] ≤ 104

# C++ Solution: 
```cpp
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> ans;
        queue<int> q;
    
        q.push(0);
        vis[0] = 1;
    
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
    
            for (int neighbor : adj[node]) {  
                if (!vis[neighbor]) {
                    q.push(neighbor);
                    vis[neighbor] = 1;
                }
            }
        }
        return ans;
    }
};
