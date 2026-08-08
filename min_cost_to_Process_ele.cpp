//
//  min_cost_to_process_ele.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 08/08/26.
//

/*
 You are given an integer array nums and an integer k.

 Initially, you have k units of resources.

 You must process the elements of nums from left to right. To process the ith element, you need nums[i] resources.

 If your available resources are less than nums[i], you may perform an operation that increases your available resources by k. The value of k is fixed and does not change throughout the process. The first such operation incurs a cost of 1, the second incurs a cost of 2, and so on.

 After processing the ith element, your available resources decrease by nums[i].

 Return an integer denoting the minimum total cost required to process all elements. Since the answer may be very large, return it modulo 109 + 7.
 
 
 Input: nums = [1,2,3,4], k = 4

 Output: 3

 Explanation:

 After processing nums[0], we have 4 - 1 = 3 units of resources left.
 After processing nums[1], we have 3 - 2 = 1 unit of resources left.
 Since nums[2] = 3 and only 1 unit of resources is available, we perform the first operation costing 1. After processing nums[2], we have 1 + 4 - 3 = 2 units of resources left.
 Since nums[3] = 4 and only 2 units of resources are available, we perform the second operation costing 2, to have 2 + 4 = 6 units of resources, which is enough to process nums[3].
 Thus, the total cost is 1 + 2 = 3.
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long MOD = 1e9 + 7;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k) {
        
        
        // Min-heap to store operation costs
        priority_queue<int, vector<int>, greater<int>> min_heap;
        long long resources = k;        // Start with k resources
        long long total_cost = 0;       // Track total cost
        int operation_count = 0;        // Track which operation we're on
        
        for (int num : nums) {
            resources -= num;           // Consume resources for this element
            
          
            // NEW - OPTIMIZED
            if (resources < 0) {
                long long deficit = -resources;
                long long num_operations = (deficit + k - 1) / k;
                
                // Cost formula
                long long sum_arithmetic = (num_operations * (num_operations + 1) / 2) % MOD;
                long long sum_offset = (num_operations % MOD * (operation_count % MOD)) % MOD;
                
                total_cost = (total_cost + sum_offset + sum_arithmetic) % MOD;
                
                // Update state
                resources += num_operations * k;
                operation_count += num_operations;
            }
        }
        return total_cost;
    }
};

int main() {
    
    
    int n;
    cin>>n;
    
    vector<int> nums(n);
    
    for( int i = 0; i < n; i++)
        cin>>nums[i];
    
    
    int k;
    cin>>k;
    
    Solution S;
    
    cout<<S.minimumCost(nums , k)<<endl;
    return 0;
}
