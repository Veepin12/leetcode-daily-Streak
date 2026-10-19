//
//  find_target_indices_after_sort.cpp
//  DSA_with_cpp
//
//  Created by Veepin kumar on 19/10/26.
//

/*
 You are given a 0-indexed integer array nums and a target element target.

 A target index is an index i such that nums[i] == target.

 Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.

  

 Example 1:

 Input: nums = [1,2,5,2,3], target = 2
 Output: [1,2]
 Explanation: After sorting, nums is [1,2,2,3,5].
 The indices where nums[i] == 2 are 1 and 2.
 Example 2:

 Input: nums = [1,2,5,2,3], target = 3
 Output: [3]
 Explanation: After sorting, nums is [1,2,2,3,5].
 The index where nums[i] == 3 is 3.
 Example 3:

 Input: nums = [1,2,5,2,3], target = 5
 Output: [4]
 Explanation: After sorting, nums is [1,2,2,3,5].
 The index where nums[i] == 5 is 4.
  

 Constraints:

 1 <= nums.length <= 100
 1 <= nums[i], target <= 100
 */

#include <iostream>
using namespace std;

class Solution{  //Complexity = O(nlogn)..
                 // Space = O(n)..
public:
    
    vector<int> f(  vector<int> & nums , int target){
        
        sort( nums.begin() , nums.end());
        
        vector<int> ans;
        for( int i = 0; i < nums.size(); i++){
            if( nums[i] == target){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    
    for( int i = 0; i < n; i++){
        cin>>nums[i];
    }
    int target;
    cin>>target;
    
    Solution S;
    vector<int> res = S.f(nums,target);
    
    for( int i = 0; i < res.size() ; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
