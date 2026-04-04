
#include <iostream> 
#include <string>
using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;
        
        int n = encodedText.length();
        int cols = n / rows;
        string res = "";
        
        // The originalText starts at each column of the first row (row 0)
        // and moves diagonally: (0, j) -> (1, j+1) -> (2, j+2)...
        for (int j = 0; j < cols; ++j) {
            for (int r = 0, c = j; r < rows && c < cols; ++r, ++c) {
                res += encodedText[r * cols + c];
            }
        }
        
        // Remove trailing spaces as per problem note
        while (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }
        
        return res;
    }
};
int main(){
    Solution S;
    string encodedText="uh dd dd";
    int rows = 3;
    cout<<S.decodeCiphertext(encodedText,rows);
    return 0;



}