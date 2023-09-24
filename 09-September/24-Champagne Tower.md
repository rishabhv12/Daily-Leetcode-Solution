## 24- Champagne Tower

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/champagne-tower/description/)


### My Approach


1. Initialize a 2D vector called tower with dimensions query_row + 1 by query_row + 1. Each element in the vector represents the amount of champagne in a specific glass. Set all elements to 0 initially.

2. Assign the amount of poured champagne to the top glass of the tower, which is tower[0][0] = poured.

3. Start iterating through each row from 0 to query_row.

- Within each row iteration, iterate through each glass from 0 to min(i, query_row + 1). The min(i, query_row + 1) condition ensures that we only consider the glasses within the row that are actually present.

- For each glass, calculate the overflow by subtracting 1 from the current amount of champagne in the glass and divide it by 2.0. This represents the amount of champagne that overflows from the current glass.

- Add half of the overflow to the glass directly below it in the next row (tower[i + 1][j] += overflow).

- Add the other half of the overflow to the glass diagonally below it in the next row (tower[i + 1][j + 1] += overflow).

4. After completing the row iteration, the bottom row of the tower vector will contain the amounts of champagne in each glass after pouring and overflow. Return the minimum value between 1.0 and the amount of champagne in the requested glass (tower[query_row][query_glass]). This ensures that the returned value doesn't exceed 1.0, which represents the maximum capacity of a glass.



### Time and Auxiliary Space Complexity

- Time Complexity: `O(n*n)` 
- Auxiliary Space Complexity: `O(n*n)`


### Code (C++)

```cpp

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tower(query_row + 1, vector<double>(query_row + 1, 0));

        tower[0][0] = poured;

        for (int i = 0; i < query_row; i++) {
            for (int j = 0; j <= min(i, query_row + 1) ; j++) {
                double overflow = max(0.0, tower[i][j] - 1) / 2.0;
                tower[i + 1][j] += overflow;
                tower[i + 1][j + 1] += overflow;
            }
        }

        return min(1.0, tower[query_row][query_glass]);
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.