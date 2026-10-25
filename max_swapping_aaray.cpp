//
//  Equal_subarray_problem.cpp
//  DSA_with_cpp
//
//  Created by Veepin kumar on 25/10/26.
//

/*
 You are given two arrays (A and B) each of size N.

 You want to change A to B. Changing the i-th element of A to i-th element of B costs |Ai – Bi| that is, the absolute difference between two numbers.

 You are also given an integer S denotes maximum cost.

 Find the Maximum length of a subarray of A that can be changed to be the same as the corresponding subarray to B with the cost at most S (maximum cost).

 The subarray of A is a contiguous part of the array A, i. e. the array Ai,Ai+1,…,Aj for some 1≤i≤j≤N.

 Constraints

 1 <= T <= 100 1 <= N <= 10000 1<= S <= 10^9 1 <= Ai, Bi<= 10^9

 Input Format

 The first line contains an integer T, the number of test cases. Then the test cases follow.

 Each test case contains three lines of input.

 First line will contain 2 space separated integers N and S.

 Second line contains N space separated integers A1,A2,…,AN.

 Third line contains N space separated integers B1,B2,…,BN.

 Output Format

 For each test case, output in a single line, the maximum length of a subarray.

 Sample Input

 2 5 6 1 2 3 4 5 4 5 2 4 2 4 10 4 5 2 6 7 5 2 4

 Sample Output

 3 4

 Explanation of Sample

 In the test case 1: subarray (2,3,4) of A can change to (5,2,4). With the cost 4, so the maximum length is 3.

 In the test case 2: subarray (4,5,2,6) of A can change to (7,5,2,4). With the cost 5, so the maximum length is 4.*/


#include <iostream>
#include <vector>
using namespace std;


int main(){
    
    int T;
    cin>>T;
    
    while( T--){
        int N , S;
        cin>>N>>S;
        
        vector<int> A(N);
        for( int i = 0; i < N; i++){
            cin>>A[i];
            
        }
        
        vector<int> B(N);
        
        for( int i = 0; i < N; i++){
            cin>>B[i];
        }
        
        vector<int> C(N);
        for( int i = 0; i < N; i++){
            C[i] = abs(A[i] - B[i]);
            
        }
        int left = 0;
        int current_cost = 0;
        int max_len = 0;
        
        for( int right = 0; right < N; right++){
            current_cost += C[right];
            
            while(  current_cost > S && left <= right ){
                current_cost -= C[left];
                left++;
            }
            
            max_len = max( max_len ,right - left + 1);
            
            
            
        }
        cout<<max_len <<" ";
        
       
    }
    
}
