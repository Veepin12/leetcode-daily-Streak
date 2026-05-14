#include <iostream>
using namespace std;
class Solution {
public:

    int maximum(vector<int> & nums){
        int n = nums.size();
        int max_val = INT_MIN;
        for( int i = 0; i < n; i++){
            max_val = max(max_val, nums[i]);
        }
        return max_val;
    }
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if( n == 1) return false;
        if( n == 2 ) {
            if( nums[0] == nums[1] && nums[1] == 1) return true;
            else return false;
        }
        else{
            sort(nums.begin(),nums.begin() + n - 2);
            if( nums[n- 2]/* max */ == maximum(nums) ) return true;
        }
        return false;
        

        /*int val = INT_MIN;
        for( int i = 0; i < n; i++){
            if( val >= nums[i]){
                val = max(val,nums[i]);
            }
        }
       */
    
    // Hashing Method ..
     int n = *max_element(nums.begin(), nums.end());
        
        // base[n] has n+1 elements
        if (nums.size() != n + 1) return false;
        
        vector<int> freq(n + 1, 0);
        for (int x : nums) {
            if (x > n) return false;
            freq[x]++;
        }
        
        // 1 to n-1 appear exactly once, n appears twice
        for (int i = 1; i < n; i++)
            if (freq[i] != 1) return false;
        
        return freq[n] == 2;
    
    }
};

int main(){
    Solution S;
    vector<int> nums = {1,2};
    cout<<S.isGood(nums)<<endl;
    return 0;
}