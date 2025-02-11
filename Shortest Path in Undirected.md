# [Shortest Path in Undirected](https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance)  
**Difficulty**: Medium  

You are given an adjacency list, adj of Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.  

**Examples** :  

Input: adj[][] = [[1, 3], [0, 2], [1, 6], [0, 4], [3, 5], [4, 6], [2, 5, 7, 8], [6, 8], [7, 6]], src=0  
Output: [0, 1, 2, 1, 2, 3, 3, 4, 4]  

![image](https://github.com/user-attachments/assets/949ec743-6581-4cc6-9a05-40335294e2f1)  


Input: adj[][]= [[3], [3], [], [0, 1]], src=3  
Output: [1, 1, -1, 0]  

![image](https://github.com/user-attachments/assets/56378178-e485-4879-8ea9-b29a77c39408)  



Input: adj[][]= [[], [], [], [4], [3], [], []], src=1  
Output: [-1, 0, -1, -1, -1, -1, -1]  

**Constraint**:    
1<=adj.size()<=104  
0<=edges<=adj.size()-1  

# Solution  
  `C++` `BFS` `Queue`
```cpp
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        queue<int> q;
    
        dist[src] = 0;
        q.push(src);
    
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int adjNode : adj[node]) {
                if (dist[adjNode] == INT_MAX) {
                    dist[adjNode] = dist[node] + 1;
                    q.push(adjNode);
                }
            }
        }
        
        for (int &d : dist) {
            if (d == INT_MAX) d = -1;
        }
        
        return dist;
    }
};
```
