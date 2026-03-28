#include <iostream>
using namespace std;

class solution {
    public:

    int valididz(vector<int> & nums){
        int n=nums.size();
        int ans=INT_MAX;
        int left=-1; int left2=-1;

        for(int i=0;i<n;i++){
            if(nums[i]==1){
                left=i;
                if(left2!= -1){
                    ans=min(ans,abs(left - left2));

                }

            }
            else{
                if(nums[i]==2){
                    left2=i;
                    if(left!= -1){
                        ans=min(ans,abs(left - left2));
                    }

                }
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }

};
int main(){
    vector<int> nums={2,0,1,0,1};
    solution S;
    cout<<S.valididz(nums)<<endl;

    return 0;
}