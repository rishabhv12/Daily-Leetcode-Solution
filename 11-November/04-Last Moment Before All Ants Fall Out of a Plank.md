## 04. Last Moment Before All Ants Fall Out of a Plank

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/description)


### My Approach


1. Initialize an integer variable `lastFallTime` to 0, which will be used to keep track of the last moment when an ant falls off the plank.

2. Iterate through the positions of ants moving to the left (from the `left` vector):
   - For each `leftPosition` in the `left` vector, update `lastFallTime` by taking the maximum of its current value and the value of `leftPosition`. This represents the farthest position reached by ants moving to the left.

3. Iterate through the positions of ants moving to the right (from the `right` vector):
   - For each `rightPosition` in the `right` vector, calculate the farthest position reached by ants moving to the right from the right end of the plank. To do this, subtract `rightPosition` from `n` (the length of the plank) to get the distance from the right end to the ant's position. Update `lastFallTime` by taking the maximum of its current value and this calculated value.

4. After iterating through both the left and right positions, the `lastFallTime` variable will hold the last moment when an ant falls off the plank.

5. Return the value of `lastFallTime`, which represents the last moment at which an ant falls off the plank.




### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(1)`



### Code (C++)

```cpp

class Solution {
public:
    
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int lastFallTime = 0;
        
        // Determine the farthest position reached by ants moving to the left.
        for (int leftPosition : left) {
            lastFallTime = max(lastFallTime, leftPosition);
        }
        
        // Determine the farthest position reached by ants moving to the right,
        // considering they start from the right end of the plank (n - position).
        for (int rightPosition : right) {
            lastFallTime = max(lastFallTime, n - rightPosition);
        }
        
        return lastFallTime;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.