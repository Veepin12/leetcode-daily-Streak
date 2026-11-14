#include <iostream>
using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        int best = INT_MAX;
        for (int len = l; len <= r; len++) {
            for (int i = 0; i + len <= n; i++) {
                int sum = prefix[i + len] - prefix[i];
                if (sum > 0 && sum < best) best = sum;
            }
        }

        return best == INT_MAX ? -1 : best;
    }
};
int main(){

    int n ;
    cin>>n;

    

    vector<int> nums(n);

    for( int i = 0; i < n; i++){
        cin>>nums[i];
    }

    int l;
    cin>>l;
    int r;
    cin>>r;

    Solution S;

    cout<<S.minimumSumSubarray(nums , l , r)<<endl;
    return 0;
}