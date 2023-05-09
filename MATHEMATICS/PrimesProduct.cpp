/*

Given two numbers L and R (inclusive) find the product of primes within this range. 
Print the product modulo 10^9+7. If there are no primes in that range you must print 
1.

Input Format

The first line contains a positive integer 
T, denoting number of testcases
The first line of each testcase contains two space - separated integers 
L and R, denoting the range
Constraints

1 ≤ T ≤ 10
1≤ L ≤ R ≤ 10^9
0 ≤ R−L ≤ 10^6

Output Format

Print the product of all primes in the range 
[L,R] modulo 10^9+7
Sample Input

2
1 10
2 20

Sample Output

210
9699690

Sample Explanation

Case 1: 
2∗3∗5∗7=210
Case 2: 
2∗3∗5∗7∗11∗13*17∗19=9699690
Example
Input
2  
1 10  
2 20
Output
210
9699690

*/


#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
vector<long long int>Prime(1000001,1);
vector<long long int>Primes;
void Seive()
{
	Prime[0] = 0;
	Prime[1] = 0;
	for(int i=2; i*i < 1000001;i++)
	{
		if(Prime[i] == 1)
		{
			for(int j = i ; i*j < 1000001; j++)
			{
				Prime[i*j] = 0;
			}
		}
	}
	for(int i=2;i<1000001;i++)
	{
		if(Prime[i] == 1)
			Primes.push_back(i);
	}
}
long long int Res(long long int L,long long int R)
{
	
	vector<int>Nums(R-L+1,1);
	for(int i=0;i<Primes.size();i++)
	{
		int k = ceil(1.0*L/Primes[i]);
		
		for(int j = max(k,2) ; Primes[i]*j <= R; j++)
		{
			Nums[Primes[i]*j - L] = 0;
		}
	}
	
	long long int ans = 1;
	
	for(int i=0;i<R-L+1;i++)
	{
		if(Nums[i] == 0)
			continue;
		else
		{
			long long int X = (i%MOD+L%MOD)%MOD;
			ans = (ans%MOD * X%MOD )%MOD;
		}
	}
	return ans;
}
int main() {
    // your code goes here
	Seive();
	int T;
	cin>>T;
	while(T--)
	{
		long long int L,R;
		cin>>L>>R;
		cout<<Res(L,R)<<endl;
	}
    return 0;
}