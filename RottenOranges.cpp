/*
===========================================================
||                    Rotten Oranges                     ||
===========================================================

Problem link : https://www.geeksforgeeks.org/problems/rotten-oranges2536/1
Difficulty: Medium 

Problem:
Given a matrix where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index [i, j] can rot other fresh orange at indexes 
[i-1, j], [i+1, j], [i, j-1], [i,j+1] (up, down, left and right) in unit time.

Note: Your task is to return the minimum time to rot all the fresh oranges. If not possible returns -1.

Examples:

1.Input: mat[][] = 
  [[0, 1, 2], 
  [0, 1, 2], 
  [2, 1, 1]]
  Output: 1
  Explanation: Oranges at positions (0,2), (1,2), (2,0) will rot oranges at (0,1), (1,1), (2,2) and (2,1) in unit time.

2.Input: mat[][] = [[2, 2, 0, 1]]
  Output: -1
  Explanation: Oranges at (0,0) and (0,1) can't rot orange at (0,3).

Constraints:
  1 ≤ mat.size() ≤ 500
  1 ≤ mat[0].size() ≤ 500
  mat[i][j] = {0, 1, 2} 
*/
class Solution {
  public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
            }
        }
        int time = 0;
        vector<pair<int,int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);
            for(auto dir: directions){
                int nr = r + dir.first;
                int nc = c + dir.second;
                if(nr>=0 && nr<m && nc>=0 && nc<n && mat[nr][nc] == 1 && vis[nr][nc] == 0){
                    q.push({{nr,nc},t+1});
                    vis[nr][nc] = 2;
                    
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j]!= 2 && mat[i][j] == 1) return -1;
            }
        }
        return time;   
    }
};
