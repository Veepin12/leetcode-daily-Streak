#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
     struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
   };
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);

        for (auto& swap : allowedSwaps)
            dsu.unite(swap[0], swap[1]);

        // Group source values by their root
        unordered_map<int, unordered_map<int, int>> comp;
        for (int i = 0; i < n; i++)
            comp[dsu.find(i)][source[i]]++;

        int hamming = 0;
        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            auto& freq = comp[root];
            if (freq.count(target[i]) && freq[target[i]] > 0)
                freq[target[i]]--;   // matched!
            else
                hamming++;           // no source value available in component
        }

        return hamming;
    }
};

int main(){

    vector<int> source={1,2,3,4};
    vector<int> target={2,1,4,5};
    vector<vector<int>> allowedSwaps={{0,1},{2,3}};

    Solution S;
    cout<<S.minimumHammingDistance(source,target,allowedSwaps);
    return 0 ;
}