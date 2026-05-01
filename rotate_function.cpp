//
//  rotate_Function.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 01/05/26.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int f(vector<int>& nums, int n){
         
        if( n == 0) return 0;
        
        
       
        
        int pref = 0;
        int sum = 0;
        int ans = INT_MIN;
        
        for(int i=0; i<n; i++){
            pref += i * nums[i];
            sum += nums[i];
            
        }
        ans = pref;
        for(int i = 0 ; i < n ; i++){
            pref += sum;
            pref -= nums.size() * nums[nums.size() -1 - i];
            ans = max(ans ,pref);
        }
        
        
        return ans;
        
    }
    int maxRotateFunction(vector<int>& nums) {
        long n = nums.size();
        
        
        int ans = f(nums,(int)n);
        return ans;
        
    }
};


class Node {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long n = nums.size();
        long long sum = 0, F = 0;

        // Compute sum and F(0)
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += (long long)i * nums[i];
        }

        long long maxF = F;

        // Use recurrence: F(k) = F(k-1) + sum - n * nums[n-k]
        for (int k = 1; k < n; k++) {
            F = F + sum - (long long)n * nums[n - k];
            maxF = max(maxF, F);
        }

        return (int)maxF;
    }
};



int main(){
    Solution S;
    Node N;
    vector<int> nums ={4,3,2,6};
     
    cout<<N.maxRotateFunction(nums)<<endl;
    cout<<S.maxRotateFunction(nums)<<endl;
    
    return 0;
}
