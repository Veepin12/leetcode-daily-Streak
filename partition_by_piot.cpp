#include <iostream>
using namespace std;

class Solution {
public:

    vector<int> partition( vector<int> & nums , int pivot){
        int n = nums.size();
        vector<int> ans ;

        for( int i = 0; i < n; i++){
            if(nums[i] < pivot)
            ans.push_back(nums[i]);
        }
        for( int i = 0; i < n; i++){
            if(nums[i] == pivot)
            ans.push_back(nums[i]);
        }
        for( int i = 0; i < n; i++){
            if(nums[i] > pivot)
            ans.push_back(nums[i]);
        }
        
        return ans;
    }
};
int main(){
    int n; 
    cin>>n;
    vector<int> nums(n);

    for( int i = 0; i < n; i++ ) cin>>nums[i];

    int pivot;
    cin>>pivot;
    Solution S;
    vector<int> res = S.partition( nums , pivot);
    for( int i = 0; i < res.size() ; i++) cout<<res[i];
    return 0;
}