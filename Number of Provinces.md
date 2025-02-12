# [Number of Provinces](https://www.geeksforgeeks.org/problems/number-of-provinces/1)  
**Difficulty**: Medium  

Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.  

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.  

**Example** 1:  

Input:  
[  
 [1, 0, 1],  
 [0, 1, 0],  
 [1, 0, 1]  
]   

  <img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/706298/Web/Other/763b704c-74af-4d7c-8457-a1b8fe00a077_1685087210.png" height="200" >

Output:2  
Explanation:  
The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.  

**Example 2**:  
Input:  
[  
 [1, 1],  
 [1, 1]  
]  

  <img src="https://github.com/user-attachments/assets/5fbfed50-1884-4150-825d-d77fbb86c532" height="100" >  

Output : 1  

**Your Task**:    
You don't need to read input or print anything. Your task is to complete the function numProvinces() which takes an integer V and an adjacency matrix adj(as a 2d vector) as input and returns the number of provinces. adj[i][j] = 1, if nodes i and j are connected and adj[i][j] = 0, if not connected.  

**Expected Time Complexity**: O(V2)  
**Expected Auxiliary Space**: O(V)  

**Constraints**:  
1 ≤ V ≤ 500  

# Solution:
### 1. Using DFS:
       `C++` `Graph` `DFS`  
```cpp
class Solution {
    void dfs(int x, vector<int> adj[], vector<int> &vis){
        vis[x] = 1;
        for(int node: adj[x]){
            if(!vis[node]){
                vis[node] = 1;
                dfs(node, adj,vis);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjList[V];
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j] == 1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int proviences = 0;
        vector<int> vis(V,0);
        for(int i=0; i<V;i++){
            if(!vis[i]){
                proviences++;
                dfs(i, adjList, vis);
            }
        }
        return proviences;
        
    }
};
```

### 2. Using BFS:
       `C++` `Graph` `BFS`  
```cpp
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjList[V];
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                }
            }
        }
        int provinces = 0;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                queue<int> q;
                q.push(i);
                vis[i] = 1;
    
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
    
                    for (int adjNode : adjList[node]) {
                        if (!vis[adjNode]) {
                            q.push(adjNode);
                            vis[adjNode] = 1;
                        }
                    }
                }
                provinces++;
            }
        }
    
        return provinces;
    }
};
```
