
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class Solution {

public:
    

    bool canBeEqual(string s1, string s2) {
    // Sort even indices (0,2) and odd indices (1,3) separately
    string even1 = {s1[0], s1[2]}, even2 = {s2[0], s2[2]};
    string odd1  = {s1[1], s1[3]}, odd2  = {s2[1], s2[3]};

    sort(even1.begin(), even1.end());
    sort(even2.begin(), even2.end());
    sort(odd1.begin(), odd1.end());
    sort(odd2.begin(), odd2.end());

    return even1 == even2 && odd1 == odd2;
}
        
    

};

int main(){
    Solution S;
    string s1="adcb";
    string s2="abcd";
    cout<<S.canBeEqual(s1,s2);
    return 0;


}