#include <bits/stdc++.h>
using namespace std;
long long int Res(vector<long long int>&A , long long int N)
{
	long long int Ans = 0;
	for(long long int i=0;i<N;i++)
	{
		if(i>0)
			A[i] = max(A[i-1],A[i]);
		
		if(A[i] == i)
			Ans +=1;
		
	}
	return Ans;
}
int main() {
    // your code goes here
	long long int N;
	cin>>N;
	vector<long long int>A(N,0);
	for(long long int i=0;i<N;i++)
		cin>>A[i];
	cout<<Res(A,N);
    return 0;
}