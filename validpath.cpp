#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // For each street type, which directions does it open?
        // Directions: 0=LEFT, 1=RIGHT, 2=UP, 3=DOWN
        // opens[type] = set of open directions
        vector<vector<int>> opens = {
            {},          // unused (0-indexed, type 0 doesn't exist)
            {0, 1},      // type 1: LEFT, RIGHT
            {2, 3},      // type 2: UP, DOWN
            {0, 3},      // type 3: LEFT, DOWN
            {1, 3},      // type 4: RIGHT, DOWN
            {0, 2},      // type 5: LEFT, UP
            {1, 2},      // type 6: RIGHT, UP
        };

        // Direction vectors: LEFT, RIGHT, UP, DOWN
        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 1};  // fix: LEFT=-1, RIGHT=+1, UP=-1, DOWN=+1
        // Opposite direction index: LEFT<->RIGHT, UP<->DOWN
        int opp[] = {1, 0, 3, 2};

        // Redefine clearly
        // dir 0 = LEFT  -> dc=-1, dr=0  | opposite = RIGHT (1)
        // dir 1 = RIGHT -> dc=+1, dr=0  | opposite = LEFT  (0)
        // dir 2 = UP    -> dr=-1, dc=0  | opposite = DOWN  (3)
        // dir 3 = DOWN  -> dr=+1, dc=0  | opposite = UP    (2)
        int DX[] = {0, 0, -1, 1};
        int DY[] = {-1, 1, 0, 0};

        auto canMove = [&](int r, int c, int dir) -> bool {
            // Does cell (r,c) open in direction `dir`?
            for (int d : opens[grid[r][c]])
                if (d == dir) return true;
            return false;
        };

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();

            if (r == m-1 && c == n-1) return true;

            for (int dir = 0; dir < 4; dir++) {
                int nr = r + DX[dir];
                int nc = c + DY[dir];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (visited[nr][nc]) continue;

                // Current cell must open toward `dir`
                // Neighbor cell must open toward opposite of `dir`
                if (canMove(r, c, dir) && canMove(nr, nc, opp[dir])) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }
};
int main(){
    vector<vector<int>> grid = {{2,4,3},{6,5,2}};
    Solution S;
    cout<<S.hasValidPath(grid);
    return 0;

}