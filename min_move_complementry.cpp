#include <iostream>
#include <algorithm>
using namespace std; 
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {

            int a = nums[i];
            int b = nums[n - 1 - i];

            int low = min(a, b);
            int high = max(a, b);

            int sum = a + b;

            // Initially assume 2 moves for every sum
            diff[2] += 2;

            // 1 move region starts
            diff[low + 1] -= 1;

            // 0 move at exact sum
            diff[sum] -= 1;
            diff[sum + 1] += 1;

            // back to 2 moves after range
            diff[high + limit + 1] += 1;
        }

        int ans = INT_MAX;
        int curr = 0;

        for (int s = 2; s <= 2 * limit; s++) {
            curr += diff[s];
            ans = min(ans, curr);
        }

        return ans;
    }
};
int main(){
    Solution S;
    vector<int> nums = {1,2,4,3};
    int limit ;
    cin>>limit;
    cout<<S.minMoves(nums,limit)<<endl;
    return 0;
}