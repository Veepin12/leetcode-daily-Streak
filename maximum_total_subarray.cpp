#include <iostream>
using namespace std;
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int diff1 = INT_MAX;
        int diff2 = INT_MIN; 
        long long ans = INT_MIN;
       
        
        for( int i = 0; i < n; i++) diff1 = min( diff1 , nums[i]);
                
        for( int i = 0; i < n; i++) diff2 = max( diff2 , nums[i]);

        ans = max((int) ans , diff2 - diff1);
        return ans * k;


        
    }
};
int main(){
    Solution S;
    int n ;
    cin>>n;
    vector<int> nums(n);

    for( int i = 0; i < n ; i++) cin>>nums[i];
    int k ;
    cin>>k;
    cout<<S.maxTotalValue( nums , k)<<endl;
    return 0;
}