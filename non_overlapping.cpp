//
//  Number_of_Sets_of_K_Non_Overlapping_Line_Segments.cpp
//  DSA_with_cpp
//
//  Created by Veepin kumar on 16/09/26.
//

/*
 Given n points on a 1-D plane, where the ith point (from 0 to n-1) is at x = i, find the number of ways we can draw exactly k non-overlapping line segments such that each segment covers two or more points. The endpoints of each segment must have integral coordinates. The k line segments do not have to cover all n points, and they are allowed to share endpoints.

 Return the number of ways we can draw k non-overlapping line segments. Since this number can be huge, return it modulo 109 + 7.
 */
#include <iostream>
using namespace std;
class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numberOfSets(int n, int k) {
        vector<vector<long long>> dp(n, vector<long long>(k + 1));
        // 0 segments → exactly 1 way
        for(int i = 0; i < n; i++) dp[i][0] = 1;

        for(int j = 1; j <= k; j++){
            long long sum = 0;
            for(int i = 1; i < n; i++){
                // Add ways for j-1 segments
                sum = (sum + dp[i - 1][j - 1]) % MOD;
                // Don't use i OR end a segment at i
                dp[i][j] = (dp[i - 1][j] + sum) % MOD;
            }
        }

        return dp[n - 1][k];
    }
};
int main(){
    int n ,k;
    cin>>n>>k;
    Solution S;
    
    cout<<S.numberOfSets(n, k)<<endl;
    return 0;
}
