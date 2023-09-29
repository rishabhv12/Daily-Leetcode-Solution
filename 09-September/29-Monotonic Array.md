## 29- Monotonic Array

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/monotonic-array/description/)



### My Approach

1. Initialize two boolean flags, `increasing` and `decreasing`, to `true`. These flags will help us track whether the array is non-increasing or non-decreasing, respectively.

2. Iterate through the array `nums` starting from index `1` (comparing each element with the previous one).

3. For each pair of adjacent elements, check whether `nums[i]` is greater than `nums[i - 1]`. If it is, set the decreasing flag to false because this indicates that the array is not decreasing.

4. If `nums[i]` is less than `nums[i - 1]`, set the `increasing` flag to false because this indicates that the array is not increasing.

5. Continue this process for the entire array.

6. After the loop, check whether either `increasing` or `decreasing` is `true`. If either of them is true, it means that the array is monotonic (either non-increasing or non-decreasing), so return `true`. Otherwise, return `false`.



### Time and Auxiliary Space Complexity

- Time Complexity: `O(n)` 
- Auxiliary Space Complexity: `O(1)`



### Code (C++)

```cpp

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = true;
        bool decreasing = true;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                decreasing = false;
            } else if (nums[i] < nums[i - 1]) {
                increasing = false;
            }
        }

        return increasing || decreasing;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.