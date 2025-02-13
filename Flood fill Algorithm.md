# Flood fill Algorithm  
**Difficulty**: Medium  

An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.  

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.  

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the new color.  

**Examples**:  

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2  
Output: [[2,2,2],[2,2,0],[2,0,1]]  
Explanation: From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected by a path of the same color as the starting pixel are colored with the new color.Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.  

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 0  
Output: [[0,0,0],[0,0,0]]  
Explanation: The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.  

Input: image = [[0,0,0],[0,0,0]], sr = 1, sc = 1, newColor = 0  
Output: [[0,0,0],[0,0,0]]  
Explanation: The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.  

**Constraints**:
1 <= n <= m <= 500  
0 <= pixel values <= 10  
0 <= newColor <= 10  
0 <= sr <= (n-1)  
0 <= sc <= (m-1)  

# Solution:
  `C++` `Graph` `BFS` `Flood-fill Algorithm`  
```cpp
class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int m = image.size(), n = image[0].size();
        
        int initial_color = image[sr][sc];
        if (initial_color == newColor) return image;
    
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
        while (!q.empty()) {
            pair<int,int> current = q.front();
            q.pop();
    
            for (auto dir : directions) {
                int x = current.first + dir.first;
                int y = current.second + dir.second;
                if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == initial_color) {
                    image[x][y] = newColor;
                    q.push({x, y});
                }
            }
        }
    
        return image;
    }
};
```
