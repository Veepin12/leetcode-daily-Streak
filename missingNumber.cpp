//
//  missing_number.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 26/07/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
class Solution1{
public:
    int missingNumber(vector<int>& nums) {
        int xor_all = 0, xor_arr = 0;
        
        // XOR all numbers from 0 to n
        for (int i = 0; i <= nums.size(); i++) {
            xor_all ^= i;
        }
        
        // XOR all array elements
        for (int num : nums) {
            xor_arr ^= num;
        }
        
        // Missing number = xor_all ^ xor_arr
        return xor_all ^ xor_arr;
    }
};

class Solution {
public:
    
    // {0 , 0}.{1 , 1} ,{3 , 2}
    
    int miss( vector<int> & nums){
        
        if( nums.size() == 2 && nums[0] == 0 && nums[1] == 1) return 2;
        priority_queue<pair<int , int>> pq;
        vector<vector<int>> ans(nums.size() , vector<int> ( 2));
        
        sort(nums.begin() , nums.end());
        
        for(int i = 0; i < nums.size() ; i++){
            ans.push_back({i , nums[i]});
        }
        
        for( auto ele : ans){
            pq.push({ele[0] , ele[1]});
        }
        int res = 0;
        while( pq.size() > 0){
            auto ele = pq.top();
            pq.pop();
            
            int x = ele.first;
            int y = ele.second;
            
            if( x == y) continue;
            
            else{
                
                res = x;
             }
            
        }
        return res;
    }
};


int main(){
    
    int n;
    
    cin>>n;
    
    vector<int> nums(n );
    
    for( int i = 0;  i < n; i++){
        cin>>nums[i];
        
    }
    
    Solution S;
    Solution1 s;
    
    cout<<S.miss(nums)<<endl;
    cout<<s.missingNumber(nums)<<endl;
    
    return 0;
    
}
