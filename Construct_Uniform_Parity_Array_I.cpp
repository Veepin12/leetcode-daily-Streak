#include <iostream>
using namespace std;

class Solution{
    public:

    bool uniform( vector<int> & nums){
        int n = nums.size();
        
        int even = 0 , odd = 0;

        for( auto ele : nums){
            if( ele % 2 == 0){
                even++;
            }
            else{
                odd++;
            }
        }

        if( even == 0 || odd == 0) return true;
        if( even >= 2 || odd >= 2) return true;
        if( even >= 1 && odd >= 1) return true;
        return false;
    }
};
int main(){

    int n ;
    cin>>n;
    vector<int> nums(n);

    for( int i = 0; i < n; i++){
        cin>>nums[i];
    }
    Solution S;
    cout<<S.uniform( nums)<<endl;
    return 0;
}