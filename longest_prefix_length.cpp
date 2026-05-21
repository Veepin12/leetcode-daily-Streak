#include <iostream>
#include <vector>
#include <set>

using namespace std;
/*
Step 1: Build Prefixes from arr1:

Initialize an empty set arr1Prefixes to store all prefixes derived from arr1.
Iterate over each value val in arr1:
While val is not in arr1Prefixes and val is greater than 0:
Add val to arr1Prefixes (storing val as a prefix).
Update val to the next shorter prefix by removing the last digit (val /= 10).
Step 2: Find the Longest Matching Prefix in arr2:

Initialize longestPrefix to 0 to keep track of the length of the longest common prefix found.
Iterate over each value val in arr2:
While val is not in arr1Prefixes and val is greater than 0:
Reduce val by removing the last digit (val /= 10).
If val is greater than 0 (i.e., a matching prefix is found):
Update longestPrefix to the maximum of its current value and the length of the matched prefix (calculated using log10(val) + 1).
Return the length of the longest common prefix found.

*/

class TrieNode {
public:
    // Each node has up to 10 possible children (digits 0-9)
    TrieNode* children[10];
    TrieNode() {
        for (int i = 0; i < 10; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    // Insert a number into the Trie by treating it as a string of digits
    void insert(int num) {
        TrieNode* node = root;
        string numStr = to_string(num);
        for (char digit : numStr) {
            int idx = digit - '0';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
    }

    // Find the longest common prefix for a number in arr2 with the Trie
    int findLongestPrefix(int num) {
        TrieNode* node = root;
        string numStr = to_string(num);
        int len = 0;

        for (char digit : numStr) {
            int idx = digit - '0';
            if (node->children[idx]) {
                // Increase length if the current digit matches
                len++;
                node = node->children[idx];
            } else {
                // Stop if no match for the current digit
                break;
            }
        }
        return len;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;

        // Step 1: Insert all numbers from arr1 into the Trie
        for (int num : arr1) {
            trie.insert(num);
        }

        int longestPrefix = 0;

        // Step 2: Find the longest prefix match for each number in arr2
        for (int num : arr2) {
            int len = trie.findLongestPrefix(num);
            longestPrefix = max(longestPrefix, len);
        }

        return longestPrefix;
    }
};
int main(){
    int n ;
    cin>>n;
    vector<int> arr1(n);
    for( int i = 0; i < n; i++) cin>>arr1[i];
    int m ;
    cin>>m;

    vector<int> arr2(m);
    for( int i = 0; i < m; i++) cin>>arr2[i];
    Solution S;

    cout<<S.longestCommonPrefix(arr1,arr2);
    return 0;

}
