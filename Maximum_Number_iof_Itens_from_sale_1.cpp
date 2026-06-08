#include <iostream>
using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();
        int m = items[0].size();

        int ams = 0;

        for( int i = 0; i < n; i++){
            for( int j = 0 ; i < m ; j++){


            }
        }


        
    }
};

int main(){
    Solution S;
    vector<vector<int>> items = {{1,2}};
    int budget = 1;
   // Input: items = [[6,2],[2,6],[3,4]], budget = 9

   //  Output: 4

    cout<<S.maximumSaleItems(items , budget)<<endl;

    return 0;
}