/*
Given an array arr[] with n elements , you need to find the sum all sub arrays of array arr. 
Since the sum could be very large print the sum modulo 10^9+7.

Example 1:

Input:

3 1 2 3

Output:

20

Explanation:

All subarrays are [1], [2], [3],[1,2], [2,3], [1,2,3]. Thus total sum is 20.

*/

#include <bits/stdc++.h>
#define M 1000000007
using namespace std;

long long  Sum(vector<long long>&A, long long N)
{
	long long  ans = 0;
	for(long long i=0;i<N;i++)
	{
		
		long long  a =  ((A[i]%M)*((i+1)%M))%M ;
		long long  b =  (N-i);
		long long  c = ((a%M)*(b%M))%M;
		ans = (ans%M + c%M)%M;
	}
	return ans%M;
}
int main() {
    // your code goes here
	long long N;
	cin>>N;
	vector<long long>A(N,0);
	for(long long i=0;i<N;i++)
		cin>>A[i];
	cout<<Sum(A,N);
    return 0;
}