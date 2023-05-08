/*
Given a matrix mat with n*m elements , you need to find the sum all sub matrices of the given matrix. 
Since the sum could be very large print the sum modulo 10^9+7.

Input

First Line contains two integers 
n,m. Next n lines contains m elements for the matrix

Output

Required sum of all sub matrices.

Example 1:

Input:

2 2

1 2

3 4

Output:

40

Explanation:

All sub matrices are [[1]], [[2]], [[3]],[[4]], [[1,2]], [[1],[3]], [[2],[4]], [[3,4]], [[1,2],[3,4]]
 Thus total sum is 40.

*/


#include <bits/stdc++.h>
#define M 1000000007
using namespace std;
/*
 for any element A[i,j]
 Its contribution would be (i+1)(j+1) * (N-i)(M-j) * A[i][j]
 Hence the result.
*/
long long res(vector<vector<long long>>&A,long long N,long long MM)
{
	long long ans = 0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<MM;j++)
		{
			long long a = (((i%M+1%M)%M)%M * ((j%M+1%M)%M)%M)%M;
			long long b = (((N-i)%M)*((MM-j)%M))%M;
			long long c = (((a%M)*(b%M))%M * A[i][j]%M)%M;
			ans = ((ans%M) + (c%M))%M;
		}
	}
	
	return ans%M;
}
int main() {
    // your code goes here
	long long N,MM;
	cin>>N>>MM;
	vector<vector<long long>>A(N,vector<long long>(MM,0));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<MM;j++)
		{
			cin>>A[i][j];
		}
	}
	cout<<res(A,N,MM);
    return 0;
}