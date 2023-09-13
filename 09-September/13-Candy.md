## 13. Candy

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/candy/)


### My Approach

We can apply the approach of valley and peak problem. Peek will have maximum candy while valley have 1 candy.

1. Initialize candy_count = no. of childern ( bcz each children must have 1 candy )

2. Start the looping from 1 to arr.size() -1

3.  if current value is equal to previous value then they have same number of Candy.

4. if we have increasing slope , we increase the peak value by one for each increasing element
`while( arr [ i ] > arr [ i - 1 ] ) peak++;` and add count_candy with peak value.

5. if we have decreasing slope , we increase the value of valley by one for each decreasing element
`while ( arr [ i ] < arr [ i - 1 ] ) valley++` and add count_candy with valley value.

6. count_candy = count_candy - min ( peak , valley )


### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(1)`


### Code (C++)

```cpp

class Solution {
public:
    int candy(vector<int>& ratings) {
        int peak = 0 , valley = 0 , size = ratings.size(),candy_count = size ;
        for(int i = 1 ; i< size ;){
            if(ratings[i] == ratings[i-1]){ i++ ; continue;}
            peak = 0 ;
            valley = 0;
            while( i< size && ratings[i] > ratings[i-1]){
                peak++;
                i++;
                candy_count += peak;
            }
               
            
            while(i<size && ratings[i] < ratings[i-1]){
                valley++;
                i++;
                candy_count += valley;
            }
               
            candy_count -= min(peak,valley);
        }
        return candy_count;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.