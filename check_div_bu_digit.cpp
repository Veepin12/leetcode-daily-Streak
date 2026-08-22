//
//  check_div_by_digit.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 22/08/26.
//
/*
You are given a positive integer n. Determine whether n is divisible by the sum of the following two values:

The digit sum of n (the sum of its digits).

The digit product of n (the product of its digits).

Return true if n is divisible by this sum; otherwise, return false.



Example 1:

Input: n = 99

Output: true

Explanation:

Since 99 is divisible by the sum (9 + 9 = 18) plus product (9 * 9 = 81) of its digits (total 99), the output is true.

Example 2:

Input: n = 23

Output: false

Explanation:

Since 23 is not divisible by the sum (2 + 3 = 5) plus product (2 * 3 = 6) of its digits (total 11), the output is false.

 

Constraints:

1 <= n <= 106
 */

#include <iostream>
using namespace std;

class Solution{
public:
    int product( int n){
        
        if( n == 0) return 0;
        
        int pro = 1;
        
        while( n > 0){
            
            pro *= n % 10;
           
            n /= 10;
        }
        return pro;
    }
    int sum( int n){
        
        if( n == 0) return 0;
        
        int s = 0;
        
        while( n > 0){
             s += n % 10;
            n /= 10;
        }
        return s;
    }
    bool check_div_digit( int n){
        if( n == 1) return 1;
        
        int pr = product(n);
        int sm = sum(n);
        
        if( n % (pr + sm) == 0) return true;
        return false;
    }
};
int main(){
    int n;
    cin>>n;
    
    Solution S;
    
    
    cout<<S.check_div_digit(n)<<endl;
    return 0;
}

