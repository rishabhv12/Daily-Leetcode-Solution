## 23- Longest String Chain

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/longest-string-chain/description/)


### My Approach


1. Custom Comparison Function `cmp`:
    - Define a static bool function `cmp` that takes two string parameters, `a` and `b`.
    - It compares two strings based on their lengths, returning `true` if the length of `a` is less than the length of `b`, and `false` otherwise.

2. `isSubsequence` Function:
    - Define a member function `isSubsequence` that takes two string parameters, `s` and `t`.
    - Initialize an integer variable `j` to 0. This variable will be used to iterate through the characters of `s`.
    - Iterate through the characters of string `t` using a for loop.
    - Inside the loop, check if the current character in `t` at index `i` is equal to the current character in `s` at index `j`.
    - If they are equal, increment the `j` variable.
    - After the loop, check if the length of `s` is equal to `j`. If it is, return `true`, indicating that `s` is a subsequence of `t`. Otherwise, return `false`.

3. `longestStrChain` Function:
    - Define a member function `longestStrChain` that takes a reference to a vector of strings, `words`.
    - Sort the `words` vector using the custom comparison function `cmp`. This sorting is done in ascending order of string lengths.
    - Initialize an integer variable `n` to store the number of words in the input vector `words`.
    - Create a dynamic programming (DP) vector `dp` of size `n`, where each element represents the length of the longest chain ending with the word at that index. Initialize all elements to 1 because each word forms a chain of length 1 by default.
    - Initialize an integer variable `maxLen` to 1, which will be used to keep track of the maximum chain length found so far.

4. DP Loop:
    - Iterate through the `words` vector using a nested for loop. The outer loop iterates from `i = 1` to `n-1`, and the inner loop iterates from `j = 0` to `i-1`.
    - Inside the inner loop, check if `words[j]` is a subsequence of `words[i]` and if the length of `words[j]` plus 1 is equal to the length of `words[i]`. This checks if `words[i]` can be part of a longer chain.
    - If the conditions are met, update the `dp[i]` value to be the maximum of its current value and `dp[j] + 1`. This means that we consider extending the chain from word `j` to word `i`.
    - Update the `maxLen` variable with the maximum of its current value and `dp[i]`.

5. Return Result:
    - After the DP loop, return the value stored in `maxLen`, which represents the length of the longest string chain that can be formed using the input words.



### Time and Auxiliary Space Complexity

- Time Complexity: `O(n*n)` 
- Auxiliary Space Complexity: `O(n)`


### Code (C++)

```cpp

class Solution {
public:
    static bool cmp(string a, string b){
        return a.length()<b.length();
    }
    bool isSubsequence(string s, string t) {
        int j=0;
        for(int i=0; i<t.length();i++){
            if(t[i]==s[j]){
                j++;
            }
        }
        if(s.length()==j)return true;
        return false;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n=words.size();
        vector<int> dp(n, 1);
        int maxLen = 1;
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(isSubsequence(words[j], words[i]) && words[j].length()+1==words[i].length()){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.