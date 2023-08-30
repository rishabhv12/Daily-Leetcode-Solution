##  30. Minimum Replacements to Sort the Array

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/minimum-replacements-to-sort-the-array/description/)


### My Approach

The intution to solve this question is we can make all the element in the vector eqaul and also try to keep the replacement number as small as possible , we can achive this as :

1. Initialize variables:
   - `curmax` to keep track of the current maximum value (initialized to `INT_MAX`).
   - `ans` to keep track of the minimum number of replacements (initialized to 0).

2. Start a loop from the last element (`i` initialized to `n-1`) and move backwards towards the first element.

3. Inside the loop, check if `nums[i]` is less than or equal to `curmax`. If it is, update `curmax` to `nums[i]`. This step ensures that `curmax` always represents the maximum value encountered so far.

4. If `nums[i]` is greater than `curmax`, it means a replacement is needed to make them equal. Calculate the number of replacements required as follows:
   - If `nums[i]` is divisible by `curmax`, subtract 1 from the result and add it to `ans`.
   - Otherwise, divide `nums[i]` by `curmax` to get `div`, then add `div` to `ans`. Update `curmax` by dividing `nums[i]` by `div`, which ensures that `curmax` represents the maximum value encountered after the replacement.

5. Repeat steps 3-4 for all elements in the vector from right to left.


### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(1)` because we used an extra queue..


### Code (C++)

```cpp
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        int curmax=INT_MAX;
        long long ans=0;

        for(int i=n-1; i>=0; i--){
            if(nums[i]<=curmax){
                curmax=nums[i];
            }
            else{
                if(nums[i]%curmax==0){
                    ans+=((nums[i]/curmax)-1);
                }else{
                    ans+=((nums[i]/curmax));
                    int div=(nums[i]/curmax)+1;
                    curmax=nums[i]/div;
                }
            }
        }
        return ans;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.