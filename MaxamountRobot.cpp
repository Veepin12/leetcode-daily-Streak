#include <iostream>
using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        // dp[i][j][k] = max coins at (i,j) using k neutralizations
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        
        // Base case: starting cell (0,0)
        dp[0][0][0] = coins[0][0];
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0; // neutralize the starting cell
        }
        
        // Fill first row
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < 3; k++) {
                if (dp[0][j-1][k] == INT_MIN) continue;
                
                // Don't neutralize
                dp[0][j][k] = max(dp[0][j][k], dp[0][j-1][k] + coins[0][j]);
                
                // Neutralize (only if negative and k < 2)
                if (coins[0][j] < 0 && k < 2) {
                    dp[0][j][k+1] = max(dp[0][j][k+1], dp[0][j-1][k]);
                }
            }
        }
        
        // Fill first column
        for (int i = 1; i < m; i++) {
            for (int k = 0; k < 3; k++) {
                if (dp[i-1][0][k] == INT_MIN) continue;
                
                // Don't neutralize
                dp[i][0][k] = max(dp[i][0][k], dp[i-1][0][k] + coins[i][0]);
                
                // Neutralize (only if negative and k < 2)
                if (coins[i][0] < 0 && k < 2) {
                    dp[i][0][k+1] = max(dp[i][0][k+1], dp[i-1][0][k]);
                }
            }
        }
        
        // Fill rest of the grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    // Best previous state (from top or left)
                    int prev = INT_MIN;
                    if (dp[i-1][j][k] != INT_MIN) prev = max(prev, dp[i-1][j][k]);
                    if (dp[i][j-1][k] != INT_MIN) prev = max(prev, dp[i][j-1][k]);
                    
                    if (prev == INT_MIN) continue;
                    
                    // Don't neutralize
                    dp[i][j][k] = max(dp[i][j][k], prev + coins[i][j]);
                    
                    // Neutralize (only if negative and k < 2)
                    if (coins[i][j] < 0 && k < 2) {
                        // Find best prev for k-1 neutralizations used
                        int prev2 = INT_MIN;
                        if (dp[i-1][j][k] != INT_MIN) prev2 = max(prev2, dp[i-1][j][k]);
                        if (dp[i][j-1][k] != INT_MIN) prev2 = max(prev2, dp[i][j-1][k]);
                        
                        if (prev2 != INT_MIN) {
                            dp[i][j][k+1] = max(dp[i][j][k+1], prev2);
                        }
                    }
                }
            }
        }
        
        // Answer is max over all neutralization counts at bottom-right
        int ans = INT_MIN;
        for (int k = 0; k < 3; k++) {
            if (dp[m-1][n-1][k] != INT_MIN)
                ans = max(ans, dp[m-1][n-1][k]);
        }
        
        return ans;
    }
};

// Driver code
int main() {
    Solution sol;
    
    // Example 1
    vector<vector<int>> coins1 = {{0,1,-1},{1,-2,3},{2,-3,4}};
    cout << "Example 1 Output: " << sol.maximumAmount(coins1) << endl; // Expected: 8
    
    // Example 2
    vector<vector<int>> coins2 = {{10,10,10},{10,10,10}};
    cout << "Example 2 Output: " << sol.maximumAmount(coins2) << endl; // Expected: 40
    
    return 0;
}
    /*
```

### Quick Walkthrough

| Part | Detail |
|---|---|
| **State** | `dp[i][j][k]` → max coins at `(i,j)` with `k` neutralizations used |
| **Transition** | For each cell, try coming from **top** or **left**, then either add `coins[i][j]` or neutralize it (if negative & `k < 2`) |
| **Answer** | `max(dp[m-1][n-1][0..2])` |
| **Time** | `O(m × n × 3)` |
| **Space** | `O(m × n × 3)` |

### Output
```
Example 1 Output: 8
Example 2 Output: 40
*/