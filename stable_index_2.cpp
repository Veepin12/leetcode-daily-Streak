#include <iostream>
using namespace std;

int stable_idx( vector<int> nums , int k){

    int n = nums.size();
    int mn = INT_MAX;

    vector<int> suff(n);

    for( int i = n - 1; i >= 0; i--){
        mn = min( mn , nums[i]);

        suff[i] = mn;
    }

    int mx = 0;
    int ans ;
    for( int i = 0; i < n; i++){
        mx = max( mx , nums[i]);

        int score = mx - suff[i];

        if( score <= k) return i;


    }
    return -1;
}
int main(){

    int n;
    cin>>n;

    vector<int> nums(n);

    for( int i = 0; i < n; i++){
        cin>>nums[i];
    }

    int k;
    cin>>k;

    cout<<stable_idx(nums , k)<<endl;
    return 0;
}