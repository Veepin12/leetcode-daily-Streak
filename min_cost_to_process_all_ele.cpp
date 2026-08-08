#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long current_resources = k;
        long long total_ops = 0;
        long long total_cost = 0;
        
        const long long MOD = 1000000007;
        const long long INV2 = 500000004; // Modular inverse of 2 mod 10^9+7
        
        auto getSum = [&](long long n) {
            long long mod_n = n % MOD;
            long long mod_n_plus_1 = (n + 1) % MOD;
            return (mod_n * mod_n_plus_1 % MOD) * INV2 % MOD;
        };
        
        for (int x : nums) {
            if (current_resources < x) {
                long long deficit = x - current_resources;
                long long ops_needed = (deficit + k - 1) / k;
                
                long long start_op = total_ops + 1;
                long long end_op = total_ops + ops_needed;
                
                // Sum from start_op to end_op = sum(end_op) - sum(start_op - 1)
                long long sum_end = getSum(end_op);
                long long sum_start = getSum(start_op - 1);
                
                long long current_cost = (sum_end - sum_start + MOD) % MOD;
                
                total_cost = (total_cost + current_cost) % MOD;
                total_ops += ops_needed;
                current_resources += ops_needed * (long long)k;
            }
            current_resources -= x;
        }
        
        return total_cost;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);

    for( int i = 0; i < n; i++){
        cin>>nums[i];
    }
    int k;
    cin>>k;

    Solution S;
    cout<<S.minimumCost( nums , k)<<endl;
    return 0;
}