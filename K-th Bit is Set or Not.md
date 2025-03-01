# K-th Bit is Set or Not  
**Difficulty**: Easy  

Given a number n and a bit number k, check if the kth index bit of n is set or not. A bit is called set if it is 1. The position of set bit '1' should be indexed starting with 0 from the LSB side in the binary representation of the number.  

**Note**: Index is starting from 0. You just need to return true or false.  

**Examples** : 
<pre>
Input: n = 4, k = 0
Output: false
Explanation: Binary representation of 4 is 100, in which 0th index bit from LSB is not set. So, return false.
</pre>
<pre>
Input: n = 4, k = 2
Output: true
Explanation: Binary representation of 4 is 100, in which 2nd index bit from LSB is set. So, return true.
</pre>
<pre>
Input: n = 500, k = 3
Output: false
Explanation: Binary representation of 500 is 111110100, in which 3rd index bit from LSB is not set. So, return false.
</pre>

**Constraints**:
1 ≤ n ≤ 109  
0 ≤ k ≤ 31  

# Solution: 
  `c++` `Bit-Manipulation`  

```cpp
class Solution {
  public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k) {
        return (n>>k) & 1;
    }
};
```
  
