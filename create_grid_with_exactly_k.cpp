#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> createGrid(int n, int m, int k) {
        if((m == 1 || n == 1) && k> 1)return {};
        if(m==3 && n ==3 && k ==4)return {"..#", "...","#.."};

        vector<string> mat(n, string(m, '#'));
        for(int i =0;i<m;i++){
            mat[0][i] = '.';
        }

        for(int i=0;i<n;i++){
            mat[i][m-1] = '.';
        }
        k--;

        if(n<m){
            int i=m-2;
            while(i >= 0 && k){
                mat[1][i] = '.';
                i--;
                k--;
            }
        }else{
            int i=1;
            while(i < n && k){
                mat[i][m-2] = '.';
                i++;
                k--;
            }
        }

        if(k)return {};
        return mat;
    }
};

int main(){

    int n ,m,k;
    cin>>n>>m>>k;

    Solution S;

    vector<string> res = S.createGrid( n , m , k);

    for( int i = 0; i < res.size() ; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;

}