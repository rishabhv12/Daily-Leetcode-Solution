## 16. Path With Minimum Effort

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/path-with-minimum-effort/description/)


### My Approach


1. Start by defining a class named `Solution` with a public member function `minimumEffortPath`, which takes a 2D vector `heights` as input and returns an integer.

2. Get the dimensions of the `heights` grid: `m` represents the number of rows, and `n` represents the number of columns.

3. Check if the grid has only one cell (m == 1 and n == 1), return 0 as there is no effort required to move within a single-cell grid.

4. Create a 2D vector `dist` of size `m x n` to store the minimum effort required to reach each cell from the starting cell. Initialize all values in `dist` to `INT_MAX` except for the starting cell, which is set to 0.

5. Create a `priority_queue` named `pq` to store cells as pairs of (distance, cell), where distance represents the minimum effort to reach that cell, and the cell is represented as (i, j).

6. Define two vectors, `di` and `dj`, to represent the four possible directions to move: up, left, down, and right. These vectors will be used to explore neighboring cells.

7. Start a while loop that continues as long as the priority queue `pq` is not empty.

8. Inside the loop, pop the top element from `pq`, which represents the cell with the smallest effort required.

9. Extract the row `i` and column `j` of the current cell from the popped element.

10. Iterate through the four possible directions (up, left, down, right) using a for loop.

11. For each direction, calculate the new row `ni` and new column `nj` by adding the corresponding values from `di` and `dj` to the current row `i` and column `j`.

12. Check if the new cell (ni, nj) is within the boundaries of the grid (i.e., ni >= 0, nj >= 0, ni < m, and nj < n).

13. Calculate the new distance `newDist` required to reach the new cell. This distance is the maximum of the current distance `dist[i][j]` and the absolute difference in heights between the current cell and the new cell `abs(heights[i][j] - heights[ni][nj])`.

14. If the new distance `newDist` is smaller than the current distance `dist[ni][nj]`, update `dist[ni][nj]` with `newDist` and push the new cell (ni, nj) into the priority queue `pq` with the updated distance.

15. Repeat steps 8-14 until all cells have been processed, ensuring that the priority queue always contains cells with the minimum effort.

16. Finally, return the minimum effort required to reach the bottom-right cell, which is stored in `dist[m - 1][n - 1]`.

This algorithm uses Dijkstra's algorithm with a priority queue to find the minimum effort path from the top-left corner to the bottom-right corner of the grid while considering the differences in heights between adjacent cells.


### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(m*n*log(m*n))` 
- **Auxiliary Space Complexity**: `O(m*n) `


### Code (C++)

```cpp

class Solution {
public:
    int minimumEffortPath(std::vector<std::vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        if (m == 1 && n == 1) {
            return 0;
        }

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;


        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
        pq.push({0, 0});
  
        vector<int> di = {-1, 0, 1, 0};
        vector<int> dj = {0, -1, 0, 1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int i = it.first;
            int j = it.second;

            for (int k = 0; k < 4; k++) {
                int ni = i + di[k];
                int nj = j + dj[k];

                if (ni >= 0 && nj >= 0 && ni < m && nj < n) {

                    // Important logic of the entire code
                    int newDist = max(dist[i][j], abs(heights[i][j] - heights[ni][nj]));

                    // If we found a shorter path, update distance and push to priority queue
                    if (newDist < dist[ni][nj]) {
                        dist[ni][nj] = newDist;
                        pq.push({ni, nj});
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.