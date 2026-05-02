//
//  rotate_digit.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 02/05/26.
//


/*
 An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.
 
 A number is valid if each digit remains a digit after rotation. For example:
 
 0, 1, and 8 rotate to themselves,
 2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
 6 and 9 rotate to each other, and
 the rest of the numbers do not rotate to any other number and become invalid.
 Given an integer n, return the number of good integers in the range [1, n].
 
 
 
 Example 1:
 
 Input: n = 10
 Output: 4
 Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
 Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
 Example 2:
 
 Input: n = 1
 Output: 0
 Example 3:
 
 Input: n = 2
 Output: 1
 
 
 Constraints:
 
 1 <= n <= 104
 
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (isGood(i)) ans++;
        }

        return ans;
    }

private:
    bool isGood(int num) {
        bool changed = false;  // tracks if at least one digit changes

        while (num > 0) {
            int d = num % 10;
            num /= 10;

            // Invalid digit — rotation produces no valid digit
            if (d == 3 || d == 4 || d == 7) return false;

            // These digits cause the number to change after rotation
            if (d == 2 || d == 5 || d == 6 || d == 9) changed = true;

            // 0, 1, 8 rotate to themselves — no change, but still valid
        }

        return changed;  // good only if the result differs from original
    }
};

int main() {
    Solution S;
    cout << S.rotatedDigits(10) << endl;  // 4
    cout << S.rotatedDigits(1)  << endl;  // 0
    cout << S.rotatedDigits(2)  << endl;  // 1
    return 0;
}
