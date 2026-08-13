//
//  longest_subsequence.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 13/08/26.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Structure to hold information for each node in the Segment Tree
struct Node {
    int max_len;
    int pref_len;
    int suff_len;
    char pref_char;
    char suff_char;
    int len;
};

class SegmentTree {
private:
    int n;
    vector<Node> tree;

    // Merge function to combine left and right child nodes
    Node merge(const Node& left, const Node& right) {
        Node res;
        res.len = left.len + right.len;
        res.pref_char = left.pref_char;
        res.suff_char = right.suff_char;
        
        // Calculate prefix length
        res.pref_len = left.pref_len;
        if (left.pref_len == left.len && left.pref_char == right.pref_char) {
            res.pref_len += right.pref_len;
        }
        
        // Calculate suffix length
        res.suff_len = right.suff_len;
        if (right.suff_len == right.len && right.suff_char == left.suff_char) {
            res.suff_len += left.suff_len;
        }
        
        // Calculate maximum length of repeating characters
        res.max_len = max(left.max_len, right.max_len);
        if (left.suff_char == right.pref_char) {
            res.max_len = max(res.max_len, left.suff_len + right.pref_len);
        }
        
        return res;
    }

    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start], 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char c) {
        if (start == end) {
            tree[node] = {1, 1, 1, c, c, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, c);
        } else {
            update(2 * node + 1, mid + 1, end, idx, c);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    SegmentTree(const string& s) {
        int n = s.length();
        tree.resize(4 * n);
        if (n > 0) build(1, 0, n - 1, s);
    }

    void update(int idx, char c) {
        update(1, 0, n - 1, idx, c);
    }

    int getMaxLen() {
        return tree[1].max_len;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree st(s);
        long k = queryIndices.size();
        vector<int> ans;
        ans.reserve(k);
        
        for (int i = 0; i < k; ++i) {
            st.update(queryIndices[i], queryCharacters[i]);
            ans.push_back(st.getMaxLen());
        }
        
        return ans;
    }
};

int main(){
    
    Solution S;
    string s  = "byzz";
    
    
    string queryCharacters = "aa";
    
    
    //Input: s = "abyzz", queryCharacters = "aa", queryIndices = [2,1]
    //Output: [2,3]
    
    vector<int> queryIndices = {2 ,1};
    
    vector<int> ans = S.longestRepeating(s, queryCharacters, queryIndices);
    
    for( int i = 0; i < ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
