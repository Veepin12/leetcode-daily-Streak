#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        
        // 1. Group indices for each value
        for (int i = 0; i < n; ++i) {
            pos[nums[i]].push_back(i);
        }
        
        vector<int> ans;
        for (int q_idx : queries) {
            int val = nums[q_idx];
            const vector<int>& idx_list = pos[val];
            
            // 2. If the value only appears once, return -1
            if (idx_list.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            
            // 3. Find the position of the query index in our stored list
            auto it = lower_bound(idx_list.begin(), idx_list.end(), q_idx);
            int k = distance(idx_list.begin(), it);
            int m = idx_list.size();
            
            // 4. Check neighbors (circularly)
            // Next element (with wrap-around)
            int next_idx = idx_list[(k + 1) % m];
            int dist1 = (next_idx - q_idx + n) % n;
            
            // Previous element (with wrap-around)
            int prev_idx = idx_list[(k - 1 + m) % m];
            int dist2 = (q_idx - prev_idx + n) % n;
            
            ans.push_back(min(dist1, dist2));
        }
        
        return ans;
    }
};


int main(){
    Solution S;
    vector<int> nums={1,3,1,1,4,5};
    vector<int> queries={0,4,1};

    vector<int> res = S.solveQueries(nums,queries);

    for(auto ele : res){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}