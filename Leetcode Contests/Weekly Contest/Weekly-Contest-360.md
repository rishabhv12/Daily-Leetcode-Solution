## 01. Furthest Point From Origin

The problem can be found at the following link: [Question Link](https://leetcode.com/contest/weekly-contest-360/problems/furthest-point-from-origin/)

### My Approach

This is the very basic question of counting values, so the intution is check is which side we can move if we take consider all the left and right movement and then add the remaining blank space on that side.  

1. Count the number of left , right and the blank space
2. Find the absolute difference between left and right
3. Add remaining blank space to that absolute difference 

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)`

- **Auxiliary Space Complexity**: `O(1)`

### Code (C++)

```cpp

int furthestDistanceFromOrigin(string moves) {

    int left =0 , right =0, blank =0;
    int ans=0;

    for(int i=0;i<moves.size();i++){

        if(moves[i]=='L'){
            left++;
        }
        else if(moves[i]=='R'){
            right++;
        }
        else blank++;
    }

    ans = abs(left-right)+blank;
    return ans;
}

```


## 02. Find the Minimum Possible Sum of a Beautiful Array

The problem can be found at the following link: [Question Link](https://leetcode.com/contest/weekly-contest-360/problems/find-the-minimum-possible-sum-of-a-beautiful-array/)

### My Approach

This is the leetcode medium question, the approch to this question is because we can add only distint value and so need to keep track of the values we added in the answer . So we use a set and add the current value which we are adding in the answer , and we can do this as:

1. Initialise set of an integer , current value to 1 and the answer variable to 0
2. Define a while loop in which we check if the current value is present in set or not 
3. If current value is not in the set the add current value to answer else we increase current 
4. Insert current value and (target - current) in the set . 

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)`

- **Auxiliary Space Complexity**: `O(1)`

### Code (C++)

```cpp

long long minimumPossibleSum(int n, int target) {
        set<long long> st; 
        int i=0, current=1;
        long long ans = 0;

        while(i<n){
            if(st.find(current) == st.end()){

                ans += current;
                st.insert((abs(target-current)));
                st.insert(current);

                i++;
                if(i==n) break;
            } 
            current++;
        }
        return ans;
    }

```



## 03. Minimum Operations to Form Subsequence With Target Sum

The problem can be found at the following link: [Question Link](https://leetcode.com/contest/weekly-contest-360/problems/minimum-operations-to-form-subsequence-with-target-sum/)

### My Approach

This is the leetcode Hard question. The intution for solution is that, we have given all the value in the array as power of 2 . So we try to think in the terms of bit and check for set bits in target and the bits set in the array .

There are 2 condition that can be possible -

1. We find the target sum without any operation .

2. We can not find the sum directly - In this case we check for bits which are set and which are not set in target .

Suppose we find a bit in not set in our array and is set in the target . Then we try to set that bit using remaing number present on the left side of the array .
Because             ` 2<sup>i</sup>  = 2<sup>i-1</sup> +1 `

And if we can not able to set the bit from remaining numbers then we find first non zero nuber inright of array and keep breaking it untill we set that bit .


### Algorithm
Certainly, here's a point-wise algorithm for the `minOperations` function:

1. Initialize a vector `freq` of size 31 to keep track of the frequency of each bit position.

2. Iterate through each number `i` in the `nums` vector and create a frequency array for each number

3. Initialize two variables: `carry` and `operations`, both initially set to 0. `carry` will be used to track the remaining bits after using them to reach the target, and `operations` will count the number of operations performed.

4. Iterate through each bit position from least significant to most significant (from 0 to 30):
   - Check if the `i`-th bit in the `target` is not set (i.e., `(target & (1 << i)) == 0`):
     - If true, add the product of the frequency of the `i`-th bit and `2^i` to `carry`.
     - Continue to the next iteration.

5. If the `i`-th bit in the `target` is set:
   - Check if there are any numbers in the `nums` vector that have a `1` in the `i`-th bit (i.e., `freq[i] > 0`):
     - If true, use one of these numbers and subtract one from its frequency.
     - Add the product of the remaining frequency of the `i`-th bit and `2^i` to `carry`.
     - Continue to the next iteration.

6. If neither of the above conditions is met, check if the `carry` is greater than or equal to `2^i`:
   - If true, subtract `2^i` from `carry`.
   - Continue to the next iteration.

7. If none of the above conditions are met:
   - Initialize a boolean variable `found` to `false`.
   - Iterate from the next bit position `j` (from `i+1` to 30):
     - Check if there are any numbers in the `nums` vector with a `1` in the `j`-th bit (i.e., `freq[j] > 0`):
       - If true, set `found` to `true`.
       - Perform a series of operations to borrow bits from higher positions:
         - Iterate from `k` starting from `j` and moving down to `i+1`:
           - Decrement the frequency of the `k`-th bit by 1.
           - Increment the frequency of the `k-1`-th bit by 2.
           - Increment the `operations` counter by 1 for each operation.
       - Break out of the loop.

8. If `found` is still `false` after the loop in step 7, return `-1` as it's not possible to reach the target.

9. Repeat steps 4 to 8 for each bit position, moving from least significant to most significant.

### Code (C++)

```cpp

int minOperations(vector<int>& nums, int target) {
        vector<long long> freq(31);
        
        for(auto i:nums){
            int pwr = 0;
            while(!(i&1)){
                pwr++;
                i >>= 1;
            }
            freq[pwr]++;
        }
        
        long long carry =0, operations =0;
        for(int i=0;i<31;i++){
            // Check if the ith bit in the target is set or not
            if((target & (1<<i)) == 0){
                carry += freq[i] * (1<<i);
                continue;
            }
            
            // If it is set then we use one value and add remaining value to carry 
            if(freq[i] > 0){
                freq[i]--;
                carry += freq[i]* (1<<i);
                continue;
            }
            if(carry >= (1<<i)){
                carry -= (1<<i);
                continue;
            }
            
            bool found = false;
            for(int j=i+1;j<31;j++){
                if(freq[j] == 0) continue;
                found = true;
                
                for(int k=j;k>i;k--){
                    freq[k]--;
                    freq[k-1] +=2;
                    operations++;
                }
                break;
            }
            if(!found) return -1;
            i--;
        }
        return operations;
    }

```
### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion/3965080/weekly-contest-360). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.