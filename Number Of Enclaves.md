# [Number Of Enclaves](https://www.geeksforgeeks.org/problems/number-of-enclaves/1)
**Difficulty: Medium**  
## Problem:  
You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.  
A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.  
Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.  

**Example 1**:  
**Input**:  
grid[][] =  
{{0, 0, 0, 0},  
            {1, 0, 1, 0},  
            {0, 1, 1, 0},  
            {0, 0, 0, 0}}  
**Output**:  
3  
**Explanation**:  
0 0 0 0  
1 0 1 0  
0 1 1 0  
0 0 0 0  
The highlighted cells represents the land cells.  

**Your Task**:  
You don't need to print or input anything. Complete the function numberOfEnclaves() which takes a 2D integer matrix grid as the input parameter and returns an integer, denoting the number of land cells.  
  
Expected Time Complexity: O(n * m)  

Expected Space Complexity: O(n * m)  

**Constraints**:  

1 <= n, m <= 500  
grid[i][j] == 0 or 1  

# Solution: (C++)
```cpp
class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && (i == 0 || j == 0 || i == m - 1 || j == n - 1)) {
                    q.push({i, j});
                    vis[i][j] = 1; 
                }
            }
        }
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            for (auto dir : directions) {
                int nx = x + dir.first, ny = y + dir.second;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1 && !vis[nx][ny]) {
                    q.push({nx, ny});
                    vis[nx][ny] = 1; 
                }
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};
```
