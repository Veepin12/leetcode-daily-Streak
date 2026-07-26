#include <iostream>
using namespace std;

class Solution {
    public:

    int max_num( vector<int> & nums){

        sort( nums.begin() , nums.end());
        int n = nums.size();

        int x = nums[n - 3] * nums[ n - 2] * nums[n - 1];
        int y = nums[0] * nums[ 1] * nums[ n- 1];
        return max(  x, y);
    }
};
int main(){ 
    int n;
    cin>>n;
    vector<int> nums(n);

    for ( int i = 0; i < n; i++){
        cin>>nums[i];
    }

    Solution S;

    cout<<S.max_num( nums)<<endl;
    return 0;

}