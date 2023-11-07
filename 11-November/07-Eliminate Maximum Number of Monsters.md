## 07. Eliminate Maximum Number of Monsters

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/eliminate-maximum-number-of-monsters/description/)


### My Approach


1. Initialize a vector of integers `time` to store the time it takes for each person to reach their destination.

2. Inside the loop, calculate the time it takes for the current person to reach their destination:
   - Calculate the floating-point value by dividing `dist[i]` by `speed[i]`.
   - Use `ceil` to round the floating-point result to the nearest integer.
   - Store the rounded result in the `time` vector.

4. After the loop, sort the `time` vector in ascending order. This will give you a list of times in ascending order, representing when each person will reach their destination.

5. Initialize an integer `t` to 0. This variable will be used to keep track of the current time.

6. Inside the loop, check if the current time `t` is less than the time `i` for the current person. If it is, increment `t` by 1 to simulate the elimination of the person who arrives earliest.

8. If the current time `t` is greater than or equal to the time `i` for the current person, break out of the loop since you have eliminated the maximum number of people possible without causing a collision.


### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(n)`



### Code (C++)

```cpp

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> time;

        for(int i=0;i<dist.size();i++){
            int x = ceil((double)(dist[i])/(double)(speed[i]));
            time.push_back(x);
        }
        sort(time.begin(),time.end());
        int t =0;
        for(auto i:time){
            if(t<i) ++t;
            else break;
        }
        return t;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.