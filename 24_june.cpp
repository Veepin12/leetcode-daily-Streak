#include <iostream>
using namespace std;

class Solution {
public:
    int valid_array( int n , int l , int r){

        vector<int> ans;
        ans.clear();

        for( int i = min(l , r); i <= max( l ,r); i++){
            
            ans.push_back(i);
        }
        return ans.size();

    }


    
};

int main(){
    int n , l , r;
    cin>>n>>l>>r;

    Solution S;
    cout<<S.valid_array( n , l, r);
    return 0;
}