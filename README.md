# Trie

In trie1.cpp, we show a simple trie implementation using array. We put a special character (in this case I have put '$') to denote a root node. Ideally this is an empty node with 26 children corresponding to 26 alphabets. We assume that the input characters are all lowercase alphabets (uppercase alphabets would not have been a problem either, just calling toLower() would do the trick!).

In trie2.cpp, we show another implementation using hash table. We can use both std::map and std::unordered_map in C++. std::map is a balanced Binary Search Tree implementation where the insert and search operations are guaranteed to be O(logN). std::unordered_map is a hash table. The search and insert operations are O(1) in the average case, however, the worst case search can be O(N). Here N is the size of the hash table.
