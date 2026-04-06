#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    // Direction vectors: North, East, South, West
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    
    // Encode obstacles as long long for O(1) lookup
    unordered_set<long long> obstacle_set;
    for (auto& obs : obstacles) {
        long long key = (long long)(obs[0] + 30001) * 100000 + (obs[1] + 30001);
        obstacle_set.insert(key);
    }
    
    int x = 0, y = 0;
    int dir = 0; // 0=North, 1=East, 2=South, 3=West
    int maxDistSq = 0;
    
    for (int cmd : commands) {
        if (cmd == -1) {
            dir = (dir + 1) % 4; // Turn right
        } else if (cmd == -2) {
            dir = (dir + 3) % 4; // Turn left
        } else {
            for (int step = 0; step < cmd; step++) {
                int next_x = x + dx[dir];
                int next_y = y + dy[dir];
                
                long long key = (long long)(next_x + 30001) * 100000 + (next_y + 30001);
                if (obstacle_set.count(key)) {
                    break; // Blocked, stop this command
                }
                
                x = next_x;
                y = next_y;
                maxDistSq = max(maxDistSq, x*x + y*y);
            }
        }
    }
    
    return maxDistSq;
}

// ── driver ──────────────────────────────────────────────
int main() {
    

   
    vector<int> commands1 = {4, -1, 3};
    vector<vector<int>> obstacles1 = {};
    cout << "Example 1 Output: " << robotSim(commands1, obstacles1) << endl;
    
    vector<int> commands2 = {4, -1, 4, -2, 4};
    vector<vector<int>> obstacles2 = {{2, 4}};
    cout << "Example 2 Output: " << robotSim(commands2, obstacles2) << endl;
   
    vector<int> commands3 = {6, -1, -1, 6};
    vector<vector<int>> obstacles3 = {{0, 0}};
    cout << "Example 3 Output: " << robotSim(commands3, obstacles3) << endl;
    

    return 0;
}