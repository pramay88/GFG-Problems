# [Bipartite Graph](https://www.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph)
**Difficulty:** Medium

**Problem**: Given an adjacency list of a graph adj. Check whether the graph is bipartite or not.  

A [bipartite graph](https://www.geeksforgeeks.org/what-is-bipartite-graph/) can be colored with two colors such that no two adjacent vertices share the same color. This means we can divide the graph’s vertices into two distinct sets where:
  - All edges connect vertices from one set to vertices in the other set.
  - No edges exist between vertices within the same set.  

**Examples**:
Input: adj = [[2, 3], [2], [0, 1, 3], [0, 2]].  

![image](https://github.com/user-attachments/assets/a6198ae0-a5a0-4b56-a46d-4e6a22284a89)  

Output: false.  
Explanation: The given graph cannot be colored in two colors such that color of adjacent vertices differs.  

**Constraints**:  
1 ≤ adj.size() ≤ 104  
1 ≤ adj[i][j] ≤ 104  

## Solution: C++
```cpp
class Solution {
    bool check(int i, vector<vector<int>> &adj, vector<int> &color){
        int m = adj.size();
        queue<int> q;
        q.push(i);
        color[i] = 0; 
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto adjNode : adj[node]) {
                if (color[adjNode] == -1) {  
                    color[adjNode] = 1 - color[node];
                    q.push(adjNode);
                } 
                else if (color[adjNode] == color[node]) { 
                    return false;
                }
            }
        }
        return true;
    }
  public:
        bool isBipartite(vector<vector<int>>& adj) {
            int m = adj.size();
            vector<int> color(m, -1);
            
            for (int i = 0; i < m; i++) {
                if (color[i] == -1) {  // Start BFS for unvisited nodes
                    if (!check(i, adj, color)) return false;
                }
            }
            return true;
        }
};
```

## Approach:
1. Initialize a color array (-`1` means unvisited).
2. For each unvisited node, run BFS:
    - Assign it color = `0`.
    - Traverse neighbors, assigning them the opposite color (`1 - color[node]`).
    - If any adjacent nodes have the same color, return `false` (not bipartite).
3. If all nodes are properly colored, return `true` (bipartite graph).  
This ensures two-colorability, a key property of bipartite graphs. 🚀
