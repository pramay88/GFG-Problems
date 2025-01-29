# Distance of nearest cell having 1.
**Difficulty**: Medium
## Problem: 
Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1. There should be atleast one 1 in the grid.

**Example 1**:

Input: 

grid = [[0,1,1,0], [1,1,0,0], [0,0,1,1]]

Output: 

[[1,0,0,1], [0,0,1,1], [1,1,0,0]]

Explanation: 

The grid is-

0 1 1 0 
1 1 0 0 
0 0 1 1 

- 0's at (0,0), (0,3), (1,2), (1,3), (2,0) and (2,1) are at a distance of 1 from 1's at (0,1), (0,2), (0,2), (2,3), (1,0) and (1,1) respectively.

![image](https://github.com/user-attachments/assets/6e674f2c-6377-4d59-8a38-1920bd45bf2d)

**Yout Task**:
You don't need to read or print anything, Your task is to complete the function nearest() which takes the grid as an input parameter and returns a matrix of the same dimensions where the value at index (i, j) in the resultant matrix signifies the minimum distance of 1 in the matrix from grid[i][j].

**Constraints**:
1 ≤ n, m ≤ 500.
---
# Solution:
```cpp
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n,0));
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[x][y] = steps;
            vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
            for(auto d: dir){
                int nx = x + d.first, ny = y + d.second;
                if(nx>=0 && nx<m && ny>=0 && ny<n && vis[nx][ny] == 0){
                    vis[nx][ny] = 1;
                    dist[nx][ny] = steps + 1;
                    q.push({{nx,ny}, steps+1});
                }
            }
        }
        return dist;
    }
};
```
---
  **Time Complexity**: O(n*m).
  
  **Space Complexity**: O(n*m).
