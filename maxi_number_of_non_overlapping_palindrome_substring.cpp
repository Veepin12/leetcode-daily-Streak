

#include <iostream>
using namespace std;
class Solution{
public:

        int maxPalindrome( string s , int k){

            int n = s.size();
            int lastEnd = 0 ;
            int  count = 0;

            for( int center = 0; center < 2 * n; center++){

                int left = center / 2;
                int right = left + center % 2;

                while( left >= 0 && right < n && s[left] == s[right]){

                    if( right - left + 1 >= k){

                        int end = right + 1;

                        if( left >= lastEnd){
                            lastEnd = end;
                            count++;
                        }
                        else{
                            lastEnd = min( lastEnd , end);
                        }

                        break;

                    }
                    left--;
                    right++;
                }
            }
            return count;
        }
};
int main(){

    string s;
    cin>>s;
    int k;
    cin>>k;

    Solution S;
    cout<<S.maxPalindrome(s , k)<<endl;
    return 0;
}