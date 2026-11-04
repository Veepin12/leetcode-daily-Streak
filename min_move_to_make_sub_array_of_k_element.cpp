/*
You are given an integer array nums and two integers, x and k. You can perform the following operation any number of times (including zero):

Increase or decrease any element of nums by 1.
Return the minimum number of operations needed to have at least k non-overlapping subarrays of size exactly x in nums, where all elements within each subarray are equal.

 

Example 1:

Input: nums = [5,-2,1,3,7,3,6,4,-1], x = 3, k = 2

Output: 8

Explanation:

Use 3 operations to add 3 to nums[1] and use 2 operations to subtract 2 from nums[3]. The resulting array is [5, 1, 1, 1, 7, 3, 6, 4, -1].
Use 1 operation to add 1 to nums[5] and use 2 operations to subtract 2 from nums[6]. The resulting array is [5, 1, 1, 1, 7, 4, 4, 4, -1].
Now, all elements within each subarray [1, 1, 1] (from indices 1 to 3) and [4, 4, 4] (from indices 5 to 7) are equal. Since 8 total operations were used, 8 is the output.
Example 2:

Input: nums = [9,-2,-2,-2,1,5], x = 2, k = 2

Output: 3

Explanation:

Use 3 operations to subtract 3 from nums[4]. The resulting array is [9, -2, -2, -2, -2, 5].
Now, all elements within each subarray [-2, -2] (from indices 1 to 2) and [-2, -2] (from indices 3 to 4) are equal. Since 3 operations were used, 3 is the output.
 

Constraints:

2 <= nums.length <= 105
-106 <= nums[i] <= 106
2 <= x <= nums.length
1 <= k <= 15
2 <= k * x <= nums.length*/

#include <iostream>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<int> vals(nums);
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int m = vals.size();
        vector<int> rk(n);
        for (int i = 0; i < n; i++) {
            rk[i] = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin() + 1;
        }
        vector<int> cnt(m + 1, 0);
        vector<long long> sm(m + 1, 0);
        int top = 1;
        while (top * 2 <= m) top *= 2;
        int need = (x + 1) / 2;
        int w = n - x + 1;
        vector<long long> cost(w);
        long long total = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
            for (int p = rk[i]; p <= m; p += p & -p) {
                cnt[p] += 1;
                sm[p] += nums[i];
            }
            if (i >= x) {
                total -= nums[i - x];
                for (int p = rk[i - x]; p <= m; p += p & -p) {
                    cnt[p] -= 1;
                    sm[p] -= nums[i - x];
                }
            }
            if (i >= x - 1) {
                int pos = 0, rem = need;
                long long s0 = 0;
                for (int pw = top; pw > 0; pw >>= 1) {
                    int nxt = pos + pw;
                    if (nxt <= m && cnt[nxt] < rem) {
                        pos = nxt;
                        rem -= cnt[nxt];
                        s0 += sm[nxt];
                    }
                }
                long long med = vals[pos];
                long long c0 = need - rem;
                cost[i - x + 1] = med * c0 - s0 + (total - s0) - med * (x - c0);
            }
        }
        const long long INF = 1000000000000000000LL;
        vector<long long> prev(n + 1, 0), cur(n + 1, 0);
        for (int j = 0; j < k; j++) {
            for (int i = 0; i < x; i++) cur[i] = INF;
            for (int i = x; i <= n; i++) {
                cur[i] = min(cur[i - 1], prev[i - x] + cost[i - x]);
            }
            swap(prev, cur);
        }
        return prev[n];
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);

    for( int i = 0; i < n; i++){
        cin>>nums[i];
    }
    int x;
    cin>>x;
    int k;
    cin>>k;

    Solution S;
    cout<<S.minOperations(nums , x , k)<<endl;

    return 0;

}