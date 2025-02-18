# [Binary Search](https://www.geeksforgeeks.org/problems/binary-search-1587115620/1)  
**Difficulty**: Easy    

Given a sorted array arr and an integer k, find the position(0-based indexing) at which k is present in the array using binary search.  
Note: If multiple occurrences are there, please return the smallest index.  

**Examples**:  
<pre>
Input: arr[] = [1, 2, 3, 4, 5], k = 4  
Output: 3  
Explanation: 4 appears at index 3.  
</pre>
<pre>
Input: arr[] = [11, 22, 33, 44, 55], k = 445  
Output: -1  
Explanation: 445 is not present. 
</pre>
<pre>
Input: arr[] = [1, 1, 1, 1, 2], k = 1  
Output: 0  
Explanation: 1 appears at index 0.  
</pre>
Note: *Try to solve this problem in constant space i.e O(1)*  

**Constraints**:  
1 <= arr.size() <= 105  
1 <= arr[i] <= 106  
1 <= k <= 106  

# Solution :
  `C++` `Binary-Search`

```cpp
class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        int left = 0, right = arr.size() - 1, result = -1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(arr[mid] == k){
                result = mid;
                right = mid - 1;
            }
            else if(arr[mid] > k) right = mid - 1;
            else left = mid + 1;
        }
        return result;
    }
};
```
