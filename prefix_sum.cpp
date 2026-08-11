#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int missingInteger(vector<int>& nums) {
         int prefixSum = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
        // Sequential means each element = previous + 1
        if (nums[i] == nums[i-1] + 1) {
            prefixSum += nums[i];
        } else {
            // Prefix is no longer sequential, stop
            break;
        }
    }
    
    // Step 2: Create a set for O(1) lookup of array elements
    unordered_set<int> numSet(nums.begin(), nums.end());
    
    // Step 3: Find the smallest integer >= prefixSum that's not in the array
    int x = prefixSum;
    while (numSet.count(x)) {
        x++;
    }
    
    return x;
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

    cout<<S.missingInteger(nums)<<endl;
    return 0;
}