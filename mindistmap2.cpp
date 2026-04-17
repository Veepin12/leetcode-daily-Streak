#include <iostream>
using namespace std;

class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> lastIndex; // reverse(nums[i]) -> last index i
        int minDist = INT_MAX;

        for (int j = 0; j < (int)nums.size(); j++) {
            int rev = reverseNum(nums[j]);

            // Check if nums[j] matches any earlier stored reverse
            if (lastIndex.count(nums[j])) {
                minDist = min(minDist, j - lastIndex[nums[j]]);
            }

            // Store reverse of current element -> current index (overwrite with latest)
            // Only update if not present OR current index is more recent
            lastIndex[rev] = j; // always overwrite to keep latest index
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};
int main(){
    Solution S;
    vector<int> nums={21,120};
    cout<<S.minMirrorPairDistance(nums);
    return 0;
}