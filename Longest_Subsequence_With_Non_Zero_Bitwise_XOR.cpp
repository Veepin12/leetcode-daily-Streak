#include <iostream>
using namespace std;

class Solution{
public:

    int f( vector<int> & nums){

        int n = nums.size();
        int count = 0;
        int idx = 0;

        for( auto ele : nums){

            if( ele != 0){
                count++;
                idx ^= ele;
            }

        }

        if( count == 0) return 0;

        if( idx != 0) return n;
        return n - 1;
        

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

    cout<<S.f(nums)<<endl;
    return 0;
}