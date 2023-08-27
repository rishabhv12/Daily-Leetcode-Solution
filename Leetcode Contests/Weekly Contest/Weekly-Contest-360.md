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

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion/3965080/weekly-contest-360). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.