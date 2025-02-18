# [Factorial](https://www.geeksforgeeks.org/problems/factorial5739/1)  
**Difficulty**: Basic  

Given a positive integer, n. Find the factorial of n.  

**Examples** :  

<pre>
Input: n = 5  
Output: 120  
Explanation: 1 x 2 x 3 x 4 x 5 = 120  
</pre>
<pre>
Input: n = 4  
Output: 24  
Explanation: 1 x 2 x 3 x 4 = 24  
</pre>
**Constraints**:  
0 <= n <= 12  

# Solution:

## 1. Recursive:
  `C++` `Recursive`  
```cpp
class Solution {
  public:
    int factorial(int n) {
        return (n==0)? 1: n*factorial(n-1);
    }
};
```
#### Complexities:
  - Time Complexity: O(n) → n recursive calls, each taking constant time.  
  - Space Complexity: O(n) → Due to the recursive call stack (each call stored until the base case is reached).
🔴 Not optimal due to O(n) space usage (stack calls).
---
## 2. Iterative  
  `C++` `Iterative`  
```cpp
class Solution {
  public:
    int factorial(int n) {
        int result = 1;
        for(int i=2; i<=n; i++)
            result *= i;
        return result;
    }
};
```

### Complexities:  
  - Time Complexity: O(n) → n iterations.  
  - Space Complexity: O(1) → No recursion, only a few variables.  
✅ Best choice for a single function call (no risk of stack overflow).

---

## 3. Recursive Factorial with Memoization (Optimal for Multiple Calls)
  `C++` 
```cpp
class Solution {
  public:
    static vector<long long> dp;
    long long factorialDP(int n) {
        if (n == 0) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = n * factorialDP(n - 1);
    }
    int factorial(int n) {
        return factorialDP(n);
    }
};
vector<long long> Solution::dp(101, -1);
```
### Complexities  
  - Time Complexity: O(n) → Each value is computed once and stored.  
  - Space Complexity: O(n) → Stores results in an array (dp array).  
✅ Efficient if calling factorial multiple times (e.g., dynamic programming problems).
---
## Summary Table:  
![image](https://github.com/user-attachments/assets/fcec7e88-d8d1-4f1f-b48d-48323e8c1746)  

