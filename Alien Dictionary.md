# Alien Dictionary  
**Difficulty**: Hard  
A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.  

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.  

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").  

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.  

Your implementation will be tested using a driver code. It will print `true` if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print `false`.  

**Examples**:  

Input: words[] = ["cb", "cba", "a", "bc"]  
Output: true  
Explanation: You need to return "cab" as the correct order of letters in the alien dictionary.  

Input: words[] = ["ab", "aa", "a"]  
Output: ""  
Explanation: You need to return "" because "aa" is lexicographically larger than "a", making the order invalid.  

Input: words[] = ["ab", "cd", "ef", "ad"]  
Output: ""  
Explanation: You need to return "" because "a" appears before "e", but then "e" appears before "a", which contradicts the ordering rules.  

**Constraints**:  

1 <= words.length <= 500  
1 <= words[i].length <= 100  
words[i] consists only of lowercase English letters. 

# Solution:
  `C++` `Kahn’s Algorithm (BFS Topological Sort)` `Directed Acyclic Graph (DAG)
` `Graph Representation`  

```cpp
class Solution {
  public:
    string findOrder(vector<string> &words) {
        vector<int> adj[26];
        unordered_set<char> uniqueChars;
        int n = words.size();
    
        // Build the Graph (Adjacency List)
        for (const string &word : words) {
            for (char ch : word) {
                uniqueChars.insert(ch);
            }
        }
    
        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i], s2 = words[i + 1];
            int len = min(s1.length(), s2.length());
    
            // Prefix condition: If s1 is longer but s2 is a prefix, return invalid
            if (s1.length() > s2.length() && s1.substr(0, len) == s2) {
                return "";
            }
    
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');  // Edge: s1[j] → s2[j]
                    break;
                }
            }
        }
    
        // Compute Indegree
        vector<int> indegree(26, -1);  // -1 means character is unused
        for (char ch : uniqueChars) {
            indegree[ch - 'a'] = 0;  // Mark as used
        }
    
        for (int i = 0; i < 26; i++) {
            for (int neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }
    
        // Topological Sorting (Kahn's Algorithm - BFS)
        queue<int> q;
        string result = "";
    
        // Push all characters with indegree == 0
        for (char ch : uniqueChars) {
            if (indegree[ch - 'a'] == 0) {
                q.push(ch - 'a');
            }
        }
    
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result += (char)(node + 'a');
    
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
    
        // If result length is not equal to unique characters, return ""
        return result.length() == uniqueChars.size() ? result : "";
    }
};
```
