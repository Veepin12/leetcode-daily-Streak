//
//  Kth_Smallest_Amount_With_Single_Denomination_Combination.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 21/08/26.
//
/*
 You are given an integer array coins representing coins of different denominations and an integer k.

 You have an infinite number of coins of each denomination. However, you are not allowed to combine coins of different denominations.

 Return the kth smallest amount that can be made using these coins.

  

 Example 1:

 Input: coins = [3,6,9], k = 3

 Output: 9

 Explanation: The given coins can make the following amounts:
 Coin 3 produces multiples of 3: 3, 6, 9, 12, 15, etc.
 Coin 6 produces multiples of 6: 6, 12, 18, 24, etc.
 Coin 9 produces multiples of 9: 9, 18, 27, 36, etc.
 All of the coins combined produce: 3, 6, 9, 12, 15, etc.

 Example 2:

 Input: coins = [5,2], k = 7

 Output: 12

 Explanation: The given coins can make the following amounts:
 Coin 5 produces multiples of 5: 5, 10, 15, 20, etc.
 Coin 2 produces multiples of 2: 2, 4, 6, 8, 10, 12, etc.
 All of the coins combined produce: 2, 4, 5, 6, 8, 10, 12, 14, 15, etc.

  

 Constraints:

 1 <= coins.length <= 15
 1 <= coins[i] <= 25
 1 <= k <= 2 * 109
 coins contains pairwise distinct integers.
 
 */
#include <iostream>
using namespace std;

class Solution {
public:
    
    int gcd( int a , int b){
        if( a == b) return b;
        
        return gcd( a % b , b);
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());

        vector<long long> useful;

        for (int coin : coins) {
            bool redundant = false;

            for (long long prev : useful) {
                if (coin % prev == 0) {
                    redundant = true;
                    break;
                }
            }

            if (!redundant) {
                useful.push_back(coin);
            }
        }

        long long high = useful[0] * 1LL * k;
        long long low = 1;

        int m = useful.size();
        int totalMasks = 1 << m;

        vector<long long> lcms(totalMasks, 1);

        vector<int> signs(totalMasks, 1);

        for (int mask = 1; mask < totalMasks; ++mask) {
            long long currentLCM = 1;
            int bits = 0;

            for (int i = 0; i < m; ++i) {
                if (mask & (1 << i)) {
                    long long g = gcd(currentLCM, useful[i]);

                    currentLCM = currentLCM / g;

                    if (currentLCM > high / useful[i]) {
                        currentLCM = high + 1;
                        break;
                    }

                    currentLCM *= useful[i];
                    ++bits;
                }
            }

            lcms[mask] = currentLCM;

            signs[mask] = (bits % 2 == 1) ? 1 : -1;
        }

        auto count = [&](long long x) {
            long long result = 0;

            for (int mask = 1; mask < totalMasks; ++mask) {
                if (lcms[mask] <= x) {
                    result += signs[mask] * (x / lcms[mask]);
                }
            }

            return result;
        };

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main(){
    int n;
    cin>>n;
    
    vector<int> coins(n);
    for( int i = 0; i < n; i++){
        cin>>coins[i];
    }
    
    Solution S;
    int k;
    cin>>k;
    
    cout<<S.findKthSmallest(coins, k);
}
