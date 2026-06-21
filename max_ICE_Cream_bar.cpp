#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // Since costs[i] is in range [1, 10^5], we can use counting sort
        // Find the maximum cost to determine the size of counting array
        int maxCost = 0;
        for (int cost : costs) {
            if (cost > maxCost) {
                maxCost = cost;
            }
        }
        
        // Create counting array
        vector<int> count(maxCost + 1, 0);
        for (int cost : costs) {
            count[cost]++;
        }
        
        // Greedily buy cheapest ice cream bars first
        int bars = 0;
        int remainingCoins = coins;
        
        for (int cost = 1; cost <= maxCost; ++cost) {
            if (count[cost] > 0) {
                // How many bars of this cost can we buy?
                int canBuy = min(count[cost], remainingCoins / cost);
                bars += canBuy;
                remainingCoins -= canBuy * cost;
                
                // If we can't buy any more, break early
                if (canBuy == 0) break;
            }
        }
        
        return bars;
    }
};
int main(){
    int n ;
    cin>>n;

    vector<int> costs(n);
    for(int i = 0; i < n; i++){
        cin>>costs[i];
    }
    int coins ;
    cin>>coins;
    Solution S;

    cout<<S.maxIceCream(costs , coins)<<endl;
    

    return 0;

}