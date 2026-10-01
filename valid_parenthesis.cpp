//
//  Valid_Parenthesis.cpp
//  DSA_with_cpp
//
//  Created by Veepin kumar on 01/10/26.
//

/*
 Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

 An input string is valid if:

 Open brackets must be closed by the same type of brackets.
 Open brackets must be closed in the correct order.
 Every close bracket has a corresponding open bracket of the same type.
  

 Example 1:

 Input: s = "()"

 Output: true

 Example 2:

 Input: s = "()[]{}"

 Output: true

 Example 3:

 Input: s = "(]"

 Output: false

 Example 4:

 Input: s = "([])"

 Output: true

 Example 5:

 Input: s = "([)]"

 Output: false

  

 Constraints:

 1 <= s.length <= 104
 s consists of parentheses only '()[]{}'.
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution{
public:
    
    bool valid_parenthesis( string s){
        
        stack<int> st;
        
        for( char ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                if( st.empty()) return false;
                
                char  top = st.top();
                st.pop();
                
                if((ch == ')' && top != '(') || (ch == '}' && top != '{' )||( ch == ']' && top != '[')) return false;
            }
        }
        return st.empty();
    }
    

};
int main(){
    string s ;
    cin>>s;
    
    Solution S;
    cout<<S.valid_parenthesis(s)<<endl;
    return 0;
}
