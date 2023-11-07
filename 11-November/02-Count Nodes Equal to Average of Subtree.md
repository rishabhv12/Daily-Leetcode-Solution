## 02. Count Nodes Equal to Average of Subtree

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/)


### My Approach


1. Start with a global variable `int res = 0;` to keep track of the count of valid subtrees where the average of values is equal to the root's value.

2. Inside the `averageOfSubtree` function:
   - Call the helper function `porder(root, 0, 0)` to initiate the processing of the binary tree. Pass the root node, an initial sum of 0, and an initial count of 0.

3. Within the `porder` function:
   - Check if the current node `root` is null. If it is, return a pair {0, 0} representing the sum and count for an empty subtree.

4. Recursively traverse the left subtree by calling `porder(root->left, sum, count)` and store the result in `l`.

5. Recursively traverse the right subtree by calling `porder(root->right, sum, count)` and store the result in `r`.

6. Update `sum` to be the sum of the values in the left subtree, the value at the current node, and the sum of values in the right subtree: `sum = l.first + root->val + r.first`.

7. Update `count` to be the count of values in the left subtree, plus one for the current node, and the count of values in the right subtree: `count = l.second + 1 + r.second`.

8. Check if the average of the values in the current subtree (sum / count) is equal to the value at the root of the subtree (`root->val`). If it is, increment the `res` counter.

9. Return a pair {sum, count} representing the sum and count of values in the current subtree.



### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(n)`



### Code (C++)

```cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;

    pair<int,int> porder(TreeNode* &root,int sum,int count)
    {
        if(root == 0) return {0,0};

        auto l = porder(root->left,sum,count);
        auto r = porder(root->right,sum,count);

        sum = l.first + root->val + r.first;
        count = l.second + 1 + r.second;

        if(sum / count == root->val) res++;
        return {sum,count};
    }

    int averageOfSubtree(TreeNode* root) {
        porder(root,0,0);
        return res;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.