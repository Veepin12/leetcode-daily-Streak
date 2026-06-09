#include <iostream>
using namespace std;

class Solution {
public:
   
  
bool consecutiveSetBits(int n) {
      
    int pairCount = 0;
    
    // Iterate through the bits of n
    while (n > 0) {
        // Check if the last two bits are both 1 (3 in binary is 11)
        if ((n & 3) == 3) {
            pairCount++;
            
            // Optimization: Break early if we find more than one pair
            if (pairCount > 1) {
                return false;
            }
        }
        // Right shift by 1 to check the next overlapping pair of bits
        n >>= 1;
    }
    
    // Return true only if exactly one pair was found
    return pairCount == 1;
}
};
int main(){
    int n;
    cin>>n;

    Solution S;
    cout<<S.consecutiveSetBits(n)<<endl;
    cout<<endl;
    return 0;
}