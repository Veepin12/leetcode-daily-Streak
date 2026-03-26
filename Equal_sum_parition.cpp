#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int MAX_VAL = 1e5;

        long long total = 0;
        for (auto& row : grid) {
            for (int v : row) {
                total += v;
            }
        }

        // ── Helper: Check if removing 'target_val' breaks connectivity ──
        auto canRemove = [&](int r1, int r2, int c1, int c2, long long target_val) -> bool {
            if (target_val < 1 || target_val > MAX_VAL) return false;
            
            int h = r2 - r1 + 1;
            int w = c2 - c1 + 1;

            if (h > 1 && w > 1) {
                // 2D Block: Safe to remove ANY matching element
                for (int i = r1; i <= r2; ++i) {
                    for (int j = c1; j <= c2; ++j) {
                        if (grid[i][j] == target_val) return true;
                    }
                }
            } else if (h == 1) {
                // 1D Horizontal Strip: Only safe to remove the first or last element
                if (grid[r1][c1] == target_val) return true;
                if (grid[r1][c2] == target_val) return true;
            } else if (w == 1) {
                // 1D Vertical Strip: Only safe to remove the first or last element
                if (grid[r1][c1] == target_val) return true;
                if (grid[r2][c1] == target_val) return true;
            }
            
            return false;
        };

        // ── Horizontal cuts ─────────────────────────────────────────────
        long long top_sum = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int v : grid[i]) {
                top_sum += v;
            }
            long long bot_sum = total - top_sum;

            if (top_sum == bot_sum) return true;

            long long diff = top_sum - bot_sum; 
            // subtract from the larger side to equalize
            if (diff > 0 && canRemove(0, i, 0, n - 1, diff)) return true;
            if (diff < 0 && canRemove(i + 1, m - 1, 0, n - 1, -diff)) return true;
        }

        // ── Vertical cuts ────────────────────────────────────────────────
        long long left_sum = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                left_sum += grid[i][j];
            }
            long long right_sum = total - left_sum;

            if (left_sum == right_sum) return true;

            long long diff = left_sum - right_sum;
            // subtract from the larger side to equalize
            if (diff > 0 && canRemove(0, m - 1, 0, j, diff)) return true;
            if (diff < 0 && canRemove(0, m - 1, j + 1, n - 1, -diff)) return true;
        }

        return false;
    }
};

int main(){
    Solution S;
    vector<vector<int>> grid={{1,2,4},{2,3,5}};
    cout<<S.canPartitionGrid(grid)<<endl;
    return 0;
}