# [Fractional Knapsack](https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1)  
**Difficulty**: Medium  

Given two arrays, val[] and wt[], representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.  
Return the maximum value as a double, rounded to 6 decimal places.  

**Examples** :
<pre>
Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
Output: 240.000000
Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total value becomes 60+100+80.0=240.0 Thus, total maximum value of item we can have is 240.00 from the given capacity of sack. 
</pre>
<pre>
Input: val[] = [60, 100], wt[] = [10, 20], capacity = 50
Output: 160.000000
Explanation: Take both the items completely, without breaking. Total maximum value of item we can have is 160.00 from the given capacity of sack.
</pre>
<pre>
Input: val[] = [10, 20, 30], wt[] = [5, 10, 15], capacity = 100
Output: 60.000000
Explanation: In this case, the knapsack capacity exceeds the combined weight of all items (5 + 10 + 15 = 30). Therefore, we can take all items completely, yielding a total maximum value of 10 + 20 + 30 = 60.000000.
</pre>
**Constraints**:  
1 <= val.size=wt.size <= 105  
1 <= capacity <= 109  
1 <= val[i], wt[i] <= 104  

# Solution:  
  `C++`

```cpp
struct Item{
    int value;
    int weight;
};


bool cmp(const Item &a, const Item &b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<Item> items(n);

        for (int i = 0; i < n; i++) {
            items[i] = {val[i], wt[i]};
        }

        sort(items.begin(), items.end(), cmp);

        double maxProfit = 0.0;

        for (int i = 0; i < n; i++) {
            if (capacity == 0) break;

            if (items[i].weight <= capacity) {
                maxProfit += items[i].value;
                capacity -= items[i].weight;
            } else {
                maxProfit += items[i].value * ((double)capacity / items[i].weight);
                break;
            }
        }
        return maxProfit;
    }
};

```
