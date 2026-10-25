//
//  Number_of_island.cpp
//  DSA_with_cpp
//
//  Created by Veepin kumar on 25/10/26.
//

/*
 Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

 Return the number of closed islands.

  

 Example 1:



 Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
 Output: 2
 Explanation:
 Islands in gray are closed because they are completely surrounded by water (group of 1s).
 Example 2:



 Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
 Output: 1
 Example 3:

 Input: grid = [[1,1,1,1,1,1,1],
                [1,0,0,0,0,0,1],
                [1,0,1,1,1,0,1],
                [1,0,1,0,1,0,1],
                [1,0,1,1,1,0,1],
                [1,0,0,0,0,0,1],
                [1,1,1,1,1,1,1]]
 Output: 2
               

 Constraints:

 1 <= grid.length, grid[0].length <= 100
 0 <= grid[i][j] <=1
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;



#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    
    
    void bfs(int startX, int startY, vector<vector<int>>& grid, int n, int m) {
        queue<pair<int, int>> q;
        q.push({startX, startY});
        grid[startX][startY] = 1; // Mark as visited by converting 0 to 1

        int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while (!q.empty()) {
            auto ele = q.front();
            q.pop();
            
            int x = ele.first;
            int y = ele.second;

            for (int d = 0; d < 4; d++) {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];

                // Stay within bounds and only traverse land (0)
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0) {
                    grid[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        long n = grid.size();
        long m = grid[0].size();

        // Step 1: Flood fill from all border cells to eliminate non-closed land
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0) bfs(i, 0, grid, n, m);
            if (grid[i][m - 1] == 0) bfs(i, m - 1, grid, n, m);
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 0) bfs(0, j, grid, n, m);
            if (grid[n - 1][j] == 0) bfs(n - 1, j, grid, n, m);
        }

        // Step 2: Any remaining 0 belongs to a strictly closed island
        int closedCount = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0) {
                    closedCount++;
                    bfs(i, j, grid, n, m);
                }
            }
        }

        return closedCount;
    }
};

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    cout << sol.closedIsland(grid) << "\n";

    return 0;
}
