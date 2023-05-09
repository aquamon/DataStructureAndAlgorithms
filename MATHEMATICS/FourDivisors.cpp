/*

You are given an array A of N numbers, output the sum of divisors of numbers in an array having exactly 4 divisors.

Input Format

The first line of the input contains a single integer T denoting the number of test cases.
 The description of T test cases follows
The first line of each test case contains a single integer N
The second line contains N space-separated integers 
A[0],A[1],...,A[N−1] array numbers
Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 10^4
0 ≤ A[i] ≤ 10^4
Output Format

For each test case, output the sum on a new line
Sample Input

1
3
21 4 7

Sample Output

32

Explanation

Only 
21 has exactly 4 divisors i.e., 
1,3,7,21. Thus, 1+3+7+21=32

*/

#include <bits/stdc++.h>
using namespace std;
int divisors(int N)
{
	//cout<<"N : "<<N<<endl;
	int count = 0;
	int value = 0;
	for(int i=1;i<sqrt(N);i++)
	{
		if(N%i == 0)
		{
			count += 2;
			value += (i + N/i);
			//cout<<count<<" "<<value<<"\n";
		}
		if(count > 4)
			break;
	}
	if(count == 4)
		return value;
	else
		return 0;
}
int Res(vector<int>&A,int N)
{
	int ans = 0;
	for(int i=0;i<N;i++)
	{
		int val = A[i];
		int sq = sqrt(A[i]);
		if(sq * sq == val or val < 6)
			continue;
		else
		{
			//cout<<"ANS : "<<ans<<endl;
			ans = ans +  divisors(A[i]);
		}
	}
	return ans;
}
int main() {
    // your code goes here
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		vector<int>A(N,0);
		for(int i=0;i<N;i++)
			cin>>A[i];
		
		cout<<Res(A,N)<<endl;
	}
    return 0;
}