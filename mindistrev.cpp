#include <iostream>
using namespace std;
class Solution {
public:
    int reverse(int n){
         int rev=0;
         while(n>0){
            rev = rev*10 + n%10;
            n /=10;

         }
         return rev;
    }
    int mirrorDistance(int n) {

       

        int diff = abs(n - reverse(n));
        return diff;
        

        
    }
};
int main(){
    Solution S;
    cout<<S.mirrorDistance(25);
    return 0;
}