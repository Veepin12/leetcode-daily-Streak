#include <iostream>
using namespace std;


vector<vector<int>> product(vector<vector<int>> & grid){
    int n=grid.size();
    int  m=grid[0].size();
    int  size=n*m;
    int mod=12345;

    vector<int> res(size,1);
    // Create Preffix...
    int  prefix=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            long idx=i*m+j;
            res[idx]=prefix;
            prefix=(prefix*grid[i][j])%mod;
        }
    }
    // Create Suffix...
    int suffix;
    for(long i=n-1;i>=0;i--){
        for(long j=m-1;j>=0;j--){
            long idx=i*m+j;
            res[idx]=(res[idx]*suffix)%mod;
            suffix=(suffix*grid[i][j])%mod;
        }
    }

    vector<vector<int>> ans(n,vector<int> (m));

    for(int i=0;i<size;i++){
        ans[i/m][i%m]=res[i];
    }
    return ans;

}
int main(){
    vector<vector<int>> grid={{1,2},{3,4}};

    vector<vector<int>> result=product(grid);

    for(auto row : result){
        for(auto ele : row){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}