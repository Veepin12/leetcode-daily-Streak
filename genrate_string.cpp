//
//  genrate_string.cpp
//  DSA_with_cpp
//
//  Created by Veepin kumar on 27/10/26.
//

/*
 You are given two integers m and n, representing the number of rows and columns of a grid.

 Construct any m x n grid consisting only of the characters '.' and '#', where:

 '.' represents a free cell.
 '#' represents an obstacle cell.
 A valid path is a sequence of free cells that:

 Starts at the top-left cell (0, 0).
 Ends at the bottom-right cell (m - 1, n - 1).
 Moves only:
 Right, from (i, j) to (i, j + 1), or
 Down, from (i, j) to (i + 1, j).
 Return any grid such that there is exactly one valid path from the top-left cell to the bottom-right cell.

  

 Example 1:

 Input: m = 2, n = 3

 Output: ["..#","#.."]

 Explanation:



 The only valid path is: (0,0) → (0,1) → (1,1) → (1,2)

 Example 2:

 Input: m = 3, n = 3

 Output: ["..#","#..","##."]

 Explanation:



 The only valid path is: (0,0) → (0,1) → (1,1) → (1,2) → (2,2)

 Example 3:

 Input: m = 1, n = 4

 Output: ["...."]

 Explanation:

 The only valid path is: (0,0) → (0,1) → (0,2) → (0,3)

  

 Constraints:

 1 <= m, n <= 25
 */

#include <iostream>
using namespace std;

class Solution{
public:
    
    
   vector<string> g( int m , int n){
        
        vector<string> res( m , string( n , '#'));
        
        int r = 0 , c = 0;
        
        res[r][c] = '.';
        
        while( r < m - 1 || c < n - 1){
            if( r < m - 1 && ( c == m - 1 || abs( r  + 1 ) * m - 1 - c * ( m - 1) <= abs(r * (n - 1) - (c + 1) * (m - 1)))){
                r++;
                
            }else c++;
            
            res[r][c] = '.';
        }
        
        return res;
    }
    
    vector<string> f( int n , int m){
        
        vector<string> res( n , string( m , '#'));
        for( int i = 0; i < m ; i++){
            res[0][i] = '.';
        }
        for( int i = 0 ;  i < n; i++){
            res[i][m - 1] = '.';
        }
        return res;
    }
        
       
};
int main(){
    
    int m , n;
    cin>>m>>n;
    
    Solution S;
    
    vector<string> ans = S.f(m,n);
    
    for( int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    cout<<endl;
    return 0;
}
