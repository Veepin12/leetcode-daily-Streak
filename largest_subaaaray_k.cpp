#include <iostream>
using namespace  std;

class Solution{
    public:

    int longest_substr( string & s){

        int n = s.length();

        int left = 0;
        int len = 0;

        unordered_map<int ,int> mp;

        for( int i = 0; i < n; i++){
            mp[s[i]]++;

            while( mp[s[i]] > 2){
                mp[s[i]]--;
                left++;
            }
        
        len = max( len , i - left + 1);
        }

        return len;


    }
};


int main(){

    string s;

    cin>>s;


    Solution S;
    cout<<S.longest_substr(s)<<endl;
    return 0;

}