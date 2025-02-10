# Shortest path in Directed Acyclic Graph  
**Difficulty**: Medium 

Given a Directed Acyclic Graph of `V` vertices from `0` to `n-1` and a 2D Integer array(or vector) `edges[][]` of length `E`, where there is a directed edge from `edge[i][0]` to `edge[i][1]` with a distance of `edge[i][2]` for all `i`.  

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return `-1` for that vertex.  

**Examples** :  

Input: V = 4, E = 2, edges = [[0,1,2], [0,2,1]]  
Output: [0, 2, 1, -1]  
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, so it's -1 for 3.  

Input: V = 6, E = 7, edges = [[0,1,2], [0,4,1], [4,5,4], [4,2,2], [1,2,3], [2,3,6], [5,3,1]]  
Output: [0, 2, 3, 6, 1, 5]  
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3. Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6. Shortest path from 0 to 4 is 0->4 with edge weight 1.Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.  

**Constraint**:  
1 <= V <= 100  
1 <= E <= min((N*(N-1))/2,4000)  
0 <= edgesi,0, edgesi,1 < n  
0 <= edgei,2 <=105  

# Solution
  `C++` `Topological Sort (Using Stack)` `Adjacency List` `Relaxation using Topological Order` `DFS for Topological Sorting`  
```cpp
class Solution {
    void topoSort(int i, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st) {
        vis[i] = 1;
        for (auto it : adj[i]) {
            int node = it.first;
            if (!vis[node])
                topoSort(node, adj, vis, st);
        }
        st.push(i);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[V];
        // Build adjacency list
        for (int i = 0; i < E; i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        vector<int> vis(V, 0);
        stack<int> st;
        // Perform topological sort
        for (int i = 0; i < V; i++) {
            if (!vis[i]) topoSort(i, adj, vis, st);
        }
        vector<int> res(V, INT_MAX);
        res[0] = 0;

        // Relaxation step
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (res[node] != INT_MAX) {
                for (auto it : adj[node]) {
                    int v = it.first, wt = it.second;
                    if (res[node] + wt < res[v]) {
                        res[v] = res[node] + wt;
                    }
                }
            }
        }
        // Replace INT_MAX with -1 for unreachable nodes
        for (int i = 0; i < V; i++) {
            if (res[i] == INT_MAX) res[i] = -1;
        }

        return res;
    }
};
```
## Key Techniques:
- **Graph Representation**: vector<pair<int, int>> adj[V] (Adjacency List) to store directed edges with weights.  
- **Topological Sorting**: DFS-based ordering ensures nodes are processed only after dependencies.  
- **Relaxation in Topological Order**: Updates shortest distances efficiently in O(V+E) time.  
- **Handling Unreachable Nodes**: INT_MAX is replaced with -1 for nodes with no valid path.  

