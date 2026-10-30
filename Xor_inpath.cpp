//
//  Xor_in_path2.cpp
//  DSA_with_cpp
//
//  Created by Veepin kumar on 28/10/26.
//

/*
 You are given a 2D integer array grid of size m * n.

 You start at the top-left cell (0, 0) and want to reach the bottom-right cell (m - 1, n - 1).

 At each step, you may move either right or down.

 The cost of a path is defined as the bitwise XOR of all the values in the cells along that path, including the start and end cells.

 Return the minimum possible XOR value among all valid paths from (0, 0) to (m - 1, n - 1).

  

 Example 1:

 Input: grid = [[1,2],[3,4]]

 Output: 6

 Explanation:

 There are two valid paths:

 (0, 0) → (0, 1) → (1, 1) with XOR: 1 XOR 2 XOR 4 = 7
 (0, 0) → (1, 0) → (1, 1) with XOR: 1 XOR 3 XOR 4 = 6
 The minimum XOR value among all valid paths is 6.

 Example 2:

 Input: grid = [[6,7],[5,8]]

 Output: 9

 Explanation:

 There are two valid paths:

 (0, 0) → (0, 1) → (1, 1) with XOR: 6 XOR 7 XOR 8 = 9
 (0, 0) → (1, 0) → (1, 1) with XOR: 6 XOR 5 XOR 8 = 11
 The minimum XOR value among all valid paths is 9.

 Example 3:

 Input: grid = [[2,7,5]]

 Output: 0

 Explanation:

 There is only one valid path:

 (0, 0) → (0, 1) → (0, 2) with XOR: 2 XOR 7 XOR 5 = 0
 The XOR value of this path is 0, which is the minimum possible.

  

 Constraints:

 1 <= m == grid.length <= 1000
 1 <= n == grid[i].length <= 1000
 m * n <= 1000
 0 <= grid[i][j] <= 1023
  

 */
;
#include <iostream>
using namespace std;

class Solution{
public:
    
    int f( vector<vector<int>>  & grid){
        
        long m = grid.size();
        long n = grid[0].size();
                
        // Since grid[i][j] <= 1023, the maximum reachable XOR value is 1023 (< 1024).
        const int MAX_XOR = 1024;
                
        // vis[x][y][xor_val] tracks if (x, y) with cumulative xor_val has been visited
        vector<vector<vector<bool>>>  vis(m,vector<vector<bool>>(n,vector<bool>(MAX_XOR, false)));
                
        // queue stores: {row, col, current_xor_sum}
        queue<tuple<int, int, int>> qu;
                
        int start_val = grid[0][0];
        qu.push({0, 0, start_val});
        vis[0][0][start_val] = true;
                
        int dir[2][2] = {{0, 1}, {1, 0}}; // Right and Down
        int min_ans = MAX_XOR;
                
        while (!qu.empty()) {
            auto [x, y, curr_xor] = qu.front();
            qu.pop();
                    
                    // If the bottom-right cell is reached, update the minimum answer
            if (x == m - 1 && y == n - 1) {
                min_ans = min(min_ans, curr_xor);
                continue;
            }
                    
            for (int d = 0; d < 2; d++) {
                int dx = x + dir[d][0];
                int dy = y + dir[d][1];
                        
                        // Boundary check
                if (dx < 0 || dy < 0 || dx >= m || dy >= n) {
                    continue;
                }
                        
                        
                int next_xor = curr_xor ^ grid[dx][dy];
                        
                        // Avoid redundant states
                if (!vis[dx][dy][next_xor]) {
                    vis[dx][dy][next_xor] = true;
                    qu.push({dx, dy, next_xor});
                    }
                }
            }
            return min_ans;
        }
};
int main(){
    
    int n , m;
    cin>>n>>m;
    
    vector<vector<int>> grid(n , vector<int> ( m));
    
    for( int i = 0; i < n; i++){
        for( int j = 0; j < m; j++){
            cin>>grid[i][j];
        }
    }
    
    
    Solution S;
    cout<<S.f(grid)<<endl;
    return 0;
}
