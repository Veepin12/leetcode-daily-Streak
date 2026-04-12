#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
    int memo[301][27][27];
    int n;

    // Calculate Manhattan distance between two characters
    int getDist(int a, int b) {
        if (a == 26 || b == 26) return 0; // Initial free position
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int dp(int idx, int f1, int f2, const string& word) {
        if (idx == n) return 0;
        if (memo[idx][f1][f2] != -1) return memo[idx][f1][f2];

        int target = word[idx] - 'A';
        // Move finger 1 to target
        int cost1 = getDist(f1, target) + dp(idx + 1, target, f2, word);
        // Move finger 2 to target
        int cost2 = getDist(f2, target) + dp(idx + 1, f1, target, word);

        return memo[idx][f1][f2] = min(cost1, cost2);
    }

public:
    int minimumDistance(string word) {
        n = word.length();
        // Initialize memoization table with -1
        for(int i=0; i<=n; ++i)
            for(int j=0; j<27; ++j)
                for(int k=0; k<27; ++k)
                    memo[i][j][k] = -1;
        
        // Start with both fingers at virtual position 26 (free)
        return dp(0, 26, 26, word);
    }
};

int main() {
    Solution sol;
    cout << sol.minimumDistance("CAKE") << endl;  // Output: 3
    cout << sol.minimumDistance("HAPPY") << endl; // Output: 6
    return 0;
}