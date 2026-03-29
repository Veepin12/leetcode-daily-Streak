#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:


    void result(vector<vector<int>> & lcp,int idx){
        
    }
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();
        int m=lcp[0].size();

        string s(n,'.');

        for(int i=0;i<n;i++){


        }

         

        
        
    }
};
int main(){
    Solution S;

    vector<vector<int>> lcp={{4,3,2,2},{4,3,2,1},{2,2,2,1},{1,1,1,1}};
    string  ans = S.findTheString(lcp);

    return 0;
}
