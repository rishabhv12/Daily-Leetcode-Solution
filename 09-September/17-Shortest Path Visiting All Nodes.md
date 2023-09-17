## 17. Shortest Path Visiting All Nodes

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/shortest-path-visiting-all-nodes/description/)


### My Approach

Firstly we have our number of nodes stored in n. The mask represents all the nodes visited.
The visited array tells us if we've visited [i] mask and [j] node.

Now calculate the mask for each node and push it into the queue q. Also mark the node and its mask visited. The mask of that node is stored in origMask.

While our q is not empty do the following -

1. pop the front of queue into curr.

2. currNode is the node in the curr

3. currMask if the mask of currNode

4. currLength is the length of the path

5. if currMask == mask which means all the nodes have been visited, return currLength - 1.

6. Else iterate over the adjacency list of the currNode provided and find its neighbors.

7. For each neighbor find the newMask and if the neighbor with newMask is not already visited push the neighbor, newMask and currLength + 1 into the queue q. This means that we can go to this newNode.

8. Mark the newMask and neighbor visited.

9. At last if no such path is found, return -1


### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(n)`


### Code (C++)

```cpp

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int mask = (1<<n) - 1;
        queue<pair<int,pair<int,int>>> q;

        vector<vector<bool>> visited(mask + 1, vector<bool>(n, false));

        for (int node = 0; node < n; ++node) {
            int origMask = (1 << node);
            q.push({node, {origMask, 1}});
            visited[origMask][node] = true;
        }

        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int currNode = curr.first;
            int currMask = curr.second.first;
            int currLength = curr.second.second;

            if (currMask == mask)
                return currLength - 1;

            for (int i = 0; i < graph[currNode].size(); ++i) {
                int neighbor = graph[currNode][i];
                int newMask = currMask | (1 << neighbor);

                if (visited[newMask][neighbor])
                    continue;

                q.push({neighbor, {newMask, currLength + 1}});
                visited[newMask][neighbor] = true;
            }
        }
        return -1;  
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.