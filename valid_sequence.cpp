    //
    //  Valid_parenthesis_string_path.cpp
    //  DSA_with_cpp
    //
    //  Created by Veepin kumar on 29/09/26.
    //

    /*
     A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

     It is ().
     It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
     It can be written as (A), where A is a valid parentheses string.
     You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:

     The path starts from the upper left cell (0, 0).
     The path ends at the bottom-right cell (m - 1, n - 1).
     The path only ever moves down or right.
     The resulting parentheses string formed by the path is valid.
     Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.
     */

    #include <iostream>
    using namespace std;


    class Solution {
            vector<vector<vector<int>>> memo;

            bool searchPath(vector<vector<char>>& grid, int row, int col, int balance) {
                if (grid[row][col] == '(') {
                    balance++;
                } else {
                    balance--;
                }

                if (balance < 0) {
                    return false;
                }

                long rows = grid.size();
                long cols = grid[0].size();

                if (row == rows - 1 && col == cols - 1) {
                    return balance == 0;
                }

                if (memo[row][col][balance] != -1) {
                    return memo[row][col][balance];
                }

                bool validPath = false;

                if (row + 1 < rows) {
                    validPath = searchPath(grid, row + 1, col, balance);
                }

                if (!validPath && col + 1 < cols) {
                    validPath = searchPath(grid, row, col + 1, balance);
                }

                return memo[row][col][balance] = validPath;
            }

        public:
            bool hasValidPath(vector<vector<char>>& grid) {
                long rows = grid.size();
                long cols = grid[0].size();

                if (grid[0][0] == ')' || grid[rows - 1][cols - 1] == '(') {
                    return false;
                }

                if ((rows + cols - 1) % 2 != 0) {
                    return false;
                }

                memo.assign(rows, vector<vector<int>>(
                    cols, vector<int>(rows + cols, -1)
                ));

                return searchPath(grid, 0, 0, 0);
            }
    };
    int main(){
        
        int n , m;
        cin>>n>>m;
        
        vector<vector<char>> grid( n , vector<char> ( m ));
        
        for( int i = 0; i < n; i++){
            for( int j = 0; j < m; j++){
                cin>>grid[i][j];
            }
        }
        Solution S;
        
        cout<<S.hasValidPath(grid)<<endl;
        return 0;
    }
