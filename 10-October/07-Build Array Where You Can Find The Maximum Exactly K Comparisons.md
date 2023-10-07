## 07. Build Array Where You Can Find The Maximum Exactly K Comparisons


The problem can be found at the following link: [Question Link](https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/)


### My Approach


1. Define a private function called "solve" with the following parameters:
   - `n`: The remaining number of elements to be placed in the array.
   - `m`: The maximum value that can be used to fill an element in the array.
   - `k`: The remaining allowed changes to the previously placed value.
   - `prev`: The previously placed value in the array.
   - `dp`: A three-dimensional vector used for memoization.

2. Check if `n` is 0 and `k` is 0, indicating that we have successfully constructed the array. Return 1 in this case.

4. Check if `k` is less than 0 or `n` is less than 0, indicating an invalid state. Return 0 in these cases.

5. Check if the result for the current state (n, k, prev) is already calculated and stored in the memoization table `dp`. If yes, return the stored result.

6. Initialize a variable `ans` to 0 to keep track of the number of valid arrays.

7. Iterate through values from 1 to `m` (inclusive) representing the next element to be placed in the array.

8. If `prev` is less than the current value `i`, recursively call the "solve" function with reduced `n`, `k`, and `prev` updated to `i`. Add the result to `ans`.

9. If `prev` is greater than or equal to the current value `i`, recursively call the "solve" function with reduced `n` and `k`, keeping `prev` unchanged. Add the result to `ans`.

10. Calculate the final result as `ans % mod`, where `mod` is defined as 1e9+7.

11. Store the calculated result in the memoization table `dp` for the current state (n, k, prev).

12. In the public function "numOfArrays," check if `k` is greater than `n`. If yes, return 0 because it's not possible to construct the array with more allowed changes than the remaining elements.

13. Initialize a three-dimensional vector `dp` of size (n+1) x (k+1) x (m+1) with all values set to -1 for memoization.



### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(n)`



### Code (C++)

```cpp

class Solution {
private:
    int solve(int n, int m, int k, int prev, vector<vector<vector<int>>> &dp){
        if(n == 0 && k == 0){
            return 1;
        }
        if(k < 0 || n < 0)
            return 0;
        if(dp[n][k][prev] != -1)
            return dp[n][k][prev];

        int ans = 0;
        for(int i = 1; i <= m; i++){
            if(prev < i)
                ans = (ans + solve(n - 1, m, k - 1, i, dp)) % mod;
            else
                ans = (ans + solve(n - 1, m, k, prev, dp)) % mod;
        }
        return dp[n][k][prev] = ans % mod;
    }
public:
    long long mod = 1e9+7;
    int numOfArrays(int n, int m, int k) {
        if(k > n)
            return 0;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (k + 1, vector<int> (m + 1, -1)));
        return solve(n, m, k, 0, dp);
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.