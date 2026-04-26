#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
int rows, cols;
vector<vector<bool>> visited;
vector<int> dr = {0, 0, 1, -1};
vector<int> dc = {1, -1, 0, 0};

bool dfs(vector<vector<char>>& grid, int r, int c, int pr, int pc, char ch) {
    visited[r][c] = true;

    for (int d = 0; d < 4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];

        // Out of bounds or different character
        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
        if (grid[nr][nc] != ch) continue;

        // Skip the parent cell (where we came from)
        if (nr == pr && nc == pc) continue;

        // Already visited → cycle found
        if (visited[nr][nc]) return true;

        if (dfs(grid, nr, nc, r, c, ch)) return true;
    }
    return false;
}


bool containsCycle(vector<vector<char>> grid) {
    rows = grid.size();
    cols = grid[0].size();
    visited.assign(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (!visited[i][j])
                if (dfs(grid, i, j, -1, -1, grid[i][j]))
                    return true;

    return false;
}
};

int main(){
    Solution S;
    vector<vector<char>>grid={{'a','a','a','a'},{'a','a','a','a'}};
    cout<<S.containsCycle(grid);
    return 0;

}