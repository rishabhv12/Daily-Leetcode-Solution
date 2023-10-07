## 04. Design HashMap


The problem can be found at the following link: [Question Link](https://leetcode.com/problems/design-hashmap/description/)


### My Approach


Certainly! Here's a step-by-step explanation of the `MyHashMap` class and its methods:

1. Class Declaration:
   - The `MyHashMap` class is declared.
   - It includes a private data member `mp`, which is a vector of lists of pairs. This data structure will be used to implement a hash map.
   - Another private data member `size` is initialized to 10. This represents the initial size of the hash map.
   - The constructor `MyHashMap` is defined, which resizes the `mp` vector to the specified size.

2. Hash Function:
   - The `hash` method is defined to compute the hash value for a given key. It uses the modulo operation (`key % size`) to map keys to a valid index within the range of the `mp` vector.

3. put Method:
   - The `put` method is used to insert a key-value pair into the hash map.
   - It calculates the index `i` using the hash function.
   - It iterates through the list at index `i` using a for loop.
   - Inside the loop, it checks if the key already exists in the list. If it does, it updates the corresponding value and returns.
   - If the key doesn't exist in the list, it adds a new pair (key, value) to the list.

4. get Method:
   - The `get` method is used to retrieve the value associated with a given key from the hash map.
   - It calculates the index `i` using the hash function.
   - It iterates through the list at index `i` using a for loop.
   - Inside the loop, it checks if the key matches the key in the pair. If it finds a match, it returns the corresponding value.
   - If it doesn't find a match after iterating through the list, it returns -1 to indicate that the key was not found.

5. remove Method:
   - The `remove` method is used to delete a key-value pair from the hash map.
   - It calculates the index `i` using the hash function.
   - It iterates through the list at index `i` using a for loop.
   - Inside the loop, it checks if the key matches the key in the pair. If it finds a match, it removes that pair from the list using the `erase` method and returns, effectively deleting the key-value pair.




### Time and Auxiliary Space Complexity

- Time Complexity: `O(n)` 
- Auxiliary Space Complexity: `O(n)`



### Code (C++)

```cpp

class MyHashMap {
public:
    vector<list<pair<int,int>>>mp;
    int size=10;
    MyHashMap() {
       mp.resize(size); 
    }
    int hash(int key)
    {
        return key%size;
    }
    void put(int key, int value) {
       int i=hash(key);
        for(auto it=mp[i].begin();it!=mp[i].end();it++)
        {
            if(it->first==key)
            {
                it->second=value;
                return;
            }
        }
        mp[i].push_back({key,value});
    }
    
    int get(int key) {
       
        int i=hash(key);
        for(auto it=mp[i].begin();it!=mp[i].end();it++)
        {
            if(it->first==key)
            {
                return it->second;
            
            }
        }
        return -1;
    }
    
    void remove(int key) {
      
        int i=hash(key);
        for(auto it=mp[i].begin();it!=mp[i].end();it++)
        {
            if(it->first==key)
            {
               mp[i].erase(it);
                return;
            }
        }
    }
};


```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://leetcode.com/discuss/general-discussion). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [rishabhv12/Daily-Leetcode-Solution](https://github.com/rishabhv12/Daily-Leetcode-Solution) repository.