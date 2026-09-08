#include <iostream>
using namespace std;

class Solution {
private :

    string to_bin( int n){

        string s = "";
        while( n > 0){

            s =  (n % 2 == 0 ? '0' : '1') + s;
            n /= 2;
            
        }
        return s;
    }
public:
     string convertDateToBinary(string date) {

        int year = stoi(date.substr(0 , 4));
        int month = stoi(date.substr(5 , 2));
        int day = stoi(date.substr(8 ,  2));

        return to_bin(year) + "-" + to_bin(month) + "-" + to_bin(day);

        
    }
};

int main(){

    Solution S;
    string s;
    cin>>s;

    cout<<S.convertDateToBinary(s);
    return 0;
}