#include <iostream>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, right = 0;
        
        for( char ch : s){
            if( ch == '('){
                left = left + 1;
                right = right + 1;
                
            }
            else if( ch == ')'){
                left = left - 1;
                right = right - 1;
            }
            else{
                left = left - 1;
                right = right + 1;
            }
            
            if( right < 0) return false;
            
            if( left < 0){
                left = 0;
            }
        }
        
        return left == 0;

        
        
    }
};

int main(){
    string s;
    cin>>s;

    Solution S;
    cout<<S.checkValidString(s)<<endl;
    return 0;
}