/*

You are given a non-negative number N.

Count the number of prime numbers less than or equal to N.

Input Format
The first line of the input contains a single integer 
T denoting the number of test cases.

The description of T test cases follows.

Next T lines each contain a single integer N.

Output Format
For each test case, output the number of prime numbers less than or equal to N
 on a seperate line.

Constraints
1≤T≤10^5

0≤N≤10^6

Example
Input
2
1
10
Output
0
4
*/


#include <bits/stdc++.h>
using namespace std;
vector<int>Prime(1000001,1);
vector<int>Ans(1000001,0);
void Primes()
{
	for(int i=2;i*i<=1000001;i++)
	{
		if(Prime[i])
		{
			//PrimeList.push_back(i);
			for(int j=i; j*i <= 1000001; j++)
			{
				Prime[j*i] = 0;
			}
		}
	}
	int count = 0;
	for(int i=2;i<=1000000;i++)
	{
		if(Prime[i])
		{
			count++;
		}
		Ans[i] = count;
	}
}
int main() {
    // your code goes here
	Primes();
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		scanf("%d",&N);
		
		printf("%d \n",Ans[N]);
	}
    return 0;
}