# Number of Distinct Islands  
**Difficulty: Medium**  
**Problem**:  
Given a boolean 2D matrix grid of size `n * m`. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).  

**Example 1**:  

Input:  
```cpp
grid[][] = {{1, 1, 0, 0, 0},  
            {1, 1, 0, 0, 0},  
            {0, 0, 0, 1, 1},  
            {0, 0, 0, 1, 1}}  
```
Output: 1  
Explanation:  
```cpp
grid[][] = {{1, 1, 0, 0, 0},   
            {1, 1, 0, 0, 0},  
            {0, 0, 0, 1, 1},  
            {0, 0, 0, 1, 1}}  
```
Same colored islands are equal.We have 2 equal islands, so we have only 1 distinct island.  

**Your Task**:
You don't need to read or print anything. Your task is to complete the function countDistinctIslands() which takes the grid as an input parameter and returns the total number of distinct islands.  

Expected Time Complexity: O(n * m)  
Expected Space Complexity: O(n * m)  

**Constraints**:
1 ≤ n, m ≤ 500  
grid[i][j] == 0 or grid[i][j] == 1  

# Solution: (C++)
```cpp
class Solution {
    void bfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int,int>> &shape){
        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        int baseX = i, baseY = j;
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            shape.push_back({x-baseX,y-baseY});
            for(auto d: dir){
                int nx = x + d.first, ny = y + d.second;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                    !vis[nx][ny] && grid[nx][ny] == 1) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    } 
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int,int>>> islands;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    vector<pair<int, int>> shape;
                    bfs(i, j, grid, vis, shape);
                    islands.insert(shape);
                }
            }
        }
        return islands.size();
    }
};
```
**Approach**: Count Distinct Islands using BFS.  
We identify unique islands in a grid by storing their relative shapes using BFS.  

- Steps:  
  1. Initialize a set islands to store unique island shapes.  
  2. Traverse the grid:  
      - If grid[i][j] == 1 and not visited, start BFS.  
      - Store relative positions (x - baseX, y - baseY) in shape.  
  3. Use BFS to explore the island:  
      - Mark cells as visited.  
      - Push neighboring land cells (nx, ny) into the queue.  
  4. Insert shape into set (ensures only distinct islands are counted).  
  5. Return set.size(), representing distinct islands.  

- Complexity:  
Time: O(m × n) (each cell is processed once)  
Space: O(k) (storing k unique island shapes)  
