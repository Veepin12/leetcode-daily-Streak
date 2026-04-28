//
//  minoperation.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 28/04/26.
//
/*
 Input: grid = [[2,4],[6,8]], x = 2
 Output: 4
 Explanation: We can make every element equal to 4 by doing the following:
 - Add x to 2 once.
 - Subtract x from 6 once.
 - Subtract x from 8 twice.
 A total of 4 operations were used.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int minOperations(vector<vector<int>>& nums, int x) {
        long  n = nums.size();
        long  m = nums[0].size();
        
        vector<int> ans;
        

        for( auto  row : nums){
            for(int ele : row){
                ans.push_back(ele);
                
            }
        }
        
        sort( ans.begin(),ans.end());
        int rem = ans[0]%x;
        
        for( int ele : ans){
            if(ele % x != rem) return -1;
        }
        
        int ans2 = ans[ans.size()/2];
        int opr = 0;
        for( int ele : ans){
            opr += abs(ele -ans2) / x;
        }
        
        return opr;
    }
};

int main(){
    Solution S;
    vector<vector<int>> nums = {{2,4},{6,8}};
    int x = 2;
    cout<<S.minOperations(nums,x);
    return 0;
}
