## 09. Combination Sum IV

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/combination-sum-iv/)


### My Approach


1. Initialize a dynamic programming (DP) vector `dp` of size `target + 1` with all elements initially set to 0. This vector will be used to store the number of combinations for each target sum.

2. Set `dp[0]` to 1. This represents that there is one way to make a sum of 0, which is by not selecting any element from `nums`.

3. Within the loop, iterate over each element `value` in the `nums` vector using a range-based for loop.

4. For each `value`, check if subtracting `value` from the current target sum `i` results in a non-negative value, and if `dp[i]` is still within the range of `INT_MAX`. This check prevents integer overflow.

5. If the conditions in step 6 are met, update `dp[i]` by adding the value of `dp[i - value]` to it. This step accumulates the number of combinations for the current target sum by considering the contributions from different combinations of elements in `nums`.

6. Continue this process for all elements in `nums` for the current target sum `i`.

7. After completing the outer loop, `dp[target]` will contain the total number of combinations that add up to the given `target` using elements from the `nums` vector.

8. Return the value stored in `dp[target]`, which represents the number of combinations that meet the target sum.


### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n*target)` 
- **Auxiliary Space Complexity**: `O(target)`


### Code (C++)

```cpp

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long int>dp(target+1,0);
        dp[0] = 1;
        for(int i = 1; i<= target;i++){
            for(auto value : nums){
                if( i - value  >= 0 && dp[i] <= INT_MAX)
                  dp[i] += (long long int)dp[i - value];   
            }
        }
       return  dp[target];  
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.