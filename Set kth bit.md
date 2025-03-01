# [Set kth bit](https://www.geeksforgeeks.org/problems/set-kth-bit3724/1)  
**Difficulty**: Basic  

Given a number n and a value k. From the right, set the kth bit in the binary representation of n. The position of the Least Significant Bit(or last bit) is 0, the second last bit is 1 and so on.   

**Examples**:  
<pre>
Input: n = 10, k = 2
Output: 14
Explanation: Binary representation of the given number 10 is: 1 0 1 0, number of bits in the binary reprsentation is
             4. Thus 2nd bit from right is 0. The number after changing this bit to 1 is: 14(1 1 1 0).
</pre>
<pre>
Input: n = 15, k = 3
Output: 15
Explanation: The binary representation of the given number 15 is: 1 1 1 1, number of bits in the binary representation
             is 4. Thus 3rd bit from the right is 1. The number after changing this bit to 1 is 15(1 1 1 1).
</pre>

**Constraints**:  
1 <= n <= 109   
0 <= k < x, where x is the number of bits in the binary representation of n.  

# Solution: 
  `C++` `Bit-Manipulation`  

```cpp
class Solution {
  public:
    int setKthBit(int n, int k) {
        return n | (1<<k);
    }
};
```
