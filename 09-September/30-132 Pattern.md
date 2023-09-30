## 30- 132 Pattern

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/132-pattern/description/)



### My Approach

We need to check if there exists three indices `i`,`j` and `k` such that `i < j < k` and `nums[i] < nums[k] < nums[j]`. To do this we'll have to first find if there exists a pair k, j for which k > j and at the same time `nums[j] > nums[k]`. Once this pair is found we need to find if we have a number to the left of j whose value is less than `nums[k]`. We can use monotonic stack for this.

1. Start with making our `s3 = INT_MIN`.

2. Initialise an empty stack st.

3. Now starting from our last index till the first index, i.e from `i = n- 1 to i = 0`, if our current number is lesser than s3 i.e `nums[i] < s3`, we've found our s1 we return true because we have already found a number s2 such that `s3 < s2` so our sequence `s1(nums[i]) < s3 < s2` is complete.

4. Else if `nums[i] > s3` it means nums[i] could be our potential s2, so , while our nums[i] > the top of our stack, we pop and update the value of s3. The popping and updating is done because we need our s3 to be smaller than nums[i] since `s3 < s2`.

5. Push `nums[i]` into the stack.

6. At last return false, it would mean that our true isn't returned so no such sequence exists.



### Time and Auxiliary Space Complexity

- Time Complexity: `O(n)` 
- Auxiliary Space Complexity: `O(n)`



### Code (C++)

```cpp

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int s3 = INT_MIN;
        stack<int> st;
        for(int i=n-1; i>=0; i--)
        {
            if(nums[i] < s3) return true;
            else
            {
                while(!st.empty() && nums[i] > st.top())
                {
                    s3 = st.top();
                    st.pop();
                }

                st.push(nums[i]);
            }
        }
        return false;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.