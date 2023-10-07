## 04. Majority Element II


The problem can be found at the following link: [Question Link](https://leetcode.com/problems/majority-element-ii/description/)


### My Approach


1. Initialize variables:
   - `n` to store the size of the input vector `nums`.
   - Create an unordered map `cnt` to store the count of occurrences of each element.
   - Initialize an empty vector `ans` to store the majority elements.

2. Iterate through the `nums` vector using a for loop:
   - Use the `cnt` map to count the occurrences of each element in the `nums` vector.

3. Iterate through the elements in the `cnt` map:
   - Check if the count (`j->second`) of an element is greater than one-third of the total elements (`n/3`).
   - If the count meets the condition, add the element (`j->first`) to the `ans` vector.

4. After both loops have finished, the `ans` vector will contain the majority elements (elements that appear more than one-third of the time) in the input vector `nums`.

5. Return the `ans` vector as the result.



### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(n)`



### Code (C++)

```cpp

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {  
        int n=nums.size();
        unordered_map<int, int> cnt;
        vector<int> ans;
        for(int i=0;i<n;i++){
            cnt[nums[i]]++;
        }
        for(auto j=cnt.begin();j!=cnt.end();j++){
            if(j->second>n/3)ans.push_back(j->first);
        }
        return ans;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.