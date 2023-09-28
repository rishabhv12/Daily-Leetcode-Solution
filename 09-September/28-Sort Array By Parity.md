## 28- Sort Array By Parity

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/sort-array-by-parity/description)



### My Approach

1. Initialize an integer variable `j` to 0. This variable will keep track of the position where the next even number should be placed in the array.

2. Within the loop, check if the current element at `nums[i]` is even. You can do this by using the bitwise AND operation with 1, i.e., `!(nums[i] & 1)`. If the result is true, it means the current element is even.

3. Inside the `if` condition (when the current element is even), perform a swap operation between `nums[i]` and `nums[j]`. This swaps the current even element with the element at position `j,` effectively moving all even elements to the front of the array.

4. Increment the `j` variable by 1 to prepare for the next even element placement.

5. Continue iterating through the elements of the `nums` vector, repeating steps 4-6 for each element.

6. Once the loop finishes, the `nums` vector will be sorted with all even elements at the beginning and all odd elements at the end.



### Time and Auxiliary Space Complexity

- Time Complexity: `O(n)` 
- Auxiliary Space Complexity: `O(1)`



### Code (C++)

```cpp

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(!(nums[i]&1)){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return nums;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.