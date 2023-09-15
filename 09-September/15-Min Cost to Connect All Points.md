## 15. Min Cost to Connect All Points

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/min-cost-to-connect-all-points/description/)


### My Approach

The problem is a classic example of the Minimum Spanning Tree (MST) problem. Given a set of points in a 2D plane, you want to find the minimum cost to connect all points such that there is exactly one simple path between any two points. The cost of connecting two points is defined as the Manhattan distance between them.

The provided solution is an implementation of Kruskal's algorithm, which is a popular algorithm for finding the MST of a graph. Here's an explanation of the solution step by step:

1. Two helper functions are defined:
find(parent, x): This function is used to find the representative (root) of a set using path compression. It recursively follows the parent pointers until it reaches the root of the set. Path compression is used to optimize the find operation by updating the parent pointers of all nodes along the path to the root, making future finds faster.

union(parent, x, y): This function is used to unite two sets by setting one's root as the parent of the other's root. It uses the find function to find the roots of the sets containing elements x and y and then sets the root of x as the parent of the root of y. This effectively merges the two sets.

2. The number of points n is determined based on the input list points.

3. A list called edges is created to store the edges between points along with their Manhattan distances. This list comprehensively computes the distances between all pairs of points and stores them in the form of tuples (distance, i, j) where distance is the Manhattan distance between point i and point j. Note that it only stores edges between distinct points (i.e., i is less than j).

4. The edges list is sorted in ascending order based on their distances. This is done to consider the shortest edges first during the MST construction.

5. A parent list is created, initialized such that each point is its own parent, effectively isolating all points at the beginning.

6. Two variables, min_cost (initialized to 0) and num_edges (initialized to 0), are used to keep track of the total minimum cost and the number of edges added to the MST, respectively.

7. The algorithm iterates through the sorted edges. For each edge (cost, u, v), it checks if adding this edge doesn't create a cycle in the minimum spanning tree. This is done by checking if find(parent, u) is not equal to find(parent, v), meaning that u and v belong to different sets.

8. If the edge doesn't create a cycle, it unites the sets containing u and v using the union function, updates min_cost by adding the cost of the current edge, and increments num_edges.

9. The loop continues until num_edges equals n - 1, which means that you have added enough edges to create a spanning tree that connects all n points.

10. Finally, the function returns min_cost, which represents the minimum cost to connect all points in the MST.


### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(ElogE)` 
- **Auxiliary Space Complexity**: `O(ElogE)`


### Code (C++)

```cpp

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<int> parent;
        vector<pair<int, pair<int, int>>> edges;
        int n = points.size();

        for (int i = 0; i < n; ++i) {
            parent.push_back(i);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({cost, {i, j}});
            }
        }

        sort(edges.begin(), edges.end());

        int min_cost = 0, num_edges = 0;

        for (auto& edge : edges) {
            int cost = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if (find(parent, u) != find(parent, v)) {
                unionSets(parent, u, v);
                min_cost += cost;
                num_edges++;
            }

            if (num_edges == n - 1) {
                break;
            }
        }

        return min_cost;
    }

private:
    int find(vector<int>& parent, int x) {
        if (parent[x] == x) {
            return x;
        }
        parent[x] = find(parent, parent[x]);
        return parent[x];
    }

    void unionSets(vector<int>& parent, int x, int y) {
        parent[find(parent, x)] = find(parent, y);
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.