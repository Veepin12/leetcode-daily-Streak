//
//  maximum_consitance_col_in_grid.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 08/08/26.
//

/*
 You are given a 2D integer array grid of size m x n, and an integer limit.

 You may remove zero or more columns from the grid, but at least one column must remain. The relative order of the remaining columns must be preserved.

 A grid is called consistent if for every row i, and for every pair of adjacent remaining columns a and b with a < b, the following holds: |grid[i][b] - grid[i][a]| <= limit.

 Return the maximum number of columns that can remain such that the resulting grid is consistent.

  

 Example 1:

 Input: grid = [[-2,0,3]], limit = 2

 Output: 2

 Explanation:

 Remove column 2 and keep columns 0 and 1, which gives |grid[0][1] − grid[0][0]| = |0 − (−2)| = 2 <= limit.
 Thus, the maximum number of columns that can remain is 2.
 Example 2:

 Input: grid = [[1,-1,1],[2,2,2]], limit = 1

 Output: 2

 Explanation:

 Remove column 1 and keep columns 0 and 2, which gives
 |grid[0][2] − grid[0][0]| = |1 − 1| = 0 <= limit and
 |grid[1][2] − grid[1][0]| = |2 − 2| = 0 <= limit.
 Thus, the maximum number of columns that can remain is 2.
 Example 3:

 Input: grid = [[-5,5]], limit = 9

 Output: 1

 Explanation:

 Remove either column 0 or column 1, since |grid[0][1] − grid[0][0]| = |5 − (−5)| = 10 > limit.
 Thus, the maximum number of columns that can remain is 1.
  

 Constraints:

 1 <= m == grid.length <= 250
 1 <= n == grid[i].length <= 250
 -105 <= grid[i][j] <= 105
 0 <= limit <= 105
  


 Seen this question in a real interview before?
 1/6
 Yes
 No
 Accepted
 11,111/16.2K
 Acceptance Rate
 68.7%

 Topics
 icon
 Companies

 Hint 1


 Hint 2


 Hint 3


 Hint 4


 Hint 5


 Discussion (36)

 Choose a type
 Copyright © 2026 LeetCode. All rights reserved.


 43




 36




 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxColumns(vector<vector<int>>& grid, int limit) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[j] stores the max consistent columns ending at column j
        vector<int> dp(n, 1);
        int max_cols = 1;
        
        // Iterate through all possible ending columns j
        for (int j = 1; j < n; ++j) {
            // Check all previous columns i to see if they can precede j
            for (int i = 0; i < j; ++i) {
                bool valid = true;
                
                // Check the condition for all rows
                for (int r = 0; r < m; ++r) {
                    if (abs(grid[r][j] - grid[r][i]) > limit) {
                        valid = false;
                        break; // No need to check other rows if one fails
                    }
                }
                
                // If column i and column j can be adjacent, update dp[j]
                if (valid) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            // Keep track of the global maximum
            max_cols = max(max_cols, dp[j]);
        }
        
        return max_cols;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>>grid( n , vector<int> ( m));
    
    for( int i = 0; i < n; i++){
        for( int j = 0; j < m; j++){
            cin>>nums[i][j];
        }
    }
    int limit;
    cin>>limit;
    
    
    Solution S;
    
    cout<<S.maxColumns(nums, limit)<<endl;
    return 0;
    
}
