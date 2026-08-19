#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& nums) {
        // Map to store a bitmask of reserved seats for each row
        unordered_map<int, int> row_map;
                
        for (const auto& seat : nums){
            int row = seat[0];
            int col = seat[1];
            // Set the `col`-th bit to 1
            row_map[row] |= (1 << col);
            
        }
                
                // Assume maximum possible families if all rows were empty (2 families per row)
               
        int max_families = 2 * n;
                
                // Bitmasks for the 3 possible blocks
                // Left block (seats 2,3,4,5): bits 2, 3, 4, 5 -> 60
               
        int left_mask = 60;
                // Right block (seats 6,7,8,9): bits 6, 7, 8, 9 -> 960
                
        int right_mask = 960;
                // Middle block (seats 4,5,6,7): bits 4, 5, 6, 7 -> 240
                
        int middle_mask = 240;
                
        for (auto const& [row, mask] : row_map) {
            // Since this row has reserved seats, subtract the 2 families we initially assumed
            max_families -= 2;
            
            // Check if both left and right blocks are completely free
            if ((mask & left_mask) == 0 && (mask & right_mask) == 0) {
                max_families += 2;
            }
            // Otherwise, check if at least ONE of the blocks (left, middle, or right) is free
            else if ((mask & left_mask) == 0 || (mask & middle_mask) == 0 || (mask & right_mask) == 0) {
                max_families += 1;
            }
            // If none are free, we add 0 families for this row.
            
        }
                
        return max_families;
        
    }
};
int main() {
    Solution S;
    
    int n;
    cout << "Enter number of rows (n): ";
    cin >> n;
    
    int num_reserved;
    cout << "Enter number of reserved seats: ";
    cin >> num_reserved;
    
    vector<vector<int>> nums(num_reserved, vector<int>(2));
    
    cout << "Enter reserved seats (row col): \n";
    for(int i = 0; i < num_reserved; i++) {
        // Fixed indexing to be 0-based for vector assignments
        cin >> nums[i][0] >> nums[i][1]; 
    }
    
    cout << "Maximum families: " << S.maxNumberOfFamilies(n, nums) << "\n";
    
    return 0;
}