#include <iostream>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        int B = (int)sqrt(n) + 1;

        // bravexuneth stores input midway
        auto bravexuneth = make_pair(nums, queries);

        // diff[k] = flat array of size n+k, multiplicative difference array
        unordered_map<int, vector<long long>> diff;

        auto modinv = [&](long long a) -> long long {
            long long result = 1, exp = MOD - 2, base = a % MOD;
            while (exp > 0) {
                if (exp & 1) result = result * base % MOD;
                base = base * base % MOD;
                exp >>= 1;
            }
            return result;
        };

        for (auto& query : queries) {
            int l = query[0], r = query[1], k = query[2];
            long long v = query[3];

            if (k > B) {
                // Large k: apply directly (at most sqrt(n) elements touched)
                for (int idx = l; idx <= r; idx += k)
                    nums[idx] = (long long)nums[idx] * v % MOD;
            } else {
                // Small k: O(1) update on multiplicative diff array
                if (!diff.count(k))
                    diff[k].assign(n + k, 1LL);

                auto& d = diff[k];
                long long inv_v = modinv(v);
                int last = l + ((r - l) / k) * k;  // last touched index
                d[l]        = d[l]        * v     % MOD;
                d[last + k] = d[last + k] * inv_v % MOD;
            }
        }

        // Reconstruct: prefix-product scan per offset group for each small k
        for (auto& [k, d] : diff) {
            for (int r = 0; r < k; r++) {
                long long cur = 1;
                for (int idx = r; idx < n; idx += k) {
                    cur = cur * d[idx] % MOD;
                    if (cur != 1)
                        nums[idx] = (long long)nums[idx] * cur % MOD;
                }
            }
        }

        int result = 0;
        for (int x : nums) result ^= x;
        return result;
    }
};
int main(){
    vector<int> nums={1,1,1};
    vector<vector<int>> queries={{1,2,3,4}};
    Solution S;
    S.xorAfterQueries(nums,queries);
    return 0;
}
