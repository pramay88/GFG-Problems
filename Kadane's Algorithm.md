# [Kadane's Algorithm](https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1)  
**Difficulty**: Medium  

Given an integer array arr[]. You need to find the maximum sum of a subarray.  

**Examples**:  
<pre>
Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
Output: 11
Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.
</pre>
<pre>
Input: arr[] = [-2, -4]
Output: -2
Explanation: The subarray {-2} has the largest sum -2.
</pre>
<pre>
Input: arr[] = [5, 4, 1, 7, 8]
Output: 25
Explanation: The subarray {5, 4, 1, 7, 8} has the largest sum 25.
</pre>

**Constraints**:  
1 ≤ arr.size() ≤ 105  
-109 ≤ arr[i] ≤ 104  

# Solution:
  `C++`

```cpp
class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int maxSum = INT_MIN, currSum = 0;
        for(int n: arr){
            currSum = max(n, currSum + n);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
```

### [Video Solution](https://www.youtube.com/embed/AHZpyENo7k4?si=2VB8jEiLnyjPQVf0)  


