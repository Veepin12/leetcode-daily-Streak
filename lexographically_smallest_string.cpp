//
//  polindrome_lexo.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 28/07/26.
//

#include <iostream>
using namespace std;

class Solution {
public:
    
    
    string smallestPolindrome( string s){
        
        long n = s.size();
        
        int count[26] = {0};
        
        // O(n) time Complexity..
        for( int i = 0; i < n/2 ; i++){
            count[i + 'a']++;
        }
        
        // O(n) Time Complexity..
        
        for( int i = 0; i < 26; i++){
            while( count[i]-- > 0){
                s[i++] = char( i + 'a');
            }
        }
        // O(n) Time Complexity..
        for( int i = 0; i < n / 2; i++){
            s[ n - i - 1] = s[i];
        }
        
        return s;
    }
   
    
    
};
int main(){
    string s;
    getline(  cin , s);
    
    Solution S;
    
    cout<<S.smallestPolindrome(s)<<endl;
    return 0;
}
