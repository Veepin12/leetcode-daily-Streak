#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:


vector<long long> distance(vector<int>& nums) {
    int n = nums.size();
    vector<long long> arr(n, 0);

    // Group indices by their value
    unordered_map<int, vector<int>> indexMap;
    for (int i = 0; i < n; i++)
        indexMap[nums[i]].push_back(i);

    for (auto& [val, indices] : indexMap) {
        // indices are already in sorted order (we iterate left to right)
        int k = indices.size();
        if (k == 1) continue; // no j != i exists

        // Build prefix sum of indices
        vector<long long> prefix(k + 1, 0);
        for (int r = 0; r < k; r++)
            prefix[r + 1] = prefix[r] + indices[r];

        // For each index position r in this group, compute contribution
        for (int r = 0; r < k; r++) {
            long long pi = indices[r];

            // Sum of |pi - pj| for all j to the LEFT (j < r)
            // = pi*r - prefix[r]
            long long leftSum = pi * r - prefix[r];

            // Sum of |pi - pj| for all j to the RIGHT (j > r)
            // = (prefix[k] - prefix[r+1]) - pi*(k-1-r)
            long long rightSum = (prefix[k] - prefix[r + 1]) - pi * (k - 1 - r);

            arr[indices[r]] = leftSum + rightSum;
        }
    }

    return arr;
}
};
int main(){
     Solution S;
    vector<int> nums ={ 1,1,1,3,3,2,2};
    vector<long long> res = S.distance(nums);

    for ( auto ele : res ){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}