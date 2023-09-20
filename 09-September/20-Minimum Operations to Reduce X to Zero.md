## 20. Minimum Operations to Reduce X to Zero

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description)


### My Approach

We have to minimixe the left and right element of a array thats meanwe have to maximize the number element of a subarray which present in the array which sum equal to tatolSum-x

To find the max middle subarray element or length

we will use sliding window technique/two pointer approach -

1. Initially we will set left and right pointer at 0 index

2. We will move right pointer until CurrSum > totalSum - x

3. if CurrSum > totalSum - x we will move left pointer and also check the condition that l<=r

4. Update our maxLength if and only if currSum == totalSum - x

5. Repeat the above steps until we reach the end of the array.

6. At last if we did not find any such window we will return -1 as answer



### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(1)`


### Code (C++)

```cpp

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int sum =0;
        for(int i:nums) sum += i;

        int i=0;
        int maxlen = INT_MIN, currsum=0;
        int target = sum -x;
        bool found = false;
        for(int j=0;j<n;j++){
            currsum += nums[j];

            while(i<=j && currsum>target){
                currsum -= nums[i];
                i++;
            }
            if(currsum == target){
                found = true;
                maxlen = max(maxlen, j-i+1);
            }
        }

        return found? n-maxlen: -1;

    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.