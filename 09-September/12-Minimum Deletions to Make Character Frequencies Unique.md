## 12. Minimum Deletions to Make Character Frequencies Unique

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/)


### My Approach

We need to count the frequencies of each character and then adjust those frequencies to ensure uniqueness while minimizing deletions.

1. Count the frequency of each character in the input string 's' using a Counter object.

2. Initialize a variable 'deletions' to keep track of the number of deletions needed.

3. Create an empty set `freqSet` to store unique frequencies encountered.

4. Iterate through each character and its frequency in `chars`.

5. For each character, enter a loop while its current frequency is greater than 0 and it is already in `chars`.

6. Decrement the frequency by 1, indicating that we are considering deleting one occurrence of this character.

7. Increment 'deletions' by 1, as we are performing a deletion operation.

8. Add the current frequency to `freqSet` to mark it as seen.

9. After processing all characters, return the total number of deletions needed


### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(n)`


### Code (C++)

```cpp

class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> chars;
        for (char c : s) {
            chars[c]++;
        }

        unordered_set<int> freqSet;
        int count = 0;

        for (const auto& pair : chars) {
            int freq = pair.second;
            while (freq > 0 && freqSet.count(freq)) {
                freq--;
                count++;
            }
            freqSet.insert(freq);
        }

        return count;        
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.