# [Prerequisite Tasks](https://www.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks)  
**Difficulty**: Medium  

**Problem:**  
There are a total of `N` tasks, labeled from `0` to `N-1`. Some tasks may have prerequisites, for example to do task `0` you have to first complete task `1`, which is expressed as a pair: `[0, 1]`
Given the total number of tasks `N` and a list of `P` prerequisite pairs, find if it is possible to finish all tasks.  

**Examples**:  

**Input**: N = 4, P = 3, prerequisites = [[1,0],[2,1],[3,2]]  
**Output**: Yes  
**Explanation**: To do task `1` you should have completed task `0`, and to do task `2` you should have finished task `1`, and to do task `3` you should have finished task `2`. So it is possible.

**Constraints**:  
1 ≤ N ≤ 104  
1 ≤ P ≤ 105  

# Solution:    
  `C++` `Kahn’s Algorithm` `BFS` `BFS-based Topological Sorting`  
```cpp
class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        vector<int> adj[N];
        for(auto it: prerequisites){
            adj[it.first].push_back(it.second);
        }
    
        vector<int> indegree(N, 0);
        for(int i = 0; i < N; i++) {
            for(auto it: adj[i])
                indegree[it]++;
        }
    
        queue<int> q;
        for(int i = 0; i < N; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
    
        int count = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for(auto it: adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        return count == N;
    }
};
```
