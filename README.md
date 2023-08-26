## Daily-Leetcode-Solution
### Todays Question: 

### Brute Force Description :
Just Traverse the letters array and check every element if this is greater than the target element or not.?
Pta hai aisa kyun kyunki our array is sorted here.

**Time Complexity :** `O(n)O(n)O(n)`
**Space Complexity :** `O(1)O(1)O(1)`

### Binary Search Description :
Aree socho yrrr lexicographically greater hi chaiye na aur here sorted array bhi hai to why not use binary search.

Here comes a solution with binary search. Where in O(logn)O(logn)O(logn) Time Complexity apna kaam ho jayega.
And Space Complexity will be same O(1)O(1)O(1)

The code of both approaches is given below. Do check it out.
```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n= letters.size();
        for(int i=0;i<n;i++){
            if(letters[i]>target) return  letters[i];
        }
        return letters[0];
    }
};
```
