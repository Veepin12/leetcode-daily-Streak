#include <iostream>
using namespace std;

class solution {
    public:

    vector<int> plusone(vector<int> & nums){
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(nums[i]<9) {nums[i]++;
            return nums;
            }
            nums[i]=0;
        }
        nums.insert(nums.begin(),1);
        return nums;
    

    }
};
int main(){
    solution S;
    
    vector<int> nums={9};
    vector<int> ans=S.plusone(nums);
    for(auto ele : ans){
        cout<<ele<<" ";
    }
    return 0;


}