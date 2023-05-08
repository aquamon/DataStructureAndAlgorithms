/**
 * Given n non-negative integers representing height h
 *of n bars, where the width of each bar is 1, compute how much water it can trap after raining.
 * 
 * IN : 12 : 0 1 0 2 1 0 1 3 2 1 2 1 
 * OP : 6
 */

#include <bits/stdc++.h>
using namespace std;
long long int Res(vector<long long>&A, long long int N)
{
	vector<long long int> SMax(N,0);
	SMax[N-1] = A[N-1];
	for(long long i=N-2;i>=0;i--)
	{
		SMax[i] = max(SMax[i+1],A[i]);
	}
	
	long long int PMax = A[0];
	long long int ans = 0;
	for(long long int i=1;i<N-1;i++)
	{
		PMax = max(PMax,A[i]);
		long long d_height = min(PMax,SMax[i]);
		if(d_height > A[i])
			ans += (d_height - A[i]);
	}
	return ans;
}

int main() {
    // your code goes here
	long long int N;
	cin>>N;
	vector<long long int>A(N,0);
	for(long long int i=0;i<N;i++)
	{
		cin>>A[i];
	}
	if(N<=2)
		cout<<0;
	else
		cout<<Res(A,N);
    return 0;
}