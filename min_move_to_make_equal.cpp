//
//  Min_move_to_make_equal.cpp
//  DSA_with_cpp
//
//  Created by Veepin kumar on 01/11/26.
//
/*
 
 Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

 In one move, you can increment n - 1 elements of the array by 1.

  

 Example 1:

 Input: nums = [1,2,3]
 Output: 3
 Explanation: Only three moves are needed (remember each move increments two elements):
 [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 Example 2:

 Input: nums = [1,1,1]
 Output: 0
  

 Constraints:

 n == nums.length
 1 <= nums.length <= 105
 -109 <= nums[i] <= 109
 The answer is guaranteed to fit in a 32-bit integer.
  
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        long n = nums.size();
        
        int mn = INT_MAX , p = 0;
        for( int i = 0; i < n; i++){
            
            mn = min( mn , nums[i]);
        }
        
        for( int x : nums){
            p += x - mn;
        }
        return p;
        
    }
};
int main(){
    
    int n;
    cin>>n;
    vector<int> nums(n);
    
    for( int i = 0; i < n; i++){
        cin>>nums[i];
    }
    
    Solution S;
    
    cout<<S.minMoves(nums)<<endl;
    return 0;
}
