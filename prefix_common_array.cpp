#include <iostream>
using namespace std;

class Solution {
public:
         
    vector<int> common_prefix(vector<int> & nums1 , vector<int> &nums2){
        int  n = nums2.size();

        vector<int> freq( n+ 1, 0);
        vector<int> C(n);


        int count = 0;
        for( int i = 0 ; i < n; i++){

            freq[nums1[i]]++;
            if( freq[nums1[i]] == 2) count++;

            freq[nums2[i]]++;

            if( freq[nums2[i]] == 2) count++;


            C[i] = count;


        }

        return C;
    }
};
int main(){

    vector<int> nums1 = {1,3,2,4};
    vector<int> nums2 = {3,1,2,4};

    Solution S;
    vector<int> ans = S.common_prefix(nums1, nums2);

    for( auto ele : ans){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}