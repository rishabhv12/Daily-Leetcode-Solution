## 19. Find the Duplicate Number

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/find-the-duplicate-number/description/)


### My Approach


1. Initialize a variable `len` to store the length of the input vector `nums` (i.e., the number of elements in the vector).

2. Iterate through each element `num` in the `nums` vector using a range-based for loop:

   a. Calculate the absolute value of `num` and store it in the variable `idx`. This is done to ensure that we can use `idx` as an index to access elements in the `nums` vector without negative indices.

   b. Check if the element at the `idx` position in the `nums` vector is already negative. If it is negative, this means that we have encountered a duplicate value because we've marked it as negative previously. In this case, return `idx` as the duplicate number.

   c. If the element at the `idx` position is not negative, mark it as negative by multiplying it by -1. This is done to indicate that we have visited this element during the iteration.

3. After the loop, print the modified `nums` vector to see the changes made during the iteration (this step is for debugging purposes).

4. If no duplicate is found in the `nums` vector during the iteration, return `len` as a signal that no duplicates were found. However, this line of code might be an error, as it should return a duplicate number when found. You may need to modify this part of the code depending on your requirements.

Please note that the algorithm uses a technique called "negation marking" to identify duplicates. It assumes that the input vector `nums` contains integers in the range from 1 to `len - 1` and that there is exactly one duplicate number in the vector. If these assumptions are not met, the algorithm may not work correctly.


### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(1)`


### Code (C++)

```cpp

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();

        for (int num : nums) {
            int idx = abs(num);
            if (nums[idx] < 0) {
                return idx;
            }
            nums[idx] = -nums[idx];
        }
        for(int num: nums) cout<<num<<" ";
        return len;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.