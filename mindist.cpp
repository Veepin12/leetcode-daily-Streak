#include <iostream>
using namespace std;

 int mindist(vector<int> & nums, int target , int start){
    int n=nums.size();

    int mindistace = INT_MAX;

    for(int i=0;i<n; i++){
        if(nums[i] == target ){
            mindistace = min(mindistace , abs(i- start));

        }
    }
    return mindistace;
 }
int main(){
     vector<int> nums={1,2,3,4,5};
     int start =3;
     int target= 5;

     cout<<mindist(nums,target , start)<<endl;

    return 0;

}