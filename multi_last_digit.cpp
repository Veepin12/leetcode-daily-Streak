//
//  632.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 25/07/26.
//

#include <iostream>
using namespace std;


class Solution {
public:
    int maxProduct(int n) {
        vector<int> ans;
        
        while( n > 0){
            int x = n % 10;
            ans.push_back(x);
            n  = n/ 10;
        }
        sort( ans.begin() , ans.end());
        return ans[ans.size() - 1] * ans[ans.size() - 2];
        

        
       
        
       

    }
};
       

                

                
                
     
        
int main(){
    
    //    int n,m;
    //    cin>>n>>m;
    //
    //    vector<vector<int>> nums( n , vector<int> ( m));
    //
    //    for( int i = 0; i < n; i++){
    //        for(int j = 0; j < m; j++){
    //            cin>>nums[i][j];
    //        }
    //    }
    //
    //    Solution S;
    //
    //    vector<int> ans  = S.smallestRange( nums);
    //
    //
    //    for( int i = 0; i < ans.size() ; i++){
    //        cout<<ans[i];
    //
    //    }
    //    cout<<endl;
    //    return 0;
    //}
    int n;
    cin>>n;
    
    Solution S;
    cout<<S.maxProduct(n)<<endl;
    return 0;
}

