//
//  maxGridformin_operation.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 29/04/26.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        long long  n = grid.size();
        
        // Edge case for a 1x1 grid: no horizontally adjacent columns exist.
        if (n == 1) return 0;

        // Precompute prefix sums for each column to query segment sums in O(1).
        // pre[j][k] stores the sum of grid[0...k-1][j]
        vector<vector<long long>> pre(n, vector<long long>(n + 1, 0));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                pre[j][i + 1] = pre[j][i] + grid[i][j];
            }
        }

        // dp[c][n_next] represents the max score up to current column where:
        // 'c' is the height of the current column
        // 'n_next' is the height of the next column
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
        
        // Base case: initialize scores for column 0
        for (int c = 0; c <= n; ++c) {
            for (int n_next = 0; n_next <= n; ++n_next) {
                long long score = 0;
                if (n_next > c) {
                    score = pre[0][n_next] - pre[0][c];
                }
                dp[c][n_next] = score;
            }
        }

        // DP transitions for columns 1 to n-2
        for (int j = 1; j < n - 1; ++j) {
            vector<vector<long long>> next_dp(n + 1, vector<long long>(n + 1, -1));

            for (int c = 0; c <= n; ++c) {
                vector<long long> prev_dp(n + 1, -1);
                for(int p = 0; p <= n; ++p) prev_dp[p] = dp[p][c];

                // Precompute prefix maximums for the p <= n_next scenario
                vector<long long> pref_mx(n + 1, -1);
                long long mx = -1;
                for (int p = 0; p <= n; ++p) {
                    mx = max(mx, prev_dp[p]);
                    pref_mx[p] = mx;
                }

                // Precompute suffix maximums for the p > n_next scenario
                vector<long long> term(n + 1, -1);
                for (int p = 0; p <= n; ++p) {
                    if (prev_dp[p] != -1) {
                        long long sc = 0;
                        if (p > c) sc = pre[j][p] - pre[j][c];
                        term[p] = prev_dp[p] + sc;
                    }
                }

                vector<long long> suff_mx(n + 2, -1);
                mx = -1;
                for (int p = n; p >= 0; --p) {
                    mx = max(mx, term[p]);
                    suff_mx[p] = mx;
                }

                // Compute transitions in O(1) using the precomputed max arrays
                for (int n_next = 0; n_next <= n; ++n_next) {
                    long long best = -1;
                    
                    // Case 1: max height bounded by the next column
                    if (pref_mx[n_next] != -1) {
                        long long sc = 0;
                        if (n_next > c) sc = pre[j][n_next] - pre[j][c];
                        best = max(best, pref_mx[n_next] + sc);
                    }
                    
                    // Case 2: max height bounded by the previous column
                    if (suff_mx[n_next + 1] != -1) {
                        best = max(best, suff_mx[n_next + 1]);
                    }
                    
                    next_dp[c][n_next] = best;
                }
            }
            dp = next_dp;
        }

        // Final step: Calculate scores for the last column (j = n - 1)
        long long ans = 0;
        for (int p = 0; p <= n; ++p) {
            for (int c = 0; c <= n; ++c) {
                if (dp[p][c] != -1) {
                    long long sc = 0;
                    if (p > c) sc = pre[n - 1][p] - pre[n - 1][c];
                    ans = max(ans, dp[p][c] + sc);
                }
            }
        }

        return ans;
    }
};

int main(){
    
    Solution S;
    vector<vector<int>> grid = {{195200396,793146510,539947128,864972466,524601205,246191098,464979981,832886019,96904551,594127603,359469151,182192046,738059908,450595127,111405257},{106421506,136213676,618217935,605828788,26427981,955371668,387846009,791856217,412995990,618995673,120607902,841056495,852241291,416442298,572658353},{772186702,452560957,515179235,402972767,712920763,251414396,996685244,626988116,51537801,180477222,327994742,660912629,272397919,282962629,182510658},{944427541,239693516,675595394,834647365,401461354,394412547,454536248,788972529,352306747,405506711,831983250,648877991,861188418,356022754,106552334},{530973237,389092491,500407969,669427900,806888642,541468362,372858144,69127265,992142085,288511201,575823772,465343802,982339357,965905461,932731947},{396322228,804622191,771598401,528728797,97645292,610453104,505587340,933958422,208814781,305427737,193791586,94087422,239130425,453700380,319986907},{120245311,517201926,157619127,772246199,608946270,266515614,736077889,239389075,645515100,821588325,934430178,288415426,42943646,301823515,269628832},{280739174,51843717,645481035,983295191,241305975,413932398,368517083,620356357,699763076,731255143,307704614,811023853,554267792,426584637,981957058},{290408113,398155705,864869642,79641022,60888481,822109810,812942683,213496660,389229980,820521091,242982583,427049434,807364949,684574448,177934134},{177149056,849621927,824271045,31657286,326065232,364303679,777520505,202919671,832578100,691414370,12456269,58587651,554751297,771231656,487626468},{13809272,463949446,190766090,363739248,2853697,274102413,12272084,140432881,273119694,498345023,399278983,938277142,57056826,980191284,144531835},{472729771,185067214,792167294,941900334,526064,847949385,95429817,580829407,984057016,367797695,562368848,384723916,88256486,31976113,872276412},{863297437,113861440,681967499,577238574,190669075,119987289,7218251,442917308,299466322,79685876,332736614,399873406,975139768,80602890,253713656},{392344239,23431137,749259010,614113637,515009383,131750067,442537686,934802789,21015160,460629134,221117007,432354449,15764333,888657274,780857181},{901640904,729375334,449271099,403520622,941628222,173633990,307307426,962633215,710817869,912344584,462332784,504975075,480961872,494899399,103678591}};
    
    cout<<S.maximumScore(grid)<<endl;
    return 0;
}
           
