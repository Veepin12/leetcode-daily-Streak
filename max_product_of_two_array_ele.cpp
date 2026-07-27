#include <iostream>
using namespace std;

class Solution {
    public:

    int max_product( vector<int> & nums){


        sort( nums.begin() , nums.end());

        return (nums[nums.size() - 1] -1) * (nums[nums.size() - 2] - 1 );

    }
};
int main(){
    int n;
    cin>>n;

    vector<int> nums(n);

    for( int i = 0 ; i < n; i++){
        cin>>nums[i];
    }

    Solution S;
    cout<<S.max_product( nums)<<endl;
    return 0;
}