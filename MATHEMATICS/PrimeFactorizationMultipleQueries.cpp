/*

Given a number N, print all its unique prime factors and their exponents in N.

Input Format
The first line of the input contains a single integer T
 denoting the number of test cases.

The description of T test cases follows.

Each test case contains a single integer N in a separate line.

Output Format
For each test case, for each prime factor of the number N
 in that test case, output two space separated integers: the prime factor and its power in 
N.

Prime factors should be printed in increasing order.

Constraints
1≤T≤10^5

2≤N≤10^6

Example
Input
2
100
35
Output
2 2
5 2
5 1
7 1

*/


#include <bits/stdc++.h>
using namespace std;

vector<int>SPF(1000001,-1);
vector<int>Prime(1000001,1);


void preCompute()
{
	Prime[0] = 0;
	Prime[1] = 0;
	SPF[0] = 1;
	SPF[1] = 1;
	for(int i=2;i<1000001;i++)
	{
		if(Prime[i] == 1)
		{
			SPF[i] = i;
			for(int j=i;1ll*i*j < 1000001;j++)
			{
				if(Prime[i*j] == 1)
				{
					SPF[i*j] = i;
					Prime[i*j] = 0;
				}
				
			}
		}
	}
	

}
void Res(int N)
{
	if(N == 1)
		return;
	if(N == 2)
	{
		cout<<"2 1\n";
		return;
	}
	int curr_factor = SPF[N];
	int count = 1;
	while(N > 1)
	{
		N = N/SPF[N];
		if(curr_factor == SPF[N])
		{
			count++;
			continue;
		}
		cout<<curr_factor<<" "<<count<<endl;
		curr_factor = SPF[N];
		count = 1;
	}
}
int main()
{
	preCompute();
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		Res(N);
	}
}