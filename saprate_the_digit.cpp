#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
class Solution {

public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;
        for (int num : nums) {
            string s = to_string(num);
            for (char c : s)
                answer.push_back(c - '0');
        }
        return answer;
    }
};

int main(){
    Solution S;
    vector<int> nums = {21,10,24,75,95};
    vector<int> res = S.separateDigits(nums);

    for( int i = 0; i< res.size(); i++){
        cout<<res[i]<<" ";
    }
    
    return 0;
}