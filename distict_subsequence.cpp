#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long int
using namespace std;

class Solution {
public:

    int disctinct_sub( string s , string t){

        int n = s.size();
        int m = t.size();


        vector<vector<ll>> dp( n + 1 , vector<ll> ( m + 1 , 0));

        for( int i = 0 ; i <= n ; i++){
            dp[i][m] = 1;
        }

        if( n < m) return 0;

        else{


            for( int i = n - 1 ; i >= 0 ; i--){
                for( int j = m - 1; j >= 0 ; j--){

                    if( s[i] == t[j]){
                        dp[i][j] = dp[i  + 1][ j + 1] + dp[i + 1][j];
                    }
                    else{
                        dp[i][j] = dp[i + 1][j];
                    }
                }
            }
        }

        return dp[0][0];
    }

};
int main(){

    string s, t;
    cin>>s>>t;

    Solution S;

    cout<<S.disctinct_sub(s , t)<<endl;
     
    return 0;
}
