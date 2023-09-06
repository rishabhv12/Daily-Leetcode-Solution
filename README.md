## Leetcode question of the day 

## 06. Split Linked List in Parts

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/split-linked-list-in-parts/)


### My Approach

The key insight here is that we can efficiently split the linked list into equal-sized parts by calculating the minimum guaranteed size of each part (n) and distributing any extra nodes (r) as evenly as possible among the first r parts. This approach ensures that we meet both conditions specified in the problem statement.

By maintaining two pointers (node and prev) and updating them as we traverse the linked list, we can keep track of the current part and efficiently split the list into k parts.


1. Create a vector of ListNode pointers called "parts" with k elements, all initialized to nullptr. This vector will store the head nodes of the k sublists.

2. Initialize a variable "len" to 0. This variable will be used to calculate the total number of nodes in the linked list.

3. Loop through the linked list using a pointer "node" starting from the "root" node.
   - For each node in the list, increment the "len" variable by 1, counting the total number of nodes.

4. Calculate two values, "n" and "r":
   - "n" represents the approximate number of nodes in each of the k sublists, which is obtained by dividing "len" by "k."
   - "r" represents the remainder of the division "len % k," which accounts for the number of sublists that need to have an extra node to balance them.

5. Initialize two pointers, "node" (pointing to the head of the original list) and "prev" (initialized to nullptr).

6. Loop through the process of splitting the linked list into k parts:
   - Iterate from 0 to k-1 in a loop (i.e., for each of the k sublists).
   - Assign the current "node" to the "i"-th element of the "parts" vector. This marks the beginning of the sublist.
   - Loop "j" from 0 to "n + (r > 0)" times. This inner loop traverses through the sublist, where "n" is the average number of nodes per sublist, and "r > 0" indicates that some sublists need an extra node.
   - Inside the inner loop, update the "prev" pointer to point to the current "node," and move the "node" pointer to the next node in the original list.
   - Set the "next" pointer of "prev" to nullptr. This effectively cuts off the current sublist from the original list.

7. After the loop completes, the "parts" vector contains the k sublists, and each sublist is separated from the original list.

8. Return the "parts" vector, which now holds the head nodes of the k sublists.


### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(1)`


### Code (C++)

```cpp

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> parts(k, nullptr);

        int len = 0;
        for (ListNode* node = root; node; node = node->next){
            len++;
        }

        int n = len / k, r = len % k;
        ListNode* node = root, *prev = nullptr;

        for (int i = 0; node && i < k; i++, r--) {
            
            parts[i] = node;
            for (int j = 0; j < n + (r > 0); j++) {
                prev = node;
                node = node->next;
            }
            
            prev->next = nullptr;
        }
        return parts;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.