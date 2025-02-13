# [Replace O's with X's](https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1)  
**Difficulty**: Medium

Given a matrix mat where every element is either 'O' or 'X'. Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.  

A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.  

**Examples**:  

Input: mat =   
[['X', 'X', 'X', 'X'],   
['X', 'O', 'X', 'X'],   
['X', 'O', 'O', 'X'],   
['X', 'O', 'X', 'X'],   
['X', 'X', 'O', 'O']]  
Output:   
[['X', 'X', 'X', 'X'],   
['X', 'X', 'X', 'X'],   
['X', 'X', 'X', 'X'],   
['X', 'X', 'X', 'X'],   
['X', 'X', 'O', 'O']]  
Explanation: We only changed those 'O' that are surrounded by 'X'  

Input: mat =   
[['X', 'O', 'X', 'X'],   
['X', 'O', 'X', 'X'],   
['X', 'O', 'O', 'X'],   
['X', 'O', 'X', 'X'],   
['X', 'X', 'O', 'O']]  
Output:   
[['X', 'O', 'X', 'X'],   
['X', 'O', 'X', 'X'],   
['X', 'O', 'O', 'X'],   
['X', 'O', 'X', 'X'],   
['X', 'X', 'O', 'O']]  
Explanation: There's no 'O' that's surround by 'X'.  

Input: mat =   
[['X', 'X', 'X'],   
['X', 'O', 'X'],   
['X', 'X', 'X']]  
Output:   
[['X', 'X', 'X'],   
['X', 'X', 'X'],   
['X', 'X', 'X']]  
Explanation: There's only one 'O' that's surround by 'X'.  

**Constraints**:  
1 ≤ mat.size() ≤ 100  
1 ≤ mat[0].size() ≤ 100  

# Solution:
  `C++` `BFS` `Graph`
```cpp
class Solution {
  public:
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && mat[i][j] == 'O') {
                    mat[i][j] = '#';
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (auto d : dir) {
                int nx = x + d.first, ny = y + d.second;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && mat[nx][ny] == 'O') {
                    mat[nx][ny] = '#';
                    q.push({nx, ny});
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                } else if (mat[i][j] == '#') {
                    mat[i][j] = 'O';
                }
            }
        }
        return mat;
    }
```
