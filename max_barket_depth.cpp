#include <iostream>
using namespace std;

class Solution {
    public:

    int bracket( string & s){

        int sol = 0, curr = 0;

        for( char ch : s){
            if( ch == '('){
                curr++;
                sol = max( curr , sol);
            }
            else{
                curr--;
            }
        }
        return sol;
    }

};
int main(){

    string s;
    cin>>s;

    Solution S;

    cout<<S.bracket(s)<<endl;
    return 0;
}