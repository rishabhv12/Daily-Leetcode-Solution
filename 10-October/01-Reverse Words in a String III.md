## 01. Reverse Words in a String III

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/reverse-words-in-a-string-iii/description/)


### My Approach


1. Initialize two variables, `start` and `end`, both initially set to 0. These will be used to keep track of the current word boundaries in the string.

2. Enter a while loop that continues until the `start` pointer reaches the end of the input string `s`.

3. Inside the outer while loop, enter another while loop that continues until either the `end` pointer reaches the end of the string or encounters a space character (' ').

4. Inside the inner while loop, the `end` pointer is incremented until it either reaches the end of the string or finds a space character, effectively identifying the end of the current word.

5. Once the inner while loop completes, it means we have identified a word in the string. At this point, we use the `reverse` function from the C++ Standard Library to reverse the characters in the identified word. The `reverse` function takes two iterators, `s.begin() + start` pointing to the beginning of the word and `s.begin() + end` pointing to the end of the word, and reverses the characters in that range.

6. After reversing the word, we update the `start` pointer to `end + 1`, which sets it to the beginning of the next word (or the character after the space).

7. We also update the `end` pointer to match the `start` pointer, effectively resetting it for the next word.



### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(1)`



### Code (C++)

```cpp

class Solution {
public:
    string reverseWords(string s) {
        int start=0,end=0;
        while(start<s.length()){
            while(end<s.length() && s[end]!= ' '){
                end++;
            }
            reverse(s.begin()+start,s.begin()+end);
            start=end+1;
            end=start;
        }
        return s;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.