#include <iostream>
using namespace std;
class Solution{
    public:

string generateString(string str1, string str2) {
    int n = str1.size(), m = str2.size();
    string word(n + m - 1, 'a');
    vector<bool> locked(n + m - 1, false);

    // Step 1: Apply all 'T' constraints
    for (int i = 0; i < n; i++) {
        if (str1[i] == 'T') {
            for (int j = 0; j < m; j++) {
                int pos = i + j;
                if (locked[pos]) {
                    if (word[pos] != str2[j]) return ""; // Conflict
                } else {
                    word[pos] = str2[j];
                    locked[pos] = true;
                }
            }
        }
    }

    // Step 2: Validate and fix 'F' constraints
    for (int i = 0; i < n; i++) {
        if (str1[i] == 'F') {
            // Check if window exactly equals str2
            bool matches = true;
            for (int j = 0; j < m; j++) {
                if (word[i + j] != str2[j]) { matches = false; break; }
            }
            if (matches) {
                // Find last unlocked position in window and increment it
                bool fixed = false;
                for (int j = m - 1; j >= 0; j--) {
                    int pos = i + j;
                    if (!locked[pos] && word[pos] < 'z') {
                        word[pos]++;
                        fixed = true;
                        break;
                    }
                }
                if (!fixed) return "";
            }
        }
    }

    return word;
}
};

int main() {
    Solution S;
    cout << S.generateString("TFTF", "ab")  << "\n"; // ababa
    cout << S.generateString("TFTF", "abc") << "\n"; // ""
    cout << S.generateString("T", "a")      << "\n"; // a
    cout << S.generateString("F", "a")      << "\n"; // b
    cout << S.generateString("TT", "ab")    << "\n"; // abb
    return 0;
}

