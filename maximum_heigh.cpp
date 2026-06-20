#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxBuilding(int building, vector<vector<int>>& restrictions) {
        
        
        

        auto && r = restrictions;
        r.push_back({1 , 0});

        sort(r.begin() , r.end());

        if( r.back()[0] != building){
            r.push_back({building, building - 1});

        }



        

        for( int i = 1 ; i < r.size(); i++){
            r[i][1] = min(r[i][1] , r[i - 1][1] + ( r[i][0] - r[i - 1][0]));
        }

       for (int i = r.size() - 2; i >= 0; --i) {
            r[i][1] = min(r[i][1], r[i + 1][1] + (r[i + 1][0] - r[i][0]));
        }

        int ans = 0;
        for (int i = 0; i < r.size() - 1; ++i) {
            // Calculate the maximum height of the buildings between r[i][0] and
            // r[i][1]
            int best = ((r[i + 1][0] - r[i][0]) + r[i][1] + r[i + 1][1]) / 2;
            ans = max(ans, best);
        }

        return ans;
        
    }
};

int main(){

    Solution S;

    int building;
    cin>>building;

    vector<vector<int>> restrictions = {{ 5,3} , { 2, 1} , { 7, 4}, { 10 , 3}};

    cout<<S.maxBuilding(building , restrictions)<<endl;
    return 0;
}