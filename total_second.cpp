#include <iostream>
using namespace std;

class Solution {
public:

    int second( string x , string y){

        auto toSecond = []( string & t){
            int h = stoi(t.substr( 0 ,2));
            int m = stoi(t.substr( 3  , 2));
            int s = stoi(t.substr( 6 , 2));

            return h * 3600 + m * 60 + s ;


        };

        int start = toSecond(x);
        int end = toSecond(y); 

        int diff = abs(start - end);

        return diff;

    }

};
int main(){

    string x;
    cin>>x;

    string y;
    cin>>y;

    Solution S;

    cout<<S.second( x , y)<<endl;

    return 0;
}