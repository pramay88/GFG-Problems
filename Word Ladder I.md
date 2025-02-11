# [Word Ladder I](https://www.geeksforgeeks.org/problems/word-ladder/1)
**Difficulty**: Hard  

Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.  
Keep the following conditions in mind:  

- A word can only consist of lowercase characters.  
- Only one letter can be changed in each transformation.  
- Each transformed word must exist in the wordList including the targetWord.  
- startWord may or may not be part of the wordList  
- The second part of this problem can be found here.  

**Note**: If no possible way to transform sequence from startWord to targetWord return 0  


**Example** 1:  

Input:  
wordList = {"des","der","dfr","dgt","dfs"}  
startWord = "der", targetWord= "dfs",  
Output: 3  
Explanation:  
The length of the smallest transformation  
sequence from "der" to "dfs" is 3  
i,e "der" -> "dfr" -> "dfs".  

Example 2:  

Input:  
wordList = {"geek", "gefk"}  
startWord = "gedk", targetWord= "geek",   
Output: 2  

Explanation:  
gedk -> geek  


**Your Task**:  
You don't need to read or print anything, Your task is to complete the function wordLadderLength() which takes startWord, targetWord and wordList as input parameter and returns the length of the shortest transformation sequence from startWord to targetWord. If not possible return 0.  


Expected Time Compelxity: O(N2 * M) 
Expected Auxiliary Space: O(N * M) where N = length of wordList and M = |wordListi|  


**Constraints**:  
1 ≤ N ≤ 100  
1 ≤ M ≤ 10  

# Solution:  
  `C++` `BFS` `Graph` `unordered_set(Hash)` `Queue`  
```cpp
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        if (wordSet.find(targetWord) == wordSet.end()) return 0;
    
        queue<pair<string, int>> q;
        q.push({startWord, 1});
    
        while (!q.empty()) {
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
    
            if (word == targetWord) 
                return level;
    
            for (int i = 0; i < word.length(); i++) {
                char originalChar = word[i];
    
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == originalChar) continue;
    
                    word[i] = c;
                    if (wordSet.find(word) != wordSet.end()) {
                        q.push({word, level + 1});
                        wordSet.erase(word);
                    }
                }
                word[i] = originalChar;
            }
        }
        return 0;
    }
};
```

## Time and Space Complexity Analysis  

### Time Complexity: O(N×L)  
  - N → Number of words in wordList.  
  - L → Length of each word.  
- Why?  
  - Each word has L positions.  
  - Each position can be replaced with 26 letters (O(L) per word).  
  - BFS processes at most N words.  

### Space Complexity: O(N×L)  
- Why?  
  - unordered_set stores N words → O(N)  
  - BFS queue stores up to N words → O(N × L)  
  - Auxiliary string operations → O(L)  
