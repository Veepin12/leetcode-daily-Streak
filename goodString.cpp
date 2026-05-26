#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
    public:
     
    int goodstring( string & word){
        unordered_set<char> st( word.begin() , word.end());
        int ans = 0;
        for( char c = 'a' ; c <= 'z' ; c++){
            if( st.count(c) && st.count( c - 'a' + 'A')){
                ans++;
            }
        }
        return ans;
     }
};
int main(){
    Solution S;
    string s;

    getline( cin , s);

    cout<<S.goodstring( s);
    return 0;
}