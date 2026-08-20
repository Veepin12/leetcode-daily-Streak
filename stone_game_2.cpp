//
//  stone_game_2.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 20/08/26.
//
/*
 Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. The objective of the game is to end with the most stones.

 Alice and Bob take turns, with Alice starting first.

 On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.

 The game continues until all the stones have been taken.

 Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.
 
 
Examples ..
 
 Input: piles = [2,7,9,4,4]

 Output: 10

 Explanation:

 If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 stones in total.
 If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 stones in total.
 So we return 10 since it's larger.
  
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int n ;
    int t[2][101][101];
    int f( vector<int> & stones, int alice , int i , int M ){
        if( i >= n) return 0;
       
        if( t[alice][i][M] != -1){
            return t[alice][i][M];
        }
        
        int stone = 0;
        
        int res  = (alice == 1) ? -1 : INT_MAX;
        
       
        
        for( int x = 1 ; x <= min({ 2 * M , n - i }); x++){
            
            stone += stones[ i + x - 1];
            
            if( alice == 1){
                // alice take our best optimal choice ..
                res = max( res , stone + f( stones ,0 ,  i + x , max( M , x)));
            }
            else{
                // bob takes our best optimal choices ...
                res = min(res , f( stones, 1,  i + x , max( M , x)));
            }
        }
        return t[alice][i][M] = res;
    }
    int stoneGame2( vector<int> & stones){
        
        memset( t , -1 , sizeof(t));
        
        n = stones.size();
        
        return f( stones , 1 , 0, 1);
   }
    
};
int main(){
    int n ;
    cin>>n;
    
    vector<int> stones(n);
    
    for( int i = 0 ; i < n; i++){
        cin>>stones[i];
    }
    
    Solution S;
    
    cout<<S.stoneGame2(stones)<<endl;
    return 0;
}

//3111 4303 2722 2183 6351 5227 8964  7167 9286 6626 2347 1465 5201 7240 5463 8523 8163  9391 8616 5063 7837 7050 1246 9579 7744 6932 7704 9841 6163 4829 7324 6006 4689 8781 621
