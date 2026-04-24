#include <iostream> 
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int left = 0;
        int right = 0;
        int underscore= 0;
        for ( char ch : moves){
            if( ch == 'L')
             {
                left++;

             } 
             else if( ch == 'R'){
                right++;

             }
             else underscore++;
        }
        return abs(left - right) + underscore;
        
    }
};

int main(){
    Solution S;
    cout<<S.furthestDistanceFromOrigin("L_RL__R")<<endl;
    return 0;

}