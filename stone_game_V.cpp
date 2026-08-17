//
//  stone_Game_V.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 10/08/26.
//
/*
 Alice and Bob take turns playing a game, with Alice starting first.

 Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.

 Also, if a player cannot make a move, he/she loses the game.

 Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.

  

 Example 1:

 Input: n = 1
 Output: true
 Explanation: Alice can remove 1 stone winning the game because Bob doesn't have any moves.
 Example 2:

 Input: n = 2
 Output: false
 Explanation: Alice can only remove 1 stone, after that Bob removes the last one winning the game (2 -> 1 -> 0).
 Example 3:

 Input: n = 4
 Output: true
 Explanation: n is already a perfect square, Alice can win with one move, removing 4 stones (4 -> 0).
  

 Constraints:

 1 <= n <= 105
 */


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



class Solution {
    int dp[501][501];
    int prefix[501];

    int solve( vector<int>& stoneValue, int left, int right) {
        // Base case: only one stone left, Alice gets 0 score.
        if (left == right) return 0;
        
        // Return already computed result
        if (dp[left][right] != -1) return dp[left][right];

        int max_score = 0;
        
        // Try all possible split points between 'left' and 'right'
        for (int i = left; i < right; i++) {
            // Calculate sum of the left and right rows using prefix sum
            int left_sum = prefix[i + 1] - prefix[left];
            int right_sum = prefix[right + 1] - prefix[i + 1];

            if (left_sum < right_sum) {
                // Bob throws away the right row, Alice gets left_sum + max score from left row
                max_score = max(max_score, left_sum + solve(stoneValue, left, i));
            } else if (left_sum > right_sum) {
                // Bob throws away the left row, Alice gets right_sum + max score from right row
                max_score = max(max_score, right_sum + solve(stoneValue, i + 1, right));
            } else {
                // Sums are equal, Bob lets Alice decide. We test both choices to maximize her score.
                max_score = max({max_score,
                                 left_sum + solve(stoneValue, left, i),
                                 right_sum + solve(stoneValue, i + 1, right)});
            }
        }
        
        return dp[left][right] = max_score;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        long n = stoneValue.size();
        
        // Initialize DP table with -1
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }
        
        // Build prefix sum array for O(1) range sum queries
        prefix[0] = 0;
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        
        return solve(stoneValue, 0,(int) n - 1);
    }
};



int main(){
    int n ;
    cin>>n;
    vector<int> stones(n);
    
    for( int i = 0; i < n; i++){
        cin>>stones[i];
    }
    
    Solution S;
    //  [6,2,3,4,5,5]
    
    
    cout<<S.stoneGameV( stones)<<endl;
    
    return 0;
}
