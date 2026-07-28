//
//  min_Cost_path_||.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 27/07/26.
//
//
//You are given two integers m and n representing the number of rows and columns of a grid. Your goal is to reach cell (m - 1, n - 1). You are also given a 2D integer array penalty.
//
//The cost to enter cell (i, j) is (i + 1) * (j + 1).
//
//You begin at cell (0, 0) and initially pay its entrance cost. Actions performed after entering (0, 0) are numbered starting from 1.
//
//On each action, you may move to an adjacent cell or wait in the current cell. A move follows the parity rule if:
//
//On an odd-numbered action, you move right or down.
//On an even-numbered action, you move left or up.
//The cost of an action is determined as follows:
//
//If you move according to the parity rule, pay only the entrance cost of the destination cell.
//If you move in a direction that violates the parity rule, pay the entrance cost of the destination cell plus penalty[i][j], where (i, j) is the cell you move from.
//If you wait in cell (i, j), pay penalty[i][j].
//After every move or wait, the action number increases by 1. Therefore, the required parity alternates after every action, regardless of whether a penalty was paid.
//
//Return the minimum total cost required to reach (m - 1, n - 1).
//
// 
//
//Example 1:
//
//Input: m = 2, n = 2, penalty = [[5,3],[1,4]]
//
//Output: 8
//
//Explanation:
//
//The optimal path is:
//
//Start at cell (0, 0) with entry cost (0 + 1) * (0 + 1) = 1.
//Move 1: Move down to cell (1, 0) with entry cost (1 + 1) * (0 + 1) = 2.
//Move 2: Move right to cell (1, 1) with entry cost (1 + 1) * (1 + 1) = 4 and an extra cost of penalty[1][0] = 1 for violating the even parity rule.
//Thus, the total cost is 1 + 2 + 4 + 1 = 8.
//
//Example 2:
//
//Input: m = 2, n = 2, penalty = [[0,7],[3,2]]
//
//Output: 7
//
//Explanation:
//
//The optimal path is:
//
//Start at cell (0, 0) with entry cost (0 + 1) * (0 + 1) = 1.
//Move 1: Wait at cell (0, 0) with an extra cost of penalty[0][0] = 0 to flip to even parity.
//Move 2: Move right to cell (0, 1) with entry cost (0 + 1) * (1 + 1) = 2 and an extra cost of penalty[0][0] = 0 for violating the even parity rule.
//Move 3: Move down to cell (1, 1) with entry cost (1 + 1) * (1 + 1) = 4.
//Thus, the total cost is 1 + 0 + 2 + 0 + 4 = 7.
//
//Example 3:
//
//Input: m = 2, n = 3, penalty = [[8,0,9],[7,4,1]]
//
//Output: 12
//
//Explanation:
//
//The optimal path is:
//
//Start at cell (0, 0) with entry cost (0 + 1) * (0 + 1) = 1.
//Move 1: Move right to cell (0, 1) with entry cost (0 + 1) * (1 + 1) = 2.
//Move 2: Move right to cell (0, 2) with entry cost (0 + 1) * (2 + 1) = 3 and an extra cost of penalty[0][1] = 0 for violating the even parity rule.
//Move 3: Move down to cell (1, 2) with entry cost (1 + 1) * (2 + 1) = 6.
//Thus, the total cost is 1 + 2 + 3 + 0 + 6 = 12.
//
// 
//
//Constraints:
//
//1 <= m, n <= 105
//2 <= m * n <= 105
//penalty.length == m
//penalty[i].length == n
//0 <= penalty[i][j] <= 105

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define pp pair<long,pair< int, pair<int, int>>>
using namespace std;



class Solution {
public:
    int minimumCost(int m, int n, vector<vector<int>>& penalty) {
        // dist[i][j][parity] = min cost to reach (i,j) where parity = 0 means next action is odd, 1 means even
        vector<vector<vector<long long>>> dist(m, vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX)));
        
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        
        // Start at (0,0), cost = (0+1)*(0+1) = 1, next action is 1 (odd), so parity = 0
        dist[0][0][0] = 1;
        pq.push({1, {0, {0, 0}}});
        
        while (!pq.empty()) {
            auto ele = pq.top();
            pq.pop();
            
            if (ele.first > dist[ele.second.first][ele.second.second.first][ele.second.second.second]) continue;
            
            // Try 4 move directions: right(0), down(1), left(2), up(3)
            vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            
            for (int d = 0; d < 4; d++) {
                int ni = ele.second.first + dirs[d].first;
                int nj = ele.second.second.first + dirs[d].second;
                
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                
                bool violate = false;
                
                // Check if move violates parity
                if (ele.second.second.second == 0) { // next action is odd: can move right(0) or down(1)
                    if (d >= 2) violate = true; // left(2) or up(3) violates
                } else { // next action is even: can move left(2) or up(3)
                    if (d < 2) violate = true; // right(0) or down(1) violates
                }
                
                long long cell_cost = (long long)(ni + 1) * (nj + 1);
                long long new_cost = ele.first + cell_cost;
                
                if (violate) {
                    new_cost += penalty[ele.second.first][ele.second.second.first];
                }
                
                int new_parity = 1 - ele.second.second.second; // flip parity after action
                
                if (new_cost < dist[ni][nj][new_parity]) {
                    dist[ni][nj][new_parity] = new_cost;
                    pq.push({new_cost,{ ni,{ nj, new_parity}}});
                }
            }
            
            // Wait action: pay penalty, flip parity (skip current cell)
            long long new_cost = ele.first + penalty[ele.second.first][ele.second.second.first];
            int new_parity = 1 - ele.second.second.second;
            
            if (new_cost < dist[ele.second.first][ele.second.second.first][new_parity]) {
                dist[ele.second.first][ele.second.second.first][new_parity] = new_cost;
                pq.push({new_cost,{ ele.second.first, {ele.second.second.first, new_parity}}});
            }
        }
        
        // Can reach destination with either parity
        return min(dist[m-1][n-1][0], dist[m-1][n-1][1]);
    }
};

int main(){
    int m, n;
    cin >> m >> n;
    
    vector<vector<int>> penalty(m, vector<int>(n));
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> penalty[i][j];
        }
    }
    
    Solution S;
    
    cout << S.minimumCost(m, n, penalty) << endl;
    return 0;
}

