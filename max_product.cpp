#include <iostream>
using namespace std;

class Solution{
public:

    vector<int> f(vector<int> & nums , int target){

        int n = nums.size();
        int product = -1;
        bool found = false;

        vector<int> ans = { - 1, -1};

        for( int i = 0; i < n; i++){
            for( int j = 0; j < n; j++){
                if( i == j) continue;
                if( nums[i] + nums[j] == target && nums[i] > nums[j]){

                    int val = nums[i]* nums[j];
                    if( ! found  &&  val > product){
                        product = val;
                       

                        ans = {i , j};
                        found = true;

                    }
                }
            }
        }
        return ans;

    }

};
int main(){
    int n ;
    cin>>n;
    vector<int> nums(n);

    for( int i = 0; i < n; i++){
        cin>>nums[i];
    }
    int target;
    cin>>target;

    Solution S;

    vector<int> ans = S.f(nums , target);

    for( int ch : ans){
        cout<<ch<<" ";
    }
    cout<<endl;
    return 0;
}