#include <bits/stdc++.h>
using namespace std;

/*
 * LeetCode 3016: Minimum Number of Pushes to Type Word II
 * 
 * PROBLEM:
 * - Given a word with lowercase English letters
 * - Telephone keypad has keys 2-9 (8 keys total)
 * - Each key can be remapped to any letters
 * - To type a letter, we push the key based on its position:
 *   - 1st letter on a key: 1 push
 *   - 2nd letter on a key: 2 pushes
 *   - 3rd letter on a key: 3 pushes
 *   - etc.
 * - Find minimum total pushes needed to type the word
 * 
 * APPROACH: Greedy
 * 1. Count frequency of each character
 * 2. Sort frequencies in descending order
 * 3. Assign most frequent characters to positions requiring fewest pushes
 * 4. Since we have 8 keys:
 *    - Positions 0-7: 1 push (8 characters at 1 push each)
 *    - Positions 8-15: 2 pushes (8 characters at 2 pushes each)
 *    - Positions 16-23: 3 pushes (8 characters at 3 pushes each)
 *    - Positions 24-25: 4 pushes (2 characters at 4 pushes each)
 * 
 * TIME COMPLEXITY: O(n + 26 log 26) = O(n)
 * SPACE COMPLEXITY: O(26) = O(1)
 */

class Solution {
public:
    int minimumPushes(string word) {
        // Count frequency of each character
        int freq[26] = {0};
        for (char c : word) {
            freq[c - 'a']++;
        }
        
        // Sort in descending order (most frequent first)
        sort(freq, freq + 26, greater<int>());
        
        int totalPushes = 0;
        
        // Assign characters to keys optimally
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;
            
            // (i / 8) + 1 determines how many times to push the key
            // i / 8 gives us which "tier" we're in
            int pushCount = (i / 8) + 1;
            totalPushes += freq[i] * pushCount;
        }
        
        return totalPushes;
    }
};

// Alternative solution using vector
class Solution2 {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;
        for (char c : word) {
            freq[c]++;
        }
        
        vector<int> frequencies;
        for (auto& p : freq) {
            frequencies.push_back(p.second);
        }
        
        sort(frequencies.begin(), frequencies.end(), greater<int>());
        
        int totalPushes = 0;
        for (int i = 0; i < frequencies.size(); i++) {
            int pushCount = (i / 8) + 1;
            totalPushes += frequencies[i] * pushCount;
        }
        
        return totalPushes;
    }
};

// Test cases
int main() {
    Solution sol;
    
    cout << "=== LeetCode 3016: Minimum Number of Pushes to Type Word II ===" << endl << endl;
    
    // Test case 1
    string test1 = "abcde";
    cout << "Test 1: word = \"" << test1 << "\"" << endl;
    cout << "Output: " << sol.minimumPushes(test1) << endl;
    cout << "Explanation: Each char appears once, assign to first 5 positions (1 push each)" << endl;
    cout << "Total: 5 * 1 = 5" << endl << endl;
    
    // Test case 2
    string test2 = "xyzxyzxyzxyz";
    cout << "Test 2: word = \"" << test2 << "\"" << endl;
    cout << "Output: " << sol.minimumPushes(test2) << endl;
    cout << "Explanation: x=4, y=4, z=4" << endl;
    cout << "All assigned to 1-push positions: 4*1 + 4*1 + 4*1 = 12" << endl << endl;
    
    // Test case 3: Complex example
    string test3 = "aabbcccccddeeeeaabccd";
    cout << "Test 3: word = \"" << test3 << "\"" << endl;
    cout << "Output: " << sol.minimumPushes(test3) << endl;
    cout << "Explanation: Frequency count and greedy assignment" << endl;
    
    return 0;
}