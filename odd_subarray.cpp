/*Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:

Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.
Example 2:

Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.
Example 3:

Input: arr = [1,2,3,4,5,6,7]
Output: 16
 

Constraints:

1 <= arr.length <= 105
1 <= arr[i] <= 100

*/

//
//  odd_subaarra.cpp
//  DSA_with_cpp
//
//  Created by Veepin kumar on 15/11/26.
//

#include <iostream>
using namespace std;

class Solution {
public:
    
    int f( vector<int> & nums){
        
        long n = nums.size();
        int  count = 0;
        
        
        for( int startidx = 0; startidx < n;  startidx++){
            
            int countidx = 0;
            
            for( int endidx = startidx; endidx < n; endidx++){
                
                countidx += nums[endidx];
                
                if( countidx % 2 != 0){
                    count++;
                }
            }
            
        }
        
        return count;
    }
    
    
    
    
    int numOfSubarrays(vector<int>& nums) {
        
        long n = nums.size();
        int MOD = 1e9  + 7;
        
        int prefixsum = 0;
        int evencount = 1;
        int oddcount = 0;
        int count = 0;
        
        for( int i = 0; i < n; i++){
            
            prefixsum += nums[i];
            
            if( prefixsum % 2 == 0){
                count += oddcount ;
                evencount++;
            }
            else{
                count += evencount;
                oddcount++;
            }
            
            
            count %= MOD;
            
        }
            
            
            
            return count;
        }
    
    
};
int main(){
    
    
    int n ;
    cin>>n;
    vector<int> nums(n);
    
    for( int i = 0; i < n; i++){
        cin>>nums[i];
    }
    
    Solution S;
    
    cout<<S.numOfSubarrays(nums)<<endl;
    return 0;
}
