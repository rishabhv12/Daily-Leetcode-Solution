## 07. Reverse Linked List II

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/pascals-triangle/description/)


### My Approach

1. Check if `left` is equal to `right`. If they are equal, there is no need to reverse the list, so return the original `head`.

2. Initialize two pointers:
   - `prev` as `NULL` (to keep track of the node before the `left`-th node in the sublist).
   - `curr` as `head` (to traverse the list).

3. Traverse the list to position `left - 1` using a `for` loop:
   - Start the loop with `i` initialized to 1.
   - In each iteration, update `prev` to `curr` and move `curr` to the next node in the list (`curr = curr->next`).

4. After the loop, `prev` points to the node before the `left`-th node, and `curr` points to the `left`-th node to be reversed.

5. Create two additional pointers:
   - `first` as `prev` (to keep track of the node before the reversed sublist).
   - `newend` as `curr` (to keep track of the first node in the reversed sublist).
   - `nextNode` as `curr->next` (to initialize the next node after the reversed sublist).

6. Use a `for` loop to reverse the sublist from `left` to `right`:
   - Initialize a loop variable `i` to 0.
   - In each iteration, reverse the `curr` node by updating `curr->next` to point to `prev`, then update `prev` to `curr`, and `curr` to `nextNode`.
   - Additionally, update `nextNode` to the next node in the list (`nextNode = nextNode->next`) if `nextNode` is not `NULL`.

7. After the loop, the sublist from `left` to `right` is reversed, and `prev` points to the new head of this reversed sublist, while `curr` points to the node after the reversed sublist.

8. Check if `first` is not `NULL` (i.e., the sublist to be reversed does not start at the beginning of the list). If not `NULL`, update `first->next` to point to the new head of the reversed sublist (`prev`).

9. If `first` is `NULL`, it means the sublist to be reversed starts at the beginning of the list. In this case, update `head` to point to the new head of the reversed sublist (`prev`).


### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(1)`


### Code (C++)

```cpp

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
    
        for(int i=1;i<left;i++) {
            prev = curr;
            curr = curr -> next;
        }

        ListNode* first = prev;
        ListNode* newend = curr;
        ListNode* nextNode = curr -> next;

        for(int i = 0;i<right - left + 1;i++) {
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
            if(nextNode != NULL) nextNode = nextNode -> next;
        }

        if(first != NULL) first -> next = prev;
        else head = prev;
        
        newend -> next = curr;
        return head;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.