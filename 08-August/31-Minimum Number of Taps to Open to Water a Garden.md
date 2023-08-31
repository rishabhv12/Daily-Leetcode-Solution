## 31. Minimum Number of Taps to Open to Water a Garden


The problem can be found at the following link: [Question Link](https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/)


### My Approach

This is a question on greedy approch, as we have given how to find the range of the given taps . We can calculate the range of each tap and check if we can manage to find a tap which have largest current range. we can do it as :

1. Initialize variables:
   - `minRange` and `maxRange` to keep track of the minimum and maximum positions that can be covered by the currently selected taps (both initially set to 0).
   - `taps` to keep track of the number of taps used (initialized to 0).
   - `curindex` to keep track of the index of the last selected tap (initialized to 0).

2. Create a while loop that continues until `maxRange` is greater than or equal to `n`. This loop is used to extend the covered range step by step.

3. Inside the while loop, iterate through the taps (represented by the `ranges` vector) starting from the `curindex`. For each tap `i`:
   - Check if the tap can cover the current position (`i - ranges[i]`) and if it can extend the range further (`i + ranges[i] > maxRange`).
   - If both conditions are met, update `maxRange` to `i + ranges[i]` and update `curindex` to `i`. This tap is chosen as it extends the maximum coverage.

4. After examining all taps within the current range, if `minRange` is equal to `maxRange`, it means that no tap can be selected to extend the coverage further. In this case, return -1 to indicate that it's impossible to cover the entire range.

5. Increment `taps` to count the tap that has been used to extend the coverage.

6. Update `minRange` to `maxRange` to indicate that the current range has been fully covered.

7. Repeat steps 3-6 until `maxRange` is greater than or equal to `n`.


### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(1)` because we used an extra queue..


### Code (C++)

```cpp
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int minRange =0, maxRange =0;
        int taps =0; int curindex =0;

        while(maxRange < n){
            for(int i=curindex;i<ranges.size();i++){
                if(i-ranges[i]<=minRange && i+ranges[i]>maxRange){
                    maxRange = i+ranges[i];
                    curindex = i;
                }
            }
            if(minRange == maxRange) return -1;
            taps++;
            minRange = maxRange;
        }
        return taps;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.