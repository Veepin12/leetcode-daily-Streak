#include <iostream>
#include <unordered_map>
#include <unordered_set>

#include <vector>
using namespace std;
class Solution {
public:
    int mirrorFrequency(string s) {
       
        unordered_map<char,int> freq;
        for( char ch : s) freq[ch]++;
        unordered_set<char> visited;
        int total =0;

        for(auto & [c,cnt] : freq){
            if(visited.count(c)) continue;

            char minnor;
            if(islower(c)){
                minnor='z'-(c-'a');
            }
                else{
                minnor= '9' -(c-'0');
                }
             
            visited.insert(c);
            visited.insert(minnor);
            int minfreq=freq.count(minnor) ?freq[minnor]:0;
            total +=abs(cnt - minfreq);
                
            
        
        }
        return total;
        
    }
};
int main(){
    string s="byby";
    Solution st;

    cout<<st.mirrorFrequency(s);

    return 0;


}