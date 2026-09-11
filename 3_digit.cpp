#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
    

    int count_digit( vector<int> & nums){

        
        int f[10] = {};
        int res = 0;

        for( auto & d : nums){
            f[d]++;
        }

        for (int i = 1; i < 10; i++) 
            for (int j = 0; j < 10; j++) 
                for (int k = 0; k < 9; k += 2) 
                    res += f[i] > 0 &&
                           f[j] > (i == j) &&
                           f[k] > (i == k) + (j == k);
        

        return res;
    }
};

int main(){

    int n;
    cin>>n;

    vector<int> nums(n);
    for( int i = 0; i < n; i++){
        cin>>nums[i];
    }

    Solution S;
    cout<<S.count_digit(nums);
    return 0;
}