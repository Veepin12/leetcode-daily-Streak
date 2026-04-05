#include <iostream>
using namespace std;
class Solution{
public:

      bool judgecircle(string moves){
        int x=0,y=0;
        for(auto move : moves){
            if(move == 'U') y++;
            else if(move == 'D') y--;
            else if(move == 'R') x++;
            else if(move == 'L') x--;
        }
        return (x==0 && y==0)?1:0;
      }


};
int main(){
    Solution S;
    string moves= "DRLU";
    cout<<S.judgecircle(moves);
    return 0;
}