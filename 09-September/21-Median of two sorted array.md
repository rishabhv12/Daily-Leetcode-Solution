## 21-Median of Two Sorted Arrays

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description)


### My Approach


1. Calculate the sizes of `nums1` and `nums2` and store them in variables `n` and `m`, respectively.

2. Check if the size of `nums1` is greater than the size of `nums2`. If it is, swap the arrays to ensure that `nums1` is the smaller array.

3. Calculate the total size of the combined array as `size = n + m`.

4. Initialize variables `low` and `high` to 0 and `n`, respectively. These variables will be used for binary search on the smaller array (`nums1`) to find the partition point.

5. Calculate the left partition size as `left = (n + m + 1) / 2`. This is because if the combined size is odd, you want the left partition to have one more element.

6. Perform a binary search within the range `[low, high]` to find the partition point in `nums1`. Use the `mid1` and `mid2` variables to partition `nums1` and `nums2`, respectively.

7. Calculate `l1`, `r1`, `l2`, and `r2`, which represent the elements to the left and right of the partition points in `nums1` and `nums2`.

8. Check if `l1` is less than or equal to `r2` and `l2` is less than or equal to `r1`. This condition ensures that you have found the correct partition points.

   a. If the condition is met and `size` is odd (`size` is an odd number), return the maximum of `l1` and `l2` as the median.
   
   b. If the condition is met and `size` is even (`size` is an even number), return the average of the maximum of `l1` and `l2` and the minimum of `r1` and `r2` as the median.

9. If the condition in step 8 is not met, adjust the binary search range (`low` and `high`) based on whether `l1` is greater than `r2` or `l2` is greater than `r1`. This adjustment ensures that you move the partition point in the correct direction.

10. Repeat the binary search until you find the correct partition points that satisfy the condition in step 8.

11. If the binary search does not find the correct partition points, return 0.0 as there might be an issue with the input arrays.



### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(log(min(n,m)))` 
- **Auxiliary Space Complexity**: `O(1)`


### Code (C++)

```cpp

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , m = nums2.size();

        if(n > m) return findMedianSortedArrays(nums2,nums1);

        int size = n+m;
        int low =0, high = n;
        int left = (n+m+1)/2;
        while(low<=high){

            int mid1 = (low+high) >> 1;
            int mid2 = left - mid1;

            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int r1 = (mid1 == n) ? INT_MAX : nums1[mid1];

            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int r2 = (mid2 == m) ? INT_MAX : nums2[mid2];


            if(l1<=r2 && l2 <= r1){
                if(size&1) return max(l1,l2);
                return (double)(max(l1,l2)+ min(r1,r2)) /2.0;
            }

            else if(l1 > r2) high = mid1;
            else low = mid1+1;
        }
        return 0.0;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.