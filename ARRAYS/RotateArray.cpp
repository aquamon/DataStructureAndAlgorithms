/**
 * You are given an integer array
 * Rotate the array to the right by K steps, where K is non negative
 * Solve in O(1) space
 * 
 * 7 3
 * 1 2 3 4 5 6 7
 * OP : 5 6 7 1 2 3 4
 * 
 * 
 * rotate 1 steps to the right: [7, 1, 2, 3, 4, 5, 6]
 * rotate 2 steps to the right: [6, 7, 1, 2, 3, 4, 5]
 * rotate 3 steps to the right: [5, 6, 7, 1, 2, 3, 4].
*/

#include <bits/stdc++.h>
using namespace std;
void Res(vector<long long > &A,long long  N,long long  K)
{
	long long  steps = K%N;
	
	reverse(A.begin(),A.begin()+N-steps);
	reverse(A.begin()+N-steps,A.end());
	reverse(A.begin(),A.end());
	
	for(long long  i=0;i<N;i++)
		cout<<A[i]<<" ";
	
}
int main() {
    // your code goes here
	long long  N,K;
	cin>>N>>K;
	vector<long long >A(N);
	for(long long  i=0;i<N;i++)
	{
		cin>>A[i];
	}
	Res(A,N,K);
    return 0;
}