//
//  max_alternating_sum.cpp
//  DSA_with_cpp
//
//  Created by Veepin kumar on 13/10/26.
//

/*
 You are given an integer array nums. You may rearrange the elements in any order.

 The alternating score of an array arr is defined as:

 score = arr[0]2 - arr[1]2 + arr[2]2 - arr[3]2 + ...
 Return an integer denoting the maximum possible alternating score of nums after rearranging its elements.

  

 Example 1:

 Input: nums = [1,2,3]

 Output: 12

 Explanation:

 A possible rearrangement for nums is [2,1,3], which gives the maximum alternating score among all possible rearrangements.

 The alternating score is calculated as:

 score = 22 - 12 + 32 = 4 - 1 + 9 = 12

 Example 2:

 Input: nums = [1,-1,2,-2,3,-3]

 Output: 16

 Explanation:

 A possible rearrangement for nums is [-3,-1,-2,1,3,2], which gives the maximum alternating score among all possible rearrangements.

 The alternating score is calculated as:

 score = (-3)2 - (-1)2 + (-2)2 - (1)2 + (3)2 - (2)2 = 9 - 1 + 4 - 1 + 9 - 4 = 16

  

 Constraints:

 1 <= nums.length <= 105
 -4 * 104 <= nums[i] <= 4 * 104
 
 
 
 */


#include <iostream>
using namespace std;

class Solution {
public:
    
    long long max_square( vector<int> & nums){
        
        long n = nums.size();
        
        long long ans = 0;
        vector<int> v(n);
        
        for( int  i = 0; i < n; i++)
            v[i] += 1LL * nums[i] * nums[i];
        
        sort(v.begin() , v.end());
        
        for( int i = 0; i < n/ 2; i++){
            ans -= v[i];
        }
        
        for( int i = n / 2; i < n; i++){
            ans += v[i];
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
    Solution S;
    
    cout<<S.max_square(nums)<<endl;
    return 0;
}
