## 01. Find Mode in Binary Search Tree

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/find-mode-in-binary-search-tree/description)


### My Approach


1. Define `current_val`, `current_count`, `max_count`, and `modes`. These will be used to keep track of the current value, its count, the maximum count, and the modes (most frequently occurring values) in the tree.

2. Inside the `findMode` function:
   - Call the `in_order_traversal` function on the root node to initiate the in-order traversal of the binary tree.
   - Return the `modes` vector, which contains the modes found during the traversal.

3. Define a private helper function, `in_order_traversal(TreeNode* node)`, that performs the in-order traversal of the binary tree:
   - Check if the current node is null (base case). If so, return without further processing.
   - Recursively traverse the left subtree of the current node by calling `in_order_traversal(node->left)`.

4. Within the `in_order_traversal` function:
   - Update the `current_count` based on whether the value of the current node matches the `current_val`. If it matches, increment `current_count` by 1; otherwise, set `current_count` to 1.
   - Check if `current_count` is equal to `max_count`. If it is, add the value of the current node to the `modes` vector because it's another mode.
   - If `current_count` is greater than `max_count`, update `max_count` to `current_count`, and reset the `modes` vector to contain only the value of the current node (since it's a new mode).
   - Update the `current_val` to the value of the current node for the next comparison.

6. After processing the left subtree and the current node, recursively traverse the right subtree of the current node by calling `in_order_traversal(node->right)`.



### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(n)`



### Code (C++)

```cpp

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        in_order_traversal(root);
        return modes;
    }
private:
    int current_val = 0;
    int current_count = 0;
    int max_count = 0;
    vector<int> modes;

    void in_order_traversal(TreeNode* node) {
        if (!node) return;
        
        in_order_traversal(node->left);
        
        current_count = (node->val == current_val) ? current_count + 1 : 1;
        if (current_count == max_count) {
            modes.push_back(node->val);
        } else if (current_count > max_count) {
            max_count = current_count;
            modes = { node->val };
        }
        current_val = node->val;

        in_order_traversal(node->right);
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.