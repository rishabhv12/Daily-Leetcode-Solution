## 25- Find the Difference

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/find-the-difference/description)



### My Approach


1. Initialize an unordered_map called `mp` to store character frequencies.
2. Iterate through each character `c` in string `s`:
   - Increment the count of character `c` in the `mp` map by 1.
   - This loop populates the `mp` map with the frequency of each character in string `s`.

3. Iterate through each character `c` in string `t`:
   - Decrement the count of character `c` in the `mp` map by 1.
   - Check if the count becomes less than 0. If it does, return the character `c`. This character is the one that appears more times in string `t` than in string `s`, making it the "difference" character.

4. If no difference character is found during the loop in step 3, return the null character `'\0'`. This indicates that all characters in `s` and `t` are the same, and there is no additional character in `t`.



### Time and Auxiliary Space Complexity

- Time Complexity: `O(n)` 
- Auxiliary Space Complexity: `O(n)`



### Code (C++)

```cpp

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        for(auto& c:s) mp[c]+=1;
        for(auto& c:t) if(--mp[c]<0) return c;
        return '\0';
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.