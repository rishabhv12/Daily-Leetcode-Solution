## 22- Is Subsequence

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/is-subsequence/description)


### My Approach


1. Initialize an integer variable `i` to 0. This variable will be used to keep track of the current character index in string `s`.

2. Iterate through each character `x` in the string `t` using a loop.

3. Inside the loop, compare the current character `x` in `t` with the character at index `i` in string `s`.

4. If the characters match (i.e., `x` is equal to `s[i]`), increment the `i` variable by 1 to move to the next character in string `s`.

5. Continue this process for all characters in string `t`.

6. After the loop, check if `i` is equal to the length of string `s`. If it is, it means that all characters in `s` have been found in `t` in the same order, so return `true`. Otherwise, return `false` because not all characters in `s` were found in `t` in the same order.



### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(1)`


### Code (C++)

```cpp

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (auto& x : t) {
            if (x == s[i]) i++;
        }
        return (i == s.size() ? true : false);
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.