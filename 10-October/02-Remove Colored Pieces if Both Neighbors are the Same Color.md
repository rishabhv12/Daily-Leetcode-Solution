## 02. Remove Colored Pieces if Both Neighbors are the Same Color

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/)


### My Approach


1. Initialize scores for Alice and Bob (`aliceScore` and `bobScore`) to `zero`.

2. Iterate through the colors (excluding edge pieces) using a loop. For each piece in the iteration:

    * Check if it's A and its neighboring pieces are also A.
    If yes, increment `aliceScore` as Alice can remove the current piece.

    * Check if it's B and its neighboring pieces are also B.
    If yes, increment `bobScore` as Bob can remove the current piece.
    
3. Return `true` if Alice's score is `greater` than Bob's score; otherwise, return `false`.



### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` 
- **Auxiliary Space Complexity**: `O(1)`



### Code (C++)

```cpp

class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice=0;
        int bob=0;
        for(int i=1;i<colors.size()-1;i++)
        {
            if(colors[i-1]=='A' && colors[i+1]=='A' && colors[i]=='A')
            {
                alice++;
            }
            else if(colors[i-1]=='B' && colors[i+1]=='B' && colors[i]=='B')
            {
                bob++;
            }
        }
        cout<<alice<<" "<<bob<<endl;
        return alice>bob;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.