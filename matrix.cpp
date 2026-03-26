#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
     
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        long total=0;

        for(auto row : grid){
            for(auto ele:row){
                total+=ele;
            }
        }

        if(total%2!=0) return false;
        long half=total/2;

        long  prefix=0;
        for(int i=0;i<m-1;i++){ // vertical partition
            for(int v:grid[i]) prefix+=v;
            if(prefix==half) return true;
            


        }
        prefix=0;

        for(int j=0;j<n-1;j++){ //harigonatal Partitions
            for(int i=0;i<m ;i++) prefix+=grid[i][j];
            if(prefix==half) return true;
            
        }


    return false;
        
    }
};
int main(){
    Solution S;
    vector<vector<int>> grid={{23461},{77421}};
    cout<<S.canPartitionGrid(grid)<<endl;
    return 0;
}