## 18. The K Weakest Rows in a Matrix

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/)


### My Approach


1. Create an empty vector of pairs `rowStrengths`. Each pair will store the row's strength (the sum of elements in the row) and the row index.

2. Iterate through each row of the matrix `mat`:
   a. Calculate the strength of the current row by summing all its elements using `accumulate`.
   b. Push a pair containing the row's strength and its index into the `rowStrengths` vector.

3. Sort the `rowStrengths` vector in ascending order based on the first element of each pair (i.e., row strength).

4. Create an empty vector `result` to store the indices of the `k` weakest rows.

5. Iterate from `i = 0` to `i < k`:
   a. Push the index of the `i`-th row from the sorted `rowStrengths` vector into the `result` vector.

6. Return the `result` vector, which contains the indices of the `k` weakest rows.

Here's the pointwise algorithm in a step-by-step format:

- Initialize an empty vector `rowStrengths`.

- Iterate through each row of the matrix `mat`:
  - Calculate the strength of the current row by summing all its elements.
  - Create a pair containing the row's strength and its index.
  - Push the pair into the `rowStrengths` vector.

- Sort the `rowStrengths` vector in ascending order based on the first element of each pair (i.e., row strength).

- Initialize an empty vector `result` to store the indices of the `k` weakest rows.

- Iterate from `i = 0` to `i < k`:
  - Push the index of the `i`-th row from the sorted `rowStrengths` vector into the `result` vector.

- Return the `result` vector, which contains the indices of the `k` weakest rows.


### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(nlogn)` 
- **Auxiliary Space Complexity**: `O(1)`


### Code (C++)

```cpp

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> rowStrengths;
        for (int i = 0; i < mat.size(); ++i) {
            int strength = accumulate(mat[i].begin(), mat[i].end(), 0);
            rowStrengths.push_back({strength, i});
        }
        
        sort(rowStrengths.begin(), rowStrengths.end());
        
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(rowStrengths[i].second);
        }
        
        return result;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.