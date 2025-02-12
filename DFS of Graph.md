# [DFS of Graph](https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/)
**Difficulty**: Easy

Given a connected undirected graph represented by an adjacency list adj, which is a vector of vectors where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Traversal (DFS) starting from vertex 0, visiting vertices from left to right as per the adjacency list, and return a list containing the DFS traversal of the graph.  

**Note**: Do traverse in the same order as they are in the adjacency list.  

**Examples**:  

Input: adj = [[2,3,1], [0], [0,4], [0], [2]]  

<img src="https://github.com/user-attachments/assets/2ec03a38-3d66-4f76-b83d-77386e805884" height="200">


Output: [0, 2, 4, 3, 1]  
Explanation: Starting from 0, the DFS traversal proceeds as follows:   
Visit 0 → Output: 0  
Visit 2 (the first neighbor of 0) → Output: 0, 2   
Visit 4 (the first neighbor of 2) → Output: 0, 2, 4  
Backtrack to 2, then backtrack to 0, and visit 3 → Output: 0, 2, 4, 3  
Finally, backtrack to 0 and visit 1 → Final Output: 0, 2, 4, 3, 1  

Input: adj = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]  

<img src="https://github.com/user-attachments/assets/db527c42-9419-4246-85d9-37783def2ab5" height="200">  

Output: [0, 1, 2, 3, 4]  
Explanation: Starting from 0, the DFS traversal proceeds as follows:   
Visit 0 → Output: 0   
Visit 1 (the first neighbor of 0) → Output: 0, 1   
Visit 2 (the first neighbor of 1) → Output: 0, 1, 2   
Visit 3 (the first neighbor of 2) → Output: 0, 1, 2, 3   
Backtrack to 2 and visit 4 → Final Output: 0, 1, 2, 3, 4   

**Constraints**:  
1 ≤ adj.size() ≤ 104  
1 ≤ adj[i][j] ≤ 104  

# Solution:
  `C++` `Graph` `DFS`  
```cpp
class Solution {
  public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &res){
        vis[node] = 1;
        res.push_back(node);
        for(int adjNode: adj[node]){
            if(!vis[adjNode])
                dfs(adjNode, adj, vis, res);
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> res;
        vector<int> vis(n, 0);
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, adj, vis, res);
            }
        }
        return res;
    }
};
```
