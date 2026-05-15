#include <iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right =  n - 1;
        while( left < right){
            int mid = left + ( right - left)/2;
        
        if( nums[ mid] > nums[ right]){
            left = mid + 1;
        }
        else{
            right = mid;
        }
        }
    return nums[left];
    }
};

int main(){
    Solution S;
    vector<int> nums = {4,5,8,0 ,3,9,7};

    cout<<S.findMin(nums)<<endl;
    return 0;
}