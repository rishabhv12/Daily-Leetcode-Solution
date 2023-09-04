## 04. Linked List Cycle

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/linked-list-cycle/)


### My Approach


1. Check if the `head` of the linked list is `NULL` (i.e., the list is empty). If it is, return `false` because an empty list cannot have a cycle.

2. Initialize two pointers, `fast` and `slow`, both initially pointing to the `head` of the linked list. These pointers will be used to traverse the list.

3. Enter a `while` loop that continues as long as both the `fast` and `fast->next` pointers are not `NULL`. This condition ensures that the `fast` pointer can move two steps ahead without causing a null reference error.

4. Inside the loop:
   a. Move the `fast` pointer two steps ahead by assigning `fast = fast->next->next`.
   b. Move the `slow` pointer one step ahead by assigning `slow = slow->next`.

5. Check if the `fast` pointer is equal to the `slow` pointer. If they are equal, this means that the two pointers have met at the same node within the linked list. This is an indication that a cycle exists in the linked list, so return `true`.

6. If the `fast` and `slow` pointers do not meet within the loop, continue iterating through the linked list until one of the following conditions is met:
   - The `fast` pointer reaches the end of the list (`fast == NULL` or `fast->next == NULL`). This means there is no cycle in the list, so return `false`.
   - The `fast` and `slow` pointers meet (indicating a cycle). In this case, the function returns `true` within the loop.

7. If none of the conditions in step 7 are met and the loop exits, return `false`. This means that the entire linked list has been traversed, and no cycle has been detected.

The algorithm utilizes the fact that the `fast` pointer moves at twice the speed of the `slow` pointer. If there is a cycle, the `fast` pointer will eventually catch up to the `slow` pointer, indicating the presence of a cycle. If there is no cycle, the `fast` pointer will reach the end of the list without intersecting the `slow` pointer, and the function will return `false`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(1)`


### Code (C++)

```cpp

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        
        ListNode *fast = head;
        ListNode *slow = head;
    
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow)
                return true;
        }
        return false;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.