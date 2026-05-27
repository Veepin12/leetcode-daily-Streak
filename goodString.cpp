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
    
    int numberOfSpecialChars(string word) {
        int lastLower[26], firstUpper[26];
        fill(lastLower, lastLower+26, -1);
        fill(firstUpper, firstUpper+26, INT_MAX);
        
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (islower(c)) lastLower[c-'a'] = i;
            else if (firstUpper[c-'A'] == INT_MAX) firstUpper[c-'A'] = i;
        }
        
        int count = 0;
        for (int i = 0; i < 26; i++)
            if (lastLower[i] != -1 && firstUpper[i] != INT_MAX && lastLower[i] < firstUpper[i])
                count++;
        return count;
    }
};

int main(){
    Solution S;
    string s;

    getline( cin , s);

    cout<<S.goodstring( s);
    cout<<S.numberOfSpecialChars(s)<<endl;
    return 0;
}