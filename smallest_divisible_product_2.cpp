//
//  sallest_divisible_product2.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 07/08/26.

/*
 You are given a string num which represents a positive integer, and an integer t.

 A number is called zero-free if none of its digits are 0.

 Return a string representing the smallest zero-free number greater than or equal to num such that the product of its digits is divisible by t. If no such number exists, return "-1".
 */
//

#include <iostream>
using namespace std;

class Solution{
public:
    
    int f( int n){
        int product = 1;
        while( n > 0){
            product *= n % 10;
            n /= 10;
            
        }
        return product;
    }
    
    bool d(int x){// it is function that detect the number of Zeroes in the product ..
        
        
        int count = 0;
        int pro = 1;
        
        while( x > 0){
            pro = x % 10;
            if(pro % 10 == 0) count++;
            x /= 10;
        }
        
        
        return count == 0 ? true : false;
        
    }
    
    string smallest(string  s  ,int t){
        
        int n = stoi(s);
        if(t % 11 == 0 || t % 13 == 0 ) return "-1";
        for( int i = n ; i < 1e14; i++){
            if( f(i) % t == 0 && d(i)){
                string x = to_string(i);
                return x;
            }
        }
        return "-1";
       
        
        
    }
};
int main(){
    
    string s;
    cin>>s;
    int t;
    cin>>t;
    
    Solution S;
    cout<<S.smallest( s , t)<<endl;
    return 0;
    // s = "12355", t = 50
    // s = "11111", t = 26
}
