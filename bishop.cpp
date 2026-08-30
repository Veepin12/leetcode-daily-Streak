//
//  bishop.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 30/08/26.
//
/*
 There is an 8 x 8 empty chessboard with 1-indexed rows and columns.

 You are given an array source = [sr, sc] representing the starting position of a bishop, and an array target = [tr, tc] representing the target position.

 In one move, the bishop travels one or more squares along a single diagonal direction, staying within the board.

 Return the minimum number of moves for the bishop to land exactly on target. If it can never reach target, return -1.


 */

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    
    int bishop( vector<int> & start , vector<int>  & end){
        
        int sr = start[0];
        int sc = start[1];
        int er = end[0] , ec = end[1];
        
        if( sr == er && sc == ec) return 0;
        if((sr + sc) % 2 != (er + ec) % 2 ) return  -1;
        if( abs(sr - er) == abs(sc - ec)) return 1;
        return 2;
    }
};
int main(){
    
    vector<int> start(2);
    cin>>start[0]>>start[1];
    vector<int> end(2);
    cin>>end[0]>>end[1];
    
    Solution S;
    cout<<S.bishop(start , end)<<endl;
    
    return 0;
}
