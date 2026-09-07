//
//  Untitled.h
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 07/09/26.
//
/*
 You are given a binary string binary. A subsequence of binary is considered good if it is not empty and has no leading zeros (with the exception of "0").

 Find the number of unique good subsequences of binary.

 For example, if binary = "001", then all the good subsequences are ["0", "0", "1"], so the unique good subsequences are "0" and "1". Note that subsequences "00", "01", and "001" are not good because they have leading zeros.
 Return the number of unique good subsequences of binary. Since the answer may be very large, return it modulo 109 + 7.

 A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.


 */
#include <iostream>
#define ll long long int
using namespace std;

class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        
        ll MOD  = 10e9 + 7;
        
        int dp[2][2] = {};
        
        for( char ch : binary){
            
            int val = ch - '0';
            //dp[i][j] , where i is string that start with i, and j defines end with j..
            if( val == 0){
                dp[0][0] = 1; // sting that contain only 0 , that will start and end with 0..
                dp[1][0] = dp[1][0] + dp[1][1]; // string that end with 0..and start with 1..
            }
            else{
                // string that start and end with 1 ..
                dp[1][1] = dp[1][0] + dp[1][1]  + 1;
                
            }
        }
        
        return (dp[0][0] + dp[0][1] + dp[1][0] + dp[1][1]) % MOD;
    }
    int numberOfUniqueGoodSubsequences1(string binary) {
            int mod = 1e9 + 7, dp[2] = {0, 0};
            for (char& c: binary)
                dp[c - '0'] = (dp[0] + dp[1] + c - '0') % mod;
            return (dp[0] + dp[1] + (binary.find("0") != string::npos)) % mod;
        }
};

int main(){
    
    string s;
    cin>>s;
    Solution S;
    
    cout<<S.numberOfUniqueGoodSubsequences(s)<<endl;
    cout<<S.numberOfUniqueGoodSubsequences1(s)<<endl;
    return 0;
}
