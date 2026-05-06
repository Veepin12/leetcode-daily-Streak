/*for each row i:
    empty = n-1          // next available spot for a stone to settle
    scan j from n-1 to 0:
        if box[i][j] == '*':
            empty = j-1
        elif box[i][j] == '#':
            box[i][j] = '.'
            box[i][empty] = '#'
            empty--

result is n x m matrix
for i in 0..m-1:
    for j in 0..n-1:
        result[j][m-1-i] = box[i][j]
*/
#include <iostream>
using namespace std;

class Solution{
public:

      vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int m = box.size();
    int n = box[0].size();

    // Step 1: Apply gravity (stones fall right)
    for (int i = 0; i < m; i++) {
        int empty = n - 1;
        for (int j = n - 1; j >= 0; j--) {
            if (box[i][j] == '*') {
                empty = j - 1;
            } else if (box[i][j] == '#') {
                box[i][j] = '.';
                box[i][empty--] = '#';
            }
        }
    }

    // Step 2: Rotate 90 degrees clockwise
    vector<vector<char>> res(n, vector<char>(m));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            res[j][m - 1 - i] = box[i][j];

    return res;
}




    
};

int main(){
    Solution S;
    vector<vector<char>> boxGrid = {{'#','.','*','.'},{'#','#','*','.'}};
    vector<vector<char>> ans = S.rotateTheBox(boxGrid);

    for( auto row : ans){
        for( auto ele : row){
            cout<<ele<<" , ";
        }
        cout<<endl;
    }
    cout<<endl;


   return 0;
}