#include <iostream>
using namespace std;
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        // minDamage[i][j] = minimum health lost to reach (i,j)
        vector<vector<int>> minDamage(m, vector<int>(n, INT_MAX));
        minDamage[0][0] = grid[0][0];
        
        queue<pair<int,int>> q;
        q.push({0, 0});
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) 
                    continue;
                
                int newDamage = minDamage[x][y] + grid[nx][ny];
                
                // health must stay positive: health - newDamage > 0
                if (newDamage >= health) 
                    continue;
                
                if (newDamage < minDamage[nx][ny]) {
                    minDamage[nx][ny] = newDamage;
                    q.push({nx, ny});
                }
            }
        }
        
        int finalDamage = minDamage[m-1][n-1];
        return finalDamage != INT_MAX && health - finalDamage >= 1;
    }
};
int main(){
    int n ;
    cin>>n;

    vector<vector<int>> grid(n , vector<int> ( n)) ;
    for( int i = 0; i < n; i++){
        for(int j = 0 ;  j < n ;j++){
            cin>>grid[i][j];
        }
    }
    int health;
    cin>>health;
    Solution S;

    cout<<S.findSafeWalk( grid, health);
    return 0;

}