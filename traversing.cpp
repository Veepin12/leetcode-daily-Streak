
#include <iostream>
using namespace std;
bool bfs( vector<int> nums, int start){

    int n = nums.size();
    queue<int> qu;
    vector<bool> visited( n, false);
    qu.push(start);
    visited[start] = true;

    while( qu.size() > 0){
        int i = qu.front();
        qu.pop();

        int next = i + nums[i];
        int prev = i - nums[i];

        if( nums[i] == 0) return true;

        if(next >= 0 && next < n && !visited[next]){
            visited[next] = true;
            qu.push(next);
        }

         if(prev >= 0 && prev < n && !visited[prev]){
            visited[prev] = true;
            qu.push(prev);
        }
        
    }
    return false;
}
int main(){
    //Input: arr = [4,2,3,0,3,1,2], start = 0
    //Output: true

    

    vector<int> nums =  {3,0,2,1,2};
    cout<<bfs(nums,2);
    return 0;
}