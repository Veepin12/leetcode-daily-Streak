

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;

        // Determine middle character (odd-frequency char, if any)
        char middle = '\0';
        int half[26] = {0};
        int halfLen = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) middle = char('a' + i);
            half[i] = cnt[i] / 2;
            halfLen += half[i];
        }

        // log(x!) via lgamma, avoids overflow for large x
        auto logFact = [](int x) -> double {
            return (x <= 1) ? 0.0 : lgamma((double)x + 1.0);
        };

        double sumLogFact = 0.0;
        for (int i = 0; i < 26; i++) sumLogFact += logFact(half[i]);
        double totalLogPerm = logFact(halfLen) - sumLogFact;

        const double THRESHOLD = 25.0; // e^25 ≈ 7.2e10, far beyond k's max (1e6)

        // Check if k exceeds total distinct palindromic permutations
        if (totalLogPerm < THRESHOLD) {
            long long totalPerm = (long long)llround(exp(totalLogPerm));
            if (k > totalPerm) return "";
        }
        // else: total is astronomically large, definitely >= k

        // Build k-th permutation of the first half, character by character
        int c[26];
        for (int i = 0; i < 26; i++) c[i] = half[i];
        int L = halfLen;
        double curSumLogFact = sumLogFact;

        string result;
        result.reserve(halfLen);
        long long kk = k;

        for (int pos = 0; pos < halfLen; pos++) {
            double logFactLminus1 = logFact(L - 1);
            for (int ch = 0; ch < 26; ch++) {
                if (c[ch] == 0) continue;

                double logCnt = logFactLminus1 - (curSumLogFact - log((double)c[ch]));
                bool huge = (logCnt > THRESHOLD);
                long long cntVal = huge ? 0 : (long long)llround(exp(logCnt));

                if (huge || kk <= cntVal) {
                    result += char('a' + ch);
                    curSumLogFact -= log((double)c[ch]);
                    c[ch]--;
                    L--;
                    break;
                } else {
                    kk -= cntVal;
                }
            }
        }

        // Assemble palindrome: half + middle + reverse(half)
        string palindrome = result;
        if (middle != '\0') palindrome += middle;
        string mirror = result;
        reverse(mirror.begin(), mirror.end());
        palindrome += mirror;

        return palindrome;
    }
};
using namespace std;
int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;

    Solution S;

    cout<<S.smallestPalindrome( s , k)<<endl;
    return 0;
}