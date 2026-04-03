#include <iostream>
#include<vector>
#include <set>
using namespace std;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
       

     int n=robots.size();
    // pair robot position with its distance, then sort
    vector<pair<int,int>> bots(n);
    for (int i = 0; i < n; i++)
        bots[i] = {robots[i], distance[i]};
    sort(bots.begin(), bots.end());
    sort(walls.begin(), walls.end());
    
    set<int> destroyed;
    
    for (int i = 0; i < n; i++) {
        int pos  = bots[i].first;
        int dist = bots[i].second;
        
        // left range
        int lo = pos - dist;
        int hi = pos;
        if (i > 0) lo = max(lo, bots[i-1].first); // blocked by left robot
        
        int left_count = (int)(upper_bound(walls.begin(), walls.end(), hi) -
                               lower_bound(walls.begin(), walls.end(), lo));
        
        // right range
        int rlo = pos;
        int rhi = pos + dist;
        if (i < n-1) rhi = min(rhi, bots[i+1].first); // blocked by right robot
        
        int right_count = (int)(upper_bound(walls.begin(), walls.end(), rhi) -
                                lower_bound(walls.begin(), walls.end(), rlo));
        
        // pick better direction and add walls to destroyed set
        if (left_count >= right_count) {
            auto l = lower_bound(walls.begin(), walls.end(), lo);
            auto r = upper_bound(walls.begin(), walls.end(), hi);
            for (auto it = l; it != r; it++)
                destroyed.insert(*it);
        } else {
            auto l = lower_bound(walls.begin(), walls.end(), rlo);
            auto r = upper_bound(walls.begin(), walls.end(), rhi);
            for (auto it = l; it != r; it++)
                destroyed.insert(*it);
        }
    }
    
    return (int)destroyed.size();
}


        
    
};

int main(){
    Solution S;
    vector<int> robots={4};
    vector<int> distance={3};
    vector<int> walls={1,10};

    cout<<S.maxWalls(robots,distance,walls)<<endl;
    return 0;

}