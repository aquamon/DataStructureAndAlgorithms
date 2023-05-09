/*

A number is called Happy Prime if there are exactly 
2 distinct prime divisors of it. Find the number of 
Happy Prime numbers between 1 and N, both inclusive.

Input Format

The first line of the input contains a single integer 
T
 denoting the number of test cases.
Each test case contains a single integer N.
Constraints

1 ≤ T ≤ 10^6
1 ≤ N ≤ 10^6
Output Format

For each test case, output the number of Happy Prime numbers between 
1 and N on a separate line.
Sample Input

2
1
10

Sample Output

0
2

Explanation

For testcase 1, there are no numbers between 
1 to 1 which contain exactly 2 distinct prime divisors.
For testcase 2, there are 2 numbers 6 and 10 between 1 to 10
 which contain exactly 2 distinct prime divisors.
Example
Input
2 
1 
10
Output
0
2

*/



#include <bits/stdc++.h>
using namespace std;
vector<int>Prime(1000001,1);
vector<int>SPF(1000001,1);
vector<int>HappyNum(1000001,0);

void SPrimeF()
{
	Prime[0] = 0;
	Prime[1] = 0;
	for(int i=2; i < 1000001 ;i++)
	{
		if(Prime[i] == 1)
		{
			SPF[i] = i;
			for(int j=i ; 1ll*i*j < 1000001 ; j++)
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

bool Happy(int N)
{
	set<int>S;
	while(N > 1)
	{
		S.insert(SPF[N]);
		N = N/SPF[N];	
	}
	
	if(S.size() == 2)
		return true;
	return false;
}

bool Happy2(int N)
{
	int count = 0;
	while(N > 1)
	{
		count++;
		if(count > 2)
			return false;
		int a = SPF[N];
		while(N%a == 0)
		{
			N = N/a;
		}
	}
	if(count == 2)
		return true;
	return false;
}
void NumHappy()
{
	for(int i=6;i<1000001;i++)
	{
		if(Happy2(i))
			HappyNum[i] = HappyNum[i-1] + 1;
		else
			HappyNum[i] = HappyNum[i-1];
	}
}
int Res(int N)
{
	return HappyNum[N];
}
int main() {
    // your code goes here
	SPrimeF();
	NumHappy();
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