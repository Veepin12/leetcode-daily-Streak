#include <iostream>
using namespace std;

class Solution {
    public:

    bool rotate( vector<int> & nums){

       int n = nums.size();
       int k = 0;
        
      

       for( int i = 0 ; i < n; i++){
        if( nums[i] > nums[( i + 1) % n]){
            k++;
        }
        
           

       }
       return k <= 1;
        
    }
};
int main(){
    Solution S;
    int n ;
    cin>>n;

    vector<int> nums(n);

    for( int i = 0; i < n; i++) cin>>nums[i];

    cout<<S.rotate(nums)<<endl;
    return 0;
}