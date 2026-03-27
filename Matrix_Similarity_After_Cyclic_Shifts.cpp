#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {

        int rows=mat.size();
        int cols=mat[0].size();

        int shift=(k%cols);

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                 int original=mat[i][j];
                 int shift_max;
                if(i%2==0){
                   
                     shift_max=mat[i][(j+shift)%cols];
                    if(original!=shift_max) return false;
                }
                else{
                    
                     shift_max=mat[i][(j-shift)%cols + cols];
                    if(original!=shift_max) return false;
                }
            }
        }
        return false;
        
    }
};
int main(){
    Solution S;
    vector<vector<int>> mat={{2,2},{2,2}};
    cout<<S.areSimilar(mat,3)<<endl;
    return 0;
}