#include  <iostream>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n= words.size();
        if(n == 0 ) return -1;

        int mindist=INT_MAX;
        for(int i=0 ;i<n ;i++){
            if(words[i] == target){
                int left = (i + startIndex) % n;
                int right = (i - startIndex + n ) % n ;
                mindist= min( {left , right , mindist});
                



            }
            

        }
       return (mindist== INT_MAX)? -1: mindist;
    }
};

int main(){
    vector<string> words={"veepin" , "goes" , "to"};
    string target = "veepin";
    int startIndex = 0;
    Solution S;
    cout<<S.closestTarget(words,target,startIndex);
    return 0;
}