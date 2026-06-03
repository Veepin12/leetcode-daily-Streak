#include <iostream>
using namespace std;



class Solution {
public:
    int lecRec( string & s , string & t, int n , int m){
        if( n == 0 || m == 0) return 0;

        if( s[n - 1] == t[ n - 1])    return 1 + lecRec( s , t , n - 1,m - 1);
        
        else return  max( lecRec( s ,t , n- 1, m) , lecRec( s , t, n , m- 1));
        
    }
    int lcs( string s , string t){
        
        int n = s.length();
        int m = t.length();
        return lecRec(s, t, n , m);
        

        


    }
    
    

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size();

        vector<int> res(n);
        int count = 0;

        for(const auto & ele : wordsContainer){
            

            

        }
        


    }
};
int main(){
    Solution S;

    /*vector<string> wordsContainer = {};
     vector<string>  wordsQuery = {};
     

    vector<int> ans = S.stringIndices(wordsContainer , wordsQuery);

    for( int ele : ans) cout<<ele<<" ";
    cout<<endl;
    */
   cout<<S.lcs( "veepin" , " vee");


    return 0;
}