#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Solution{
public:
vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int n = positions.size();
    
    // Create indices sorted by position
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);  // for(int i=0;i<n;i++) indices[i]=i;
    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return positions[a] < positions[b];
    });
    
    vector<int> stack;  // stores original indices of rightward robots
    vector<bool> alive(n, true);
    
    for (int i : indices) {
        if (directions[i] == 'R') {
            stack.push_back(i);
        } else {
            // Current robot moves Left — may collide with stacked R robots
            while (!stack.empty()) {
                int top = stack.back();
                
                if (healths[top] > healths[i]) {
                    // Rightward robot wins
                    healths[top]--;
                    alive[i] = false;
                    break;
                } else if (healths[top] < healths[i]) {
                    // Leftward robot wins, continues to next collision
                    healths[i]--;
                    alive[top] = false;
                    stack.pop_back();
                } else {
                    // Equal health — both removed
                    alive[top] = false;
                    alive[i]  = false;
                    stack.pop_back();
                    break;
                }
            }
        }
    }
    
    // Collect survivors in original order
    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (alive[i]) result.push_back(healths[i]);
    }
    return result;
}
};

int main(){
    class Solution S;
    vector<int> positions={5,4,3,2,1};
    vector<int> health={2,17,9,15,10};
    string directions="RRRRR";

    vector<int> result=S.survivedRobotsHealths(positions,health,directions);
    for(auto row: result){
        cout<<row<<" ";

    }
    cout<<endl;
    return 0;
}