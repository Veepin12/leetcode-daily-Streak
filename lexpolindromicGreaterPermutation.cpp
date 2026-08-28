#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {// time Complexity O(n)..
                // space =  O(n)..
public:
    vector<string> res;
    
    void per(string ans, string original) { // ist give the memory limit exceeded .. around 340+ testcase passed of 1000+ testcases ...
        if(original == "") {
            res.push_back(ans);
            return;
        }
            
        for(int i = 0; i < original.size(); i++) {
            char ch = original[i];
            string left = original.substr(0, i);
            string right = original.substr(i + 1);
            
            per(ans + ch, left + right);
        }
    }
    
    // Simplified into a boolean checker to verify if a generated permutation is actually a palindrome
    bool isPalindrome(string str) {
        long left = 0, right = str.size() - 1;
        while(left < right) {
            if(str[left] != str[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    
    string lexpolindromicGreaterPermutation(string s, string target) { 
        res.clear(); // Clear previous results in case of multiple test cases
        per("", s);
        
        // Changed unordered_set to set. A set automatically sorts elements lexicographically.
        set<string> st;
        for(string str : res) {
            st.insert(str);
        }
        
        // Since the set is sorted, the FIRST string that meets both conditions is the smallest one.
        for(string str : st) {
            if(str > target && isPalindrome(str)) {
                return str;
            }
        }
        
        return ""; // Return empty string if no valid permutation exists
    }
};


class Solution2 {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> freq(26, 0);
        
        // 1. Count character frequencies
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        // 2. Validate if a palindrome is possible and find the middle character
        string mid_char = "";
        int odd_count = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                odd_count++;
                mid_char += (char)(i + 'a');
            }
        }
        // If there's more than one odd frequency character, a palindrome is impossible
        if (odd_count > 1) return "";
        
        // 3. Keep track of available characters for the left half
        vector<int> avail(26, 0);
        for (int i = 0; i < 26; i++) {
            avail[i] = freq[i] / 2;
        }
        
        // 4. Find how much of target's left half we can match exactly
        int max_i = 0;
        while (max_i < n / 2 && avail[target[max_i] - 'a'] > 0) {
            avail[target[max_i] - 'a']--;
            max_i++;
        }
        
        // 5. If we matched the left half perfectly, check if the resulting palindrome is > target
        if (max_i == n / 2) {
            string L = target.substr(0, n / 2);
            string revL = L;
            reverse(revL.begin(), revL.end());
            string P = L + mid_char + revL;
            if (P > target) return P;
        }
        
        // 6. Backtrack to find the first point where we can put a strictly larger character
        for (int i = max_i; i >= 0; i--) {
            if (i < n / 2) {
                // Try to find the smallest character strictly greater than target[i]
                for (int c = target[i] - 'a' + 1; c < 26; c++) {
                    if (avail[c] > 0) {
                        avail[c]--; // Use this larger character
                        
                        // Construct the left half: matched prefix + new char + remaining smallest chars
                        string L = target.substr(0, i) + (char)(c + 'a');
                        for (int k = 0; k < 26; k++) {
                            L += string(avail[k], k + 'a');
                        }
                        
                        // Mirror it to build the full palindrome
                        string revL = L;
                        reverse(revL.begin(), revL.end());
                        return L + mid_char + revL;
                    }
                }
            }
            
            // If we couldn't place a larger character at index `i`, we backtrack.
            // Give the target's character back to `avail` pool for the `i-1` iteration.
            if (i > 0) {
                avail[target[i - 1] - 'a']++;
            }
        }
        
        return ""; // No valid palindrome is strictly greater than the target
    }
};
int main(){

    string s , target;
    cin>>s>>target;

    Solution S;
    Solution2 S2;
    cout<<S.lexpolindromicGreaterPermutation(s , target)<<endl;
    cout<<S2.lexPalindromicPermutation(s , target)<<endl;
    return 0;
}