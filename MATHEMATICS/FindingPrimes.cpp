/*

General method to calculate all primes in the range 2......N
 is to start with the number 2
, mark it as prime, and mark all its multiples (excluding itself) as not prime. 
Then, we find the next smallest unmarked number, mark it as prime, and mark all its multiples (excluding itself)
 as not prime. Continuing this way, we get a list of all primes.

Now, let us say that we modified the above algorithm, and start with N instead of 2. 
We mark it as prime, and mark all its factors (excluding itself) as not prime. 
Then we find the next greatest unmarked number, mark it as prime, and mark all its factors 
(excluding itself) as not prime. Continuing this way, we get a list of all primes.

You are given a natural number 
N. You run both the original and modified version of finding primes for numbers from 2..N.

Output the count of integers that are present in both the lists.

Input Format
The first line of the input contains a single integer T
 denoting the number of test cases.

The description of T test cases follows.

Each test case contains a single integer N in a separate line.

Output Format
For each test case, output the count of numbers marked as a prime on a separate line.

Constraints
1≤T≤10^5

2≤N≤10^6

Example
Input
3
2
4
7
Output
1
1
2

*/



#include <bits/stdc++.h>
using namespace std;
vector<int>Prime(1000001,1);
vector<int>CntPrime(1000001,0);
void Seive()
{
	Prime[0] = 0;
	Prime[1] = 1;
	
	for(int i=2;i*i<1000001;i++)
	{
		if(Prime[i] == 1)
		{
			
			for(int j=i ; i*j < 1000001;j++)
			{
				Prime[i*j] = 0;
			}
		}
		
	}
	int val=0;
	for(int i=2;i<1000001;i++)
	{
		if(Prime[i] == 1)
			val++;
		CntPrime[i] = val;
	}
}

int Res(int N)
{
	 
	return CntPrime[N] - CntPrime[N/2];
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
		cout<<Res(N)<<endl;
	}
    return 0;
}