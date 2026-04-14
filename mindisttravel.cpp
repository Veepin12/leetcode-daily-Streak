#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end()); // sort by position

    int n = robot.size(), m = factory.size();
    // dp[i][j]: min cost for first i robots using first j factories
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 1e18));
    dp[0][0] = 0;

    for (int j = 1; j <= m; ++j) {
        dp[0][j] = 0; // 0 robots cost 0
        int pos = factory[j-1][0];
        int limit = factory[j-1][1];

        for (int i = 0; i <= n; ++i) {
            dp[i][j] = dp[i][j-1]; // don't use this factory
            ll cost = 0;
            // try assigning last k robots to factory j
            for (int k = 1; k <= limit && i - k >= 0; ++k) {
                cost += abs(robot[i - k] - pos);
                dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + cost);
            }
        }
    }
    return dp[n][m];
}

int main(){
    vector<int> robot ={ 0 , 4, 6};
    vector<vector<int>> factory={{2,2},{6,2}};
   cout<<minimumTotalDistance(robot,factory);

    return 0;
}