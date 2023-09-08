## 08. Pascal's Triangle

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/pascals-triangle/description/)


### My Approach


1. Initialize a 2D vector `ans` with `n` rows. This vector will store the rows of Pascal's Triangle.

2. Create a vector `one` containing a single element with the value 1, representing the first row of Pascal's Triangle.

3. Start a loop from `i = 1` to `n - 1` (inclusive) to generate the remaining rows of Pascal's Triangle.

4. Inside the loop:
   a. Create an empty vector `row` to represent the current row being generated.

   b. Start another loop from `j = 0` to `i` (inclusive) to calculate each element of the current row.
   
   c. In the inner loop:
      - If `j` is 0, it means we are at the beginning of the row. Add the element at the same position from the previous row (`ans[i-1][j]`) to `row`.

      - If `j` is equal to `i`, it means we are at the end of the row. Add the element at the same position from the previous row (`ans[i-1][i-j]`) to `row`.

      - For all other values of `j`, calculate the element by summing the elements from the previous row at positions `j-1` and `j`. Add this value (`x`) to `row`.

   d. After completing the inner loop, assign the `row` vector as the current row of `ans` (at index `i`).

5. After the loop is finished, `ans` will contain Pascal's Triangle up to the `n`th row. Return `ans`.


### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(1)`


### Code (C++)

```cpp

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);
        vector<int> one(1,1);

        ans[0] = one;

        for(int i=1;i<n;i++){
            vector<int> row;

            for(int j=0;j<=i;j++){

                if(j==0) row.push_back(ans[i-1][j]);
                else if(j==i) row.push_back(ans[i-1][i-j]);
                else{
                    int x = ans[i-1][j-1]+ans[i-1][j];
                    row.push_back(x);
                }
            }
            ans[i] = row;
        }
        return ans;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.