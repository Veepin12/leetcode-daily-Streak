#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string add="";
        int n=a.size()-1;
        int m=b.size()-1;
        int carry=0;

        while(n>=0 || m>=0 || carry) {
           
            int sum = carry;

            if(n>=0) sum +=a[n--];
            if(m>=0) sum +=b[m--];

             add =(sum%2)+ '0';
            carry =sum/2;

        }
        reverse(add.begin(),add.end());
        return add;




        
    }
};

int main(){
    Solution S;
    cout<<S.addBinary("0","1");
    return 0;
}