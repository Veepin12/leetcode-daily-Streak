//
//  optimal.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 06/09/26.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long int
using namespace std;

// you have a give string s and t , count number of min opteration to remove , insert , replace form s to make equal to t .

class Solution{
public:
    
    
    int op_str( string s , string t){
        long m = s.length();
        long n = t.length();
        
        // dp[i][j] will hold the minimum operations to convert s[0..i-1] to t[0..j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Base cases
        // If t is empty, we must remove all characters from s
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        // If s is empty, we must insert all characters of t
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // If characters match, no new operation is needed
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // If they don't match, take the minimum of Insert, Remove, or Replace
                else {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],    // Remove a character from s
                        dp[i][j - 1],    // Insert a character into s
                        dp[i - 1][j - 1] // Replace a character in s
                    });
                }
            }
        }
        
       return dp[m][n] ;
    }
    
};
int main(){
    
    string s , t;
    cin>>s>>t;
    
    Solution S;
    
    
    cout<<S.op_str(s, t)<<endl;
    return 0;
}
