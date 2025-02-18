# [Selection Sort](https://www.geeksforgeeks.org/problems/selection-sort/1)  
**Difficulty**: Easy  

Given an array arr, use selection sort to sort arr[] in increasing order.  

**Examples** :  
<pre>
Input: arr[] = [4, 1, 3, 9, 7]  
Output: [1, 3, 4, 7, 9]  
Explanation: Maintain sorted (in bold) and unsorted subarrays. Select 1. Array becomes  1 4 3 9 7.
Select 3. Array becomes 1 3 4 9 7. Select 4. Array becomes 1 3 4 9 7. Select 7. 
Array becomes 1 3 4 7 9. Select 9. Array becomes 1 3 4 7 9.    
</pre>  
<pre>  
Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]  
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]  
</pre>  
<pre>  
Input: arr[] = [38, 31, 20, 14, 30]  
Output: [14, 20, 30, 31, 38]  
</pre>  
**Constraints**:  
1 ≤ arr.size() ≤ 103  
1 ≤ arr[i] ≤ 106  

# Solution: 
  `C++` `Secection-Sort`  
```cpp
class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        int n = arr.size();
        for(int i=0; i<n; i++){
            int smallestIndex = i;
            for(int j=i+1; j<n; j++){
                if(arr[j] < arr[smallestIndex]){
                    smallestIndex = j;
                }
            }
            if(smallestIndex != i)
                swap(arr[i], arr[smallestIndex]);
        }
    }
};
```
