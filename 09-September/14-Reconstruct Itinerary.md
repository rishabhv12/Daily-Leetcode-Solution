## 14. Reconstruct Itinerary

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/reconstruct-itinerary/description/)


### My Approach

Map all the airports to their destination.Sort the destinations according to lexical order and then apply DFS.

1. Initialize a unordered map to store the destinations of every airport.

2. Sort the destinations according to their lexical order.

3. Call the DFS with the starting airport as "JFK".

4. In DFS run a while loop till the destinations are not over.

5. n loop get the first destination.

6. Remove it from the adjacency list.

7. Call the DFS(Recursion).

8. After the end of loop push the string into the ans.



### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(nlogn)` 
- **Auxiliary Space Complexity**: `O(nlogn)`


### Code (C++)

```cpp

class Solution {
private:
     void dfs(unordered_map<string, vector<string>>& adj, vector<string>& ans, string s)
     {
       
        while(adj[s].size())
        {
            
            string v = adj[s][0];
            adj[s].erase(adj[s].begin());
            dfs(adj, ans, v);
        }

        ans.push_back(s);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        unordered_map<string, vector<string>> adj;
        for(auto it: tickets)
            adj[it[0]].push_back(it[1]);
        
        vector<string> ans;
        for(auto &[_,it]: adj)
            sort(it.begin(),it.end());

        dfs(adj, ans, "JFK");
        reverse(ans.begin(), ans.end());

        return ans;
        
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.