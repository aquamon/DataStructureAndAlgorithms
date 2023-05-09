/*

You are given a natural number N. Output the sum of all its proper divisors.

A Proper Divisor of a natural number is the divisor that is strictly less than that number.

Input Format
The first line of the input contains a single integer T, denoting the number of test cases.

The description of T test cases follows.

Each test case contains a single integer N.

Output Format
For each test case, output the sum of all proper divisors of N on a seperate line.

Constraints
1≤T≤10^2

1≤N≤10^9

Example
Input
3
2
10
20
Output
1
8
22

*/


#include <bits/stdc++.h>
using namespace std;
long long  Res(long long int N)
{
	if(N == 1)
		return 0;
	if(N < 4)
		return 1;
	long long int i=2 , sum = 1;
	for(; i*i < N; i++)
	{
		if(N%i == 0)
		{
			sum += (i + N/i);
		}
	}
	if(i*i == N)
		sum += i;
	return sum;
}
int main() {
    // your code goes here
	  int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		cout<<Res(N)<<endl;
	}
    return 0;
}