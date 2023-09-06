## 05. Copy List with Random Pointer

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/copy-list-with-random-pointer/)


### My Approach

1. Create an unordered_map called "map" to establish a mapping between the nodes of the original linked list and their corresponding nodes in the new copied list. The keys will be the original nodes, and the values will be the newly created nodes.

2. Initialize a pointer "itr" and set it to the head of the original linked list. This pointer will be used for traversing the original list.

3. Start a while loop to iterate through the original linked list until the pointer "itr" reaches the end (i.e., until "itr" is not null).
   
   a. Inside the loop:
      - Create a new node with the same value as the current node pointed to by "itr." This node will become a corresponding node in the new list.
      - Add an entry to the "map" where the key is the current node pointed to by "itr," and the value is the newly created node.
      - Move the "itr" pointer to the next node in the original list.

4. Reset the "itr" pointer to the head of the original list to prepare for the second pass.

5. Start another while loop to iterate through the original list again, using the same "itr" pointer.

   a. Inside this loop:
      - Update the "next" pointer of the newly created node (corresponding to the current node pointed to by "itr") to point to the newly created node that corresponds to the next node in the original list. This establishes the "next" relationship in the new list.
      - Update the "random" pointer of the newly created node to point to the newly created node that corresponds to the random node of the current node pointed to by "itr." This establishes the "random" relationship in the new list.
      - Move the "itr" pointer to the next node in the original list.

6. After the second pass, all the "next" and "random" pointers in the new list are properly connected.

7. Return the node in the "map" that corresponds to the head of the original list. This is the head of the new copied list.



### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(n)`


### Code (C++)

```cpp

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> map;

        Node* itr = head;
        while(itr) {
            map[itr] = new Node(itr->val);
            itr=itr->next;
        }

        itr = head;
        while(itr) {
            map[itr]->next = map[itr->next];
            map[itr]->random = map[itr->random];
            itr = itr->next;
        }

        return map[head];
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.