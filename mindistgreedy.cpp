#include <iostream>
using namespace std;


class Solution {
public:
    int maxDistance(vector<int>& colors) {

    
        int n = colors.size();
        int res = 0;

        // Fix left end (index 0), scan from right
        for (int j = n - 1; j > 0; j--) {
            if (colors[j] != colors[0]) {
                res = max(res, j);   // distance = j - 0 = j
                break;
            }
        }

        // Fix right end (index n-1), scan from left
        for (int i = 0; i < n - 1; i++) {
            if (colors[i] != colors[n - 1]) {
                res = max(res, n - 1 - i);
                break;
            }
        }

        return res;
    }
};

int main(){
    Solution S;
    vector<int> colors = {1,1,1,6,1,1};
    cout<<S.maxDistance(colors);
    return 0;
}
