//
//  jumpGame.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 07/05/26.
//
/*
You are given an integer array nums.

From any index i, you can jump to another index j under the following rules:

Jump to index j where j > i is allowed only if nums[j] < nums[i].
Jump to index j where j < i is allowed only if nums[j] > nums[i].
For each index i, find the maximum value in nums that can be reached by following any sequence of valid jumps starting at i.

Return an array ans where ans[i] is the maximum value reachable starting from index i.

 

Example 1:

Input: nums = [2,1,3]

Output: [2,2,3]

Explanation:

For i = 0: No jump increases the value.
For i = 1: Jump to j = 0 as nums[j] = 2 is greater than nums[i].
For i = 2: Since nums[2] = 3 is the maximum value in nums, no jump increases the value.
Thus, ans = [2, 2, 3].

Example 2:

Input: nums = [2,3,1]

Output: [3,3,3]

Explanation:

For i = 0: Jump forward to j = 2 as nums[j] = 1 is less than nums[i] = 2, then from i = 2 jump to j = 1 as nums[j] = 3 is greater than nums[2].
For i = 1: Since nums[1] = 3 is the maximum value in nums, no jump increases the value.
For i = 2: Jump to j = 1 as nums[j] = 3 is greater than nums[2] = 1.
Thus, ans = [3, 3, 3].

 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109

*/

#include <iostream>
#include <vector>
using namespace std;





class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        // max_so_far[i] stores the maximum value in nums[0...i]
        vector<int> max_so_far(n);
        max_so_far[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            max_so_far[i] = max(max_so_far[i - 1], nums[i]);
        }

        // min_suffix[i] stores the minimum value in nums[i...n-1]
        vector<int> min_suffix(n);
        min_suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            min_suffix[i] = min(min_suffix[i + 1], nums[i]);
        }

        vector<int> ans(n);
        int start = 0;
        
        for (int i = 0; i < n; ++i) {
            // A split occurs if the max of the left part is <= the min of the right part.
            // This means no element on the left can jump to any element on the right.
            if (i == n - 1 || max_so_far[i] <= min_suffix[i + 1]) {
                
                // The maximum value for this entire isolated component is simply
                // the maximum value seen up to the end of this component.
                int partition_max = max_so_far[i];
                
                // Assign this maximum to all elements in the current component
                for (int j = start; j <= i; ++j) {
                    ans[j] = partition_max;
                }
                
                // Move the start pointer to the beginning of the next component
                start = i + 1;
            }
        }

        return ans;
    }
};

int main(){
    
    Solution S;
    vector<int> nums = {2,2,3};
    vector<int> res = S.maxValue(nums);
    
    for( auto ele : res){
        cout<<ele<<" ";
    }
    return 0;
}
