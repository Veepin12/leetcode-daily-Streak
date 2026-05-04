#include <iostream>
using namespace std;

class Solution {
public:
      
      void rotate(vector<vector<int>>  &nums){
        int  n = nums.size();

        for ( int i = 0; i < n; i++){
            for( int  j = i+1 ; j < n ; j++){
                swap(nums[i][j] , nums[j][i]);

            }
        }

        for( int i =0; i< n ;i++){
            reverse(nums[i].begin(),nums[i].end());
        }
        
      }
   

};
int main(){

    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};

    Solution S;
     S.rotate(nums);

    for( auto ele : nums){
        for(auto el : ele){
            cout<<el<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;

}