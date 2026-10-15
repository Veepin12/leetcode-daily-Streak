//
//  Count_prime.cpp
//  DSA_with_cpp
//
//  Created by Veepin kumar on 15/10/26.
//

/*
 Given an integer n, return the number of prime numbers that are equal  to the  n.

  

 Example 1:

 Input: n = 10
 Output: 4
 Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 Example 2:

 Input: n = 0
 Output: 0
 Example 3:

 Input: n = 1
 Output: 0
  

 Constraints:

 0 <= n <= 5 * 106
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> is_prime( int n ){
        
        vector<bool> vis( n + 1 , true);
        
        if( n >= 0) vis[0] = false;
        if( n >= 1) vis[1] = false;
       
        
        for( int i = 2; i * i <= n ; i++){
            if( vis[i]){
                
                for( int d = i * i; d  <= n ; d += i){
                    vis[d] = false;
                }
            }
        }
        return vis;
    }
    int count_prime( int n){
        
        vector<bool> ans = is_prime(n);
        vector<bool> res;
        
        for( int i = 0; i < ans.size(); i++){
            if(ans[i]){
                res.push_back(i);
            }
        }
        
        
        
        
        return (int)res.size();
        
    }
};
int main(){
    
    int n;
    cin>>n;
    Solution S;
    
    cout<<S.count_prime(n)<<endl;
    return 0;
}
