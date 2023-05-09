/*

You will be given T pairs of natural numbers A and B.

For each pair, output the number of common divisors between the two numbers.

Input Format
The first line of the input contains a single integer T denoting the number of test cases.

The description of T test cases follows.

The first line of each test case contains two integers A and B.

Output Format
For each test case, output the number of common divisors between the given pair on a seperate line.

Constraints
1≤T≤10^2

1≤A,B≤10^9

Example
Input
3
100000 100000
12 24
747794 238336
Output
36
6
2

*/


#include <bits/stdc++.h>
using namespace std;
int Res(int A,int B)
{
	int MIN = min(A,B);
	int MAX = max(A,B);
	int count = 1;
	
	int i=2;
	for(;i*i<MIN;i++)
	{
		if(MIN%i == 0)
		{
			if(MAX%i == 0)
				count++;
			if(MAX%(MIN/i)==0)
				count++;
		}
	}
	if(i*i == MIN)
	{
		if(MAX%i == 0)
			count++;
	}
	if(MAX%MIN == 0)
		count++;
	return count;
}
int main() {
    // your code goes here
	int T;
	cin>>T;
	while(T--)
	{
		int A,B;
		cin>>A>>B;
		cout<<Res(A,B)<<endl;
	}
    return 0;
}