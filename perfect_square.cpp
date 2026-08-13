#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:

    int perfect( int n){

        int root = sqrt(n);

        if( root * root == n) return 1;

        // using Legendre 3 Square Method ..if n satisfied 4^a * ( 8b + 7) .. return 4;
        while( n % 4 == 0){
            n /= 4;
        }

        if( n % 8 == 7){
            return 4;
        }

        for( int i  = 1; i  * i <= n; i++){
            int root = sqrt( n - i * i);

            if( root * root == ( n - i * i)) {
                return 2;
            }
        }
         return 3;
    }
};

int main(){

    Solution S;

    int n;
    cin>>n;

    cout<<S.perfect(n)<<endl;
    return 0;
}