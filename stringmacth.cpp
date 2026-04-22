#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n= queries[0].size();
        vector<string> ans;

        for( auto & ele : queries){
            for( auto & ele2 : dictionary){
                 
                    int diff =0;
                    for( int i=0 ;i< n; i++){
                         if( ele[i] != ele2[i]) diff++;
                         if(diff >2) { break;}

                    }
                    if(diff <= 2 ) {
                        ans.push_back(ele);
                        break;
                    }

                 }

                
            }
            return ans;
        }
        
    
};
int main(){
    vector<string> queries={"veepin","aditya"};
    vector<string> dictionary={"chaudhary"};
    Solution S;
    vector<string> res = S.twoEditWords(queries,dictionary);
    for ( auto ele : res){
        cout <<ele<<" ";
    }
    cout<<endl;
    return 0;
}