## 28. Implement stack using queues

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/implement-stack-using-queues/description/)

### My Approach

This is the standard problem , In this we can create two queue and then -

1. For push operation, first we push the givem value in queue 2
2. After that we push all the value of queue 1 in queue 2 ,it will result in the first element will be present at the last of queue
3. We swap queue 1 and 2 it will result that the first element of queue is the element we just pushed for in queue 2.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(n)` because we used an extra queue..

### Code (C++)

```cpp
class MyStack {
    queue<int> q1, q2;
public:
    MyStack() {

    }
    
    void push(int x) {
        q2.push(x);

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp;
        temp = q1;
        q1 = q2;
        q2 = temp;

    }
    
    int pop() {
 
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty()) return true;
        else return false;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.