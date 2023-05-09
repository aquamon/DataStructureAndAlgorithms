/*

You are given an array A of N integers.

Count the number of unique prime factors of each element in it.

Input Format
The first line of the input contains a single integer 
T, denoting the number of test cases.

The description of T test cases follows.

The first line of each test case contains a single integer 
N.
The second line of each test case contains 
N space-separated integers A[0],A[1],...,A[N−1].

Output Format
For each test case output a line containing 
N space separated integers denoting the number of prime factors of each of the array element.

Constraints
1≤T≤10

1≤N≤10^5

1≤Ai≤10^6

*/




#include <bits/stdc++.h>
using namespace std;
vector<int>SPF(1000001,-1);
vector<int>Prime(1000001,1);

void Seive()
{
	SPF[0] = 1;
	SPF[1] = 1;
	Prime[0] = 0;
	Prime[1] = 0;
	
	for(int i=2; i < 1000001 ; i++)
	{
		if(Prime[i] == 1)
		{
			SPF[i] = i;
			for(int j=i; 1ll*j*i < 1000001;j++)
			{
				if(Prime[i*j] == 1)
				{
					Prime[i*j] = 0;
					SPF[i*j] = i;
				}
			}
		}
	}
}
int PrimeFactor(int N)
{
	if(N == 1)
		return 1;
	if(N == 2)
		return 2;
	
	int curr = SPF[N];
	int count = 1;
	int ans = 0;
	while(N > 1)
	{
		
		N = N/SPF[N];
		if(SPF[N] == curr)
		{
			count++;
			continue;
		}
		ans++;
		curr = SPF[N];
		count = 1;
	}
	return ans;
	
}
void Res(vector<int> &A,int N)
{
	for(int i=0;i<N;i++)
	{
		cout<<PrimeFactor(A[i])<<" ";
	}
	cout<<endl;
}
int main() {
    // your code goes here
	Seive();
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		vector<int>A(N,0);
		for(int i=0;i<N;i++)
			cin>>A[i];
		
		Res(A,N);
	}
    return 0;
}