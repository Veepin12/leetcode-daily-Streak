#include <iostream>
using namespace std;

class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n; i<=1e8; i++) {
            string x = to_string(i);
            int pro = 1;
            for(auto &c: x) {
                pro*=(c-'0');
            }
            if(pro%t==0) return i;
        }
        return 1e9;
    }
};

int main(){

    Solution S;
    int n,t;
    cin>>n>>t;

    cout<<S.smallestNumber( n , t);
    return 0;
}