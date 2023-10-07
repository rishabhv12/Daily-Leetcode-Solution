## 03. Number of Good Pairs


The problem can be found at the following link: [Question Link](https://leetcode.com/problems/number-of-good-pairs/description/)


### My Approach


1. Initialize an unordered map of `int`.

2. Iterate through the given values in the array. For each piece in the iteration:

    * Check if the current value is present in the map or not 
    If yes, increment `count` as it is a valid pair. 

    * If it is not present in the map then insert the value in the map
   
    
3. Return `count` which stores the count of all valid pairs .



### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(n)`



### Code (C++)

```cpp

class Solution {
public:
    int numIdenticalPairs(vector<int>& a) {
        int i,count=0;

        unordered_map<int,int>map;

        for(i=0;i<a.size();i++){
            if(map.find(a[i])!=map.end())
            count +=map[a[i]];
                
            map[a[i]]++;
        }
        return count;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.