## 03. Build an Array With Stack Operations

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/build-an-array-with-stack-operations/description/)


### My Approach


1. Initialize an empty vector of strings named `operations` to store the sequence of operations.

2. Initialize an integer variable `targetIndex` to 0, which will keep track of the current index in the `target` array.

3. Inside the for loop:
   - Check if `targetIndex` is equal to the size of the `target` array. If it is, there are no more elements to match in the `target` array, so exit the loop by using a `break` statement.

4. Check if the current element in the `target` array at index `targetIndex` is equal to `i`. If it is, it means the element at index `targetIndex` in the `target` array matches the current value `i` in the range 1 to `n`. In this case:
   - Append "Push" to the `operations` vector to represent pushing the current value `i` onto the stack.
   - Increment `targetIndex` to move to the next element in the `target` array.

5. If the current element in the `target` array at index `targetIndex` is not equal to `i`, it means that the element at index `targetIndex` in the `target` array does not match the current value `i` in the range 1 to `n`. In this case:
   - Append "Push" to the `operations` vector to represent pushing the current value `i` onto the stack.
   - Append "Pop" to the `operations` vector to represent popping an element from the stack.

6. Continue the loop until all elements in the `target` array have been matched or until the loop reaches the end of the range from 1 to `n`.

7. After the loop, return the `operations` vector, which contains the sequence of operations required to transform an array into the `target` array using a stack.



### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(n)`



### Code (C++)

```cpp

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;
        
        int targetIndex = 0;
        
        for (int i = 1; i <= n; i++) {
            if (targetIndex == target.size()) {
                break;  // No more elements to match in the target array
            }
            
            if (target[targetIndex] == i) {
                operations.push_back("Push");
                targetIndex++;
            } else {
                operations.push_back("Push");
                operations.push_back("Pop");
            }
        }
        
        return operations;
    }

};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.