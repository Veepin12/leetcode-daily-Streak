#include <iostream>
using namespace std;

class Solution{
    public:

    int Longest_subarr( vector<int> & nums , int k){

        unordered_map<int, int> mp;

        int left = 0;
        int ans = 0;

        for( int i = 0; i < nums.size(); i++){

            mp[nums[i]]++;

            while(mp[nums[i]] > k)
            {
                mp[nums[left]]--;
                left++;
            }
            ans = max(ans,i - left + 1);
        }
        return ans;

    }
};
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);

    for( int i = 0;i < n; i++){
        cin>>nums[i];
    }
    int k;
    cin>>k;

    Solution S;
    cout<<S.Longest_subarr(nums , k)<<endl;

    return 0;
}