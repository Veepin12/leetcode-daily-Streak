#include <iostream>
using namespace std;

class Solution {
    
public:

    int min_search(vector<int> & nums){

        int start = 0;
        int end = nums.size() - 1;

        while( nums[start] >= nums[end]){
            int mid  = start + (end - start) / 2;

            if( nums[start] == nums[mid] && nums[mid] == nums[end]){
               return *min_element(nums.begin() + start, nums.begin() + end);

            }
            if( nums[start] <= nums[mid]){
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }
        return nums[start];
    }
};
int main(){
    vector<int> nums = {17,4,5,0,5,4,9,0};
    Solution S;

    cout<<S.min_search(nums)<<endl;
    return 0;

}
