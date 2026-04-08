#include <iostream>
using namespace std;

int Xor(vector<int> & nums,vector<vector<int>>& quary){
    long long mod=10e9 +7;
    for(auto & row : quary){
        for(int i=row[0] ; i<=row[1];i+=row[2]){
            nums[i]=(nums[i]*row[3])%(mod);
        } 
    }
    int res=0;
    for(auto ele : nums){
        res^=ele;
    }
    return res;

}
int main(){
    vector<int> nums={2,3,1,5,4};
    vector<vector<int>> quary={{1,4,2,3},{0,2,1,2}};
    cout<<Xor(nums,quary);
    return 0;
}