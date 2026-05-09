#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int numLayers = min(m, n) / 2;

        for (int layer = 0; layer < numLayers; ++layer) {
            // 1. Extract elements of the current layer in counter-clockwise order
            vector<int> elements;
            
            // Top row (left to right)
            for (int j = layer; j < n - 1 - layer; ++j) elements.push_back(grid[layer][j]);
            // Right column (top to bottom)
            for (int i = layer; i < m - 1 - layer; ++i) elements.push_back(grid[i][n - 1 - layer]);
            // Bottom row (right to left)
            for (int j = n - 1 - layer; j > layer; --j) elements.push_back(grid[m - 1 - layer][j]);
            // Left column (bottom to top)
            for (int i = m - 1 - layer; i > layer; --i) elements.push_back(grid[i][layer]);

            // 2. Calculate effective rotation
            int numElements = elements.size();
            int netRotation = k % numElements;
            
            // 3. Put elements back into the grid at shifted positions
            int idx = netRotation; // Start from the element that will move to the first position
            
            // Re-fill Top row
            for (int j = layer; j < n - 1 - layer; ++j) {
                grid[layer][j] = elements[idx];
                idx = (idx + 1) % numElements;
            }
            // Re-fill Right column
            for (int i = layer; i < m - 1 - layer; ++i) {
                grid[i][n - 1 - layer] = elements[idx];
                idx = (idx + 1) % numElements;
            }
            // Re-fill Bottom row
            for (int j = n - 1 - layer; j > layer; --j) {
                grid[m - 1 - layer][j] = elements[idx];
                idx = (idx + 1) % numElements;
            }
            // Re-fill Left column
            for (int i = m - 1 - layer; i > layer; --i) {
                grid[i][layer] = elements[idx];
                idx = (idx + 1) % numElements;
            }
        }

        return grid;
    }
};
int main(){
    Solution S;
    vector<vector<int>> grid = {{1,1,1,1},{1,2,2,2},{1,1,1,1},{2,2,2,2}};
    int k;
    cin>>k;

    vector<vector<int>> ans =  S.rotateGrid(grid,k);

    for( auto row : ans){
        for( auto ele : row){
            cout<<ele << " ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}