#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
    public:

    int min_Freq( vector<int> & nums){
        unordered_map<int, vector<int>> mp;

        for( int ele= 0; ele < nums.size(); ele++){
            mp[nums[ele]].push_back(ele);
        }
        int ans = INT_MAX;
        int val = 0;
        for( auto ele : mp){
            int temp = ele.second.size();

            ans = min( ans , temp);



            
        }
        return ans ;

        

    }


};
int main(){
    Solution S;
    vector<int> nums = { 1,1,1,2,3,3,4,4};
    cout<<S.min_Freq( nums)<<endl;
    return 0;
}