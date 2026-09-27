//
//  reverse_substring_parenthesis.cpp
//  DSA_with_cpp
//
//  Created by Veepin kumar on 27/09/26.
//

/*
 You are given a string s that consists of lower case English letters and brackets.

 Reverse the strings in each pair of matching parentheses, starting from the innermost one.

 Your result should not contain any brackets.

  

 Example 1:

 Input: s = "(abcd)"
 Output: "dcba"
 Example 2:

 Input: s = "(u(love)i)"
 Output: "iloveu"
 Explanation: The substring "love" is reversed first, then the whole string is reversed.
 Example 3:

 Input: s = "(ed(et(oc))el)"
 Output: "leetcode"
 Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
  

 Constraints:

 1 <= s.length <= 2000
 s only contains lower case English characters and parentheses.
 It is guaranteed that all parentheses are balanced.
 */


#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution{
public:
    
    string reverse_parenthesis( string & s){
        
        long n = s.size();
        
        vector<int> pair(n);
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            if( s[i] == '('){
                st.push(i);
            }
            else{
                if( s[i] == ')'){
                    int j = st.top(); st.pop();
                    
                    pair[i] = j;
                    pair[j] = i;
                    
                    
                }
            }
        }
        
        string res;
        int i = 0 , dir = 1;
        
        while( i >= 0 && i < n){
            
            if( s[i] == '(' || s[i] == ')'){
                i = pair[i];
                dir = -dir;
            }
            else{
                
                res += s[i];
            }
            i += dir;
        }
     
        return res;
        
    }
};
int main(){
    string s;
    cin>>s;
    
    Solution S;
    
    cout<<S.reverse_parenthesis(s)<<endl;
    return 0;
}
