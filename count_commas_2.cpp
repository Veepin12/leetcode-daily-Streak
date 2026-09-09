#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
    public:

    long long count_commas( long long n){

       if( n <= 999) return 0;

      long long totalcommas = 0;
      long long rangeStart = 1000;
      long long rangeEnd = rangeStart * 1000 - 1;

	  int commas = 1;
      
      while( rangeStart <= n){

		long long numbers = (min( n , rangeEnd) - rangeStart + 1);
		totalcommas += 1LL * commas * numbers;

		if( rangeEnd > n) break;


		rangeStart = rangeStart * 1000;
		rangeEnd = rangeStart * 1000 - 1;
		commas++;



      }

	  return totalcommas;


    }

	long long c_c( long long n){

		if( n <= 999) return 0;
		long long rangeStart = 1000;
		long long count = 0;

		while( n >= 1000 ){
			count += ( n - rangeStart ) + 1;
			if( rangeStart >= n / 1000) break;

			rangeStart *= 1000;


		}
		return count;

	}
};
int main(){

	long long n;
	cin>>n;
	Solution S;

	cout<<S.count_commas(n)<<endl;
	cout<<S.c_c(n)<<endl;
    return 0;

}