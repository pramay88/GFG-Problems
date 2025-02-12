# Graph and Vertices  
**Difficulty**: Easy  

Given an integer n representing number of vertices. Find out how many undirected graphs (not necessarily connected) can be constructed out of a given n number of vertices.  

**Example 1**:  

Input: 2  
Output: 2  

Example 2:  

Input: 5  
Output: 1024  

**Your Task**:  
Complete the function count() which takes an integer n as input and return the count of total number of graphs possible.  


**Expected Time Complexity**: O(1)  

**Expected Space Complexity**: O(1)  

**Constraints**:
1<=n<=10

# Solution
  `C++` `Bit Manipulation`   
```cpp
class Solution {
  public:
    long long count(int n) {
        return 1LL << (n * (n-1)/2);
    }
};
```

## Why is This Optimal?  
✅ O(1) Time Complexity – Bit shifting (1LL << x) runs in constant time.  
✅ O(1) Space Complexity – Uses only a single integer variable.  
✅ No Floating-Point Precision Issues – Avoids pow(2, x), which can introduce inaccuracies.  
