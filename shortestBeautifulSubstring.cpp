//
//  shortest_and_lexicographically_smallest_string.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 26/08/26.
//
#include <iostream>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        long n = s.size();
        int bestLen = INT_MAX, bestLeft = -1;
        
        int left = 0, ones = 0;
        
        for (int right = 0; right < n; right++) {
            if (s[right] == '1') ones++;
            
            while (ones > k || (ones == k && s[left] == '0')) {
                if (s[left] == '1') ones--;
                left++;
            }
            
            if (ones == k) {
                int curLen = right - left + 1;
                if (curLen < bestLen) {
                    bestLen = curLen;
                    bestLeft = left;
                } else if (curLen == bestLen) {
                    // compare only when lengths tie, avoids extra allocation otherwise
                    if (s.compare(left, curLen, s, bestLeft, curLen) < 0) {
                        bestLeft = left;
                    }
                }
            }
        }
        
        return bestLeft == -1 ? "NULL" : s.substr(bestLeft, bestLen);
    }
};

int main(){
    
    Solution S;
    
    string s;
    cin>>s;
    
    int k;
    cin>>k;
    
    cout<<S.shortestBeautifulSubstring(s,k)<<endl;
    return 0;
}

