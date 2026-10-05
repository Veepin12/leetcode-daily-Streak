#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:

    int valid( string s){
        stack<int> st;
        st.push(0);

        for( char ch : s){
            if( ch == '('){
                st.push(0);

            }else{

                int include = st.top();
                st.pop();


                if( include == 0){
                    int below = st.top();
                    st.pop();

                    st.push( below + 1);
                }
                else{
                    int below = st.top();
                    st.pop();

                    st.push( below  + 2 * include);
                }
            }
        }

        return st.top();

    }


};
int main(){
    string s;
    cin>>s;

    Solution S;
    cout<<S.valid(s)<<endl;
    return 0;
}