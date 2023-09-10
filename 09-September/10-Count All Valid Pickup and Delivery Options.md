## 10. Count All Valid Pickup and Delivery Options

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/)


### My Approach

1. **Total Number of Permutations (2n!)**: When you have a set of 2n distinct elements and you want to arrange them in different orders, you can calculate the total number of permutations using the factorial notation (n!). Factorial (n!) means multiplying all positive integers from 1 to n.

   For example, if you have 4 distinct elements, the total number of permutations is 4! = 4 x 3 x 2 x 1 = 24.

2. **Pairs and Order Determination**: Now, For each pair, the order is determined, This means that within each pair of elements, there are only two possible ways to arrange them: either the first element followed by the second or the second element followed by the first. 

   For example, if you have a pair of elements A and B, the two possible permutations are AB and BA.

3. **Accounting for Pairs**: In a set of 2n elements, you'll have n pairs. For each of these pairs, there are 2 ways to arrange the elements within the pair. To account for all possible arrangements of the pairs, you multiply 2 by itself n times (2^n).

   For example, if you have 2 pairs, you have 2^2 = 4 possible arrangements of the pairs.

4. **Dividing by 2^n**: Since you've counted all possible permutations of pairs twice in step 3, you need to correct for this double counting. To do this, you divide the total number of permutations (2n!) by 2^n.

   For example, if you have 4 pairs (8 elements in total), you have 8! permutations initially. However, each pair's permutations are counted twice, so you divide by 2^4 = 16 to correct for this double counting.

Putting it all together, the formula (2n)! / (2^n) correctly calculates the number of unique permutations of 2n distinct elements when you need to account for the order within pairs, ensuring that you don't overcount permutations of the same elements within those pairs.


### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(1)`


### Code (C++)

```cpp

class Solution {
public:
    int countOrders(int n) {
        long long int ans = 1, mod = 1e9 + 7;
        for(int i = 1; i <= n; i++){
            ans = ans * (i * 2 - 1) * i % mod;
        }
        return (int)ans;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.