## 29. Minimum Penalty for a Shop

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/minimum-penalty-for-a-shop/description/)

### My Approach

The Single Pass Approach operates by effectively iterating through the customer visit log string only once and recording the penalty score. This reduces the amount of computation required to determine the ideal time to close the store. Here is what we do :


1. Initialize variables:
   - `max_score` to store the maximum score encountered.
   - `score` to keep track of the current score.
   - `best_hour` to store the hour (index + 1) with the maximum score. Initialize it to -1 since we haven't found a better hour yet.

2. Loop through each character in the `customers` string:
   - If the current customer is 'Y', increment the `score` by 1 (indicating a customer arrived).
   - If the current customer is 'N', decrement the `score` by 1 (indicating a customer left).
   - Update `max_score` and `best_hour` if the current `score` is greater than `max_score`.

3. Return `best_hour + 1` to get the hour at which the business should close (adding 1 because the index is zero-based).



### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(1)` because we used an extra queue..

### Code (C++)

```cpp
class Solution {
public:
    int bestClosingTime(string customers) {
        int max_score = 0, score = 0, best_hour = -1;
        for(int i = 0; i < customers.size(); ++i) {
            if(customers[i]=='Y'){
                score++;
            }
            else score--;
            
            if(score > max_score) {
                max_score = score;
                best_hour = i;
            }
        }
        return best_hour + 1;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.