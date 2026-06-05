#include <iostream>
using namespace std;
class Solution {
public:
    int digitFrequencyScore(int n) {
        string s = to_string(n);
        unordered_map<char , int> mp;
        
       for( int i = 0; i < s.length() ; i++){
        mp[(int)s[i]]++;
       }
            
        
        int ans = 0;
        for( auto ele : mp){
            ans += (int)((ele.first) - 48) * ele.second;
            
        }
        return ans ;
        
    }
};

int main(){
    int n; 
    cin>>n;
    Solution S;
    cout<<S.digitFrequencyScore(n)<<endl;
    return 0;
}