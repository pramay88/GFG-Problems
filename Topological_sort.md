# [Topological sort](https://www.geeksforgeeks.org/problems/topological-sort/1)  
**Difficulty**: Medium  

**Problem**:  
Given an adjacency list for a _Directed Acyclic Graph_ (DAG) where `adj[u]` contains a list of all vertices `v` such that there exists a directed edge `u -> v`. Return topological sort for the given graph.  

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.  
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be 1 else 0.

**Examples**:  
**Input**: adj = [[], [0], [0], [0]]  

![image](https://github.com/user-attachments/assets/e241e37c-5326-4d05-b021-937c99b84ce2)  

**Output**: 1  
**Explanation**: The output 1 denotes that the order is valid. Few valid Topological orders for the given graph are:  
[3, 2, 1, 0]  
[1, 2, 3, 0]  
[2, 3, 1, 0]  

**Constraints**:  
2  ≤  V  ≤  103  
1  ≤  E  ≤  (V * (V - 1)) / 2  

# Solution:
`C++` `DFS` `Topoloogical sort` 
```cpp
class Solution {
    void dfs(int node, vector<vector<int>>& adj, int vis[], stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it])
                dfs(it, adj, vis, st);
        }
        st.push(node);
    }
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int m = adj.size();
        int vis[m] = {0};
        stack<int> st;

        for (int i = 0; i < m; i++) {
            if (!vis[i])
                dfs(i, adj, vis, st);
        }

        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
```
