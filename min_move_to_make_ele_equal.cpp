#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int minMoves( vector<int> &nums){
        int n = nums.size();
        int sz = nums[0];
        for( int i = 0; i < n; i++){
            sz = max( sz , nums[i]);

        }
        int ans = 0;
        for( int  ele : nums){
            ans += sz - ele;
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

    cout<<S.minMoves(nums)<<endl;
    return 0;
}