#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n);
        vector<int> rightSum(n);
        
        int left = 0;
        int right = 0;


        for( int i = 0; i < n ; i++){
            left += nums[i];
            leftSum.push_back(left);
        }
        for( int i = n - 1; i >= 0 ; i--){
            right += nums[i];
            rightSum.push_back(right);
        }

        vector<int> ans( n);

        for( int i = 0; i < n; i++){
            ans[i] = abs( leftSum[i] - rightSum[i]);
        }
        return ans ;


        
    }
};

int main(){
    Solution S;
    vector<int> nums = { 3,4,2,4};
    vector<int> ans = S.leftRightDifference( nums);

    for( int i = 0; i < ans.size() ; i++) cout<<ans[i];
    return 0;
}