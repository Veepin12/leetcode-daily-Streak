#include<iostream>
using namespace std;
class Solution {
public:
    int minimumDistance(vector<int> & nums){
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        
        for(auto &ele : mp){
            vector<int> &idx=ele.second;
            if(idx.size() < 3) continue;
            for(int i=0;i+2<idx.size();i++){
                int mindist= 2 *abs(idx[i]-idx[i+2]);
                ans=min(ans,mindist);
                
            }
        }
        return (ans==INT_MAX)? -1: ans;
    }
};
int main(){
    vector<int> nums={1,2,1,1,3};
    Solution S;
    cout<<S.minimumDistance(nums);

    return 0;
}