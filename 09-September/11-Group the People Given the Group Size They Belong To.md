## 11. Group the People Given the Group Size They Belong To

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/)


### My Approach

One way to approach this problem is by using a map data structure from C++ STL library. We can iterate through the input array and store the indices of all the people belonging to a particular group size in a vector. By doing so, we can group all the people based on their group sizes. After that, we can iterate through the map and divide each group into subgroups of size groupSize.

1. Initialize an empty map mp.

2. Iterate through the groupSizes array using a loop.

3. For each element groupSizes[i], insert the index i into the corresponding vector in the map mp `groupSizes[i]`.

4. Iterate through the mp map using a loop.

5. For each key-value pair in the map, store the key in k and the value in vec.

6. Initialize a count variable count to 0 and an empty vector temp.

7. For each index vec[i], push it into the temp vector and increment the count variable.

8. If the count variable becomes equal to k, push the temp vector into the ans vector, reset the count variable to 0, and clear the temp vector.

9. Return the ans vector, which contains all the subgroups of people grouped by their respective group sizes.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(nlogn)` 
- **Auxiliary Space Complexity**: `O(n)`


### Code (C++)

```cpp

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> mp;

        for(int i = 0; i < groupSizes.size(); i++){
            mp[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> ans;

        for(auto it : mp){
            int k = it.first;
            vector<int> vec = it.second;

            int count = 0;

            vector<int> temp;

            for(int i = 0; i < vec.size(); i++){
                temp.push_back(vec[i]);
                count++;
                if(count == k){
                    ans.push_back(temp);
                    count = 0;
                    temp.clear();
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