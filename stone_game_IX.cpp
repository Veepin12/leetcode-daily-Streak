#include <iostream>
using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n=stones.size();
        int n0=0,n1=0,n2=0;
        for(int i=0;i<n;i++){
            if(stones[i]%3==0)n0++;
            else if(stones[i]%3==1)n1++;
            else n2++;
        }
        n0=n0%2;
        if(n0==1&&!(abs(n2-n1)<3))return true;
        if(n2==0||n1==0||n0==1)return false;
        return true;
    }
};
int main(){

    int n ;
    cin>>n;

    vector<int> stones(n);

    for( int i = 0 ; i < n; i++){
        cin>>stones[i];
    }

    Solution S;
    cout<<S.stoneGameIX(stones);
    return 0;
}