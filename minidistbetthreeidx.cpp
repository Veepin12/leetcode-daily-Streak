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
    
    int MinimumDistance(vector<int> & nums){
        int n=nums.size();
        int mindist=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]==nums[j] && nums[j]==nums[k]){
                        int dist = abs(i-j) + abs(j-k) + abs(k-i);
                        mindist=min(mindist,dist);

                        

                    }
                }
            }
        }
        return (mindist==INT_MAX) ? -1: mindist;
    }
};
int main(){
    vector<int> nums={1,2,1,1,3};
    Solution S;
    cout<<S.minimumDistance(nums);
    cout<<S.MinimumDistance(nums);

    return 0;
}