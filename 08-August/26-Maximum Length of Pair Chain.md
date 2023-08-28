## 26. Maximum Length of Pair Chain

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/maximum-length-of-pair-chain/)

### My Approach

The greedy approch to solve this questiojn is , we can sort the given vector according to their 2nd element . Then we can check if the end value of the first element is less then to start value of the second element . If it is true then we increment our counter and change our current index acoording to end value .


### Algorithm

1. Sort the `pairs` vector in ascending order based on their ending points using the `compare` function. This step ensures that pairs with smaller ending points come first in the sorted vector.

2. Initialize a variable `ans` to 1. This variable will keep track of the length of the longest chain.

3. Initialize a variable `end` to the ending point of the first pair in the sorted `pairs` vector.

4. Iterate through the sorted `pairs` vector starting from the second pair (index 1).

5. For each pair at index `i`, get its starting point `si` and ending point `ei`.

6. Check if the starting point `si` of the current pair is greater than the current `end`. If it is, this means that you can add this pair to the chain because it doesn't overlap with the previous pair.

7. If `si` is greater than `end`, increment the `ans` variable by 1 to extend the chain length, and update the `end` variable to be `ei` (the ending point of the current pair).

8. Continue iterating through the sorted pairs, repeating steps 6-8, until you've processed all pairs.


### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(nlogn)` 
- **Auxiliary Space Complexity**: `O(1)`

### Code (C++)

```cpp
class Solution {
public:
    
	// sorting by minimum end
    static bool compare(vector<int> &a, vector<int> &b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),compare);
        
        int ans =1;
        int end=pairs[0][1];
        for(int i=1;i<pairs.size();i++){
            int si=pairs[i][0], ei=pairs[i][1];
        
            if(si>end){
                ans++;
                end=max(end ,ei);
            }
        }
        return ans;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.