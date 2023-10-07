## 06. Integer Break 


The problem can be found at the following link: [Question Link](https://leetcode.com/problems/integer-break/description)


### My Approach



1. Check if `n` is equal to 2:
   - If `n` is 2, return 1. This is because the maximum product of two positive integers that sum up to 2 is 1 * 1.

2. Check if `n` is equal to 3:
   - If `n` is 3, return 2. This is because the maximum product of two positive integers that sum up to 3 is 1 * 2.

3. Calculate the integer division `x` of `n` by 3:
   - `x = n / 3`

4. Check if `n` is divisible by 3 (i.e., `n % 3 == 0`):
   - If `n` is divisible by 3, return the result of raising 3 to the power of `x` using the `pow` function. This is because you can split `n` into `x` equal parts, each of size 3, to maximize the product.

5. Check if `(n - 1)` is divisible by 3 (i.e., `(n - 1) % 3 == 0`):
   - If `(n - 1)` is divisible by 3, return the result of raising 3 to the power of `x - 1` and multiplying it by 4. This is because you can split `n` into `x - 1` equal parts of size 3 and one part of size 4 to maximize the product.

6. If none of the above conditions are met:
   - Return the result of raising 3 to the power of `x` and multiplying it by 2. This is because you can split `n` into `x` equal parts of size 3 and one part of size 2 to maximize the product.





### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(1)` 
- **Auxiliary Space Complexity**: `O(1)`



### Code (C++)

```cpp

class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int x = n/3;
        if(n%3==0) return pow(3,x);
        else if((n-1)%3==0) return pow(3,x-1)*4;
        else return pow(3,x)*2; 
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.