#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int ,vector<pair<int,int>>> cube;

        for(int a=1;(long long)a*a*a <n; a++){
            for(int b=a;(long long)b*b*b + (long long)a*a*a<=n;b++){
                int val = a*a*a + b*b*b;
                cube[val].push_back({a,b});
            }
        }
        vector<int> ans;
        for(auto& [vals ,pairs] : cube){
            if(pairs.size() >=2){
                ans.push_back(vals);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};
int main(){
    int n=4104;
    Solution S;
    vector<int> res = S.findGoodIntegers(n);

    for(auto ele : res){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}