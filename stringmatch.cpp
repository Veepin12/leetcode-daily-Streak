//
//  stringmatch.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 03/05/26.
//
/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false
*/

#include <iostream>
using namespace std;

class solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s + s).find(goal) != -1;
    }
};
class Solution {
public:
    bool RotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        for (int i = 0; i < s.size(); i++) {
            if (s == goal) return true;
            s = s.substr(1) + s[0];
        }
        return false;
    }
};
int main(){
    string s = "abcde";
    string goal = " cdeab";
    Solution S;
    cout<<S.RotateString(s,goal)<<endl;
    return 0;
}
