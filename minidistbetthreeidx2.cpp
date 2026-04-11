#include <iostream>
 using namespace std;

 int mindistance(vector<int> & nums){
    unordered_map<int,vector<int>> mp;

    for(int i=0;i<nums.size() ; i++){
        mp[nums[i]].push_back(i);
    }

    int dist=INT_MAX;

    for(auto & ele : mp){
        vector<int > idx=ele.second;
        if(idx.size() < 3) continue;
        for(int i=0;i<idx.size();i++){
        int mindist = 2 * abs(idx[i] - idx[i+2]);
        dist=min(dist,mindist);
        }

    }
    return (dist==INT_MAX) ? -1: dist;



 }
 int main(){
    vector<int> nums={1,3,1,1};
    cout<<mindistance(nums);
    return 0;
 }