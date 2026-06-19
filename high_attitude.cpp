#include <iostream>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int n = gain.size();
        vector<int> prefix_sum(n + 1);
        int sum =  0;
        prefix_sum.push_back(0);

        for( int i = 0; i < n; i++){
            sum += gain[i];
            prefix_sum.push_back(sum);


        }
        int high_attitude = INT_MIN;

        for( int i = 0; i < prefix_sum.size(); i++){
            high_attitude = max( high_attitude , prefix_sum[i]);

        }
        return high_attitude;

    }
};
int main(){
    Solution S ;
    
    int n;
    cin>>n;
    vector<int> gain(n);

    for( int i = 0; i < n ; i++) cin>>gain[i];

    cout<<S.largestAltitude(gain)<<endl;
    

    return 0;
}