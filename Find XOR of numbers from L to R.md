# [Find XOR of numbers from L to R.](https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/0)
**Difficulty**: Easy  

You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].  

**Example**:  
<pre>
Input: 
L = 4, R = 8 
Output:
8 
Explanation:
4 ^ 5 ^ 6 ^ 7 ^ 8 = 8
</pre>

**Your Task**:  
Your task is to complete the function findXOR() which takes two integers l and r and returns the XOR of numbers from l to r.  

Expected Time Complexity: O(1).  

Expected Auxiliary Space: O(1).  

**Constraints**:  
1<=l<=r<=109

# Solution:
  `C++` `Bit-Manipulation`

```cpp
class Solution {
  public:
    int XOR(int n){
        if(n % 4 == 1) return 1;
        else if(n % 4 == 2) return n + 1;
        else if(n % 4 == 3 ) return 0;
        else return n;
    }
    int findXOR(int l, int r) {
        return XOR(l-1) ^ XOR(r);
    }
};
```

<pre>
  XOR(l,r) = XOR(0,r) ⊕ XOR(0,l−1)
</pre>
