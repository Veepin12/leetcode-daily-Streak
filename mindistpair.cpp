#include <iostream>
using namespace std;
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
       
    int i = 0, j = 0;
    int ans = 0;
    int n = nums1.size(), m = nums2.size();

    while (i < n && j < m) {
        if (nums1[i] <= nums2[j]) {
            ans = max(ans, j - i);
            j++;
        } else {
            i++;
            // j must be at least i (constraint: i <= j)
            if (j < i) j = i;
        }
    }
    return ans;
}
};

int main() {
    // Example 1
    Solution S;
    vector<int> n1 = {55,30,5,4,2}, n2 = {100,20,10,10,5};
    cout << S.maxDistance(n1, n2) << "\n"; // 2

    // Example 2
    
   
}
        
 