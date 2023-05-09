/*

You are given an array A of N numbers, output the count of pairs in the array whose sum is divisible by 
4.

Input Format
The first line of the input contains a single integer 
T
 denoting the number of test cases.

The description of 
T
 test cases follows.

The first line of each test case contains a single integer 
N
.

The second line contains 
N
 space-separated integers 
A[0],A[1],...,A[N−1]
 representing the array numbers.

Output Format
For each test case, output the count of pairs in the array whose sum is divisible by 
4 on a separate line.

Constraints
1≤T≤10
1≤N≤10^5
1≤Ai≤10^6

Example
Input
1
5
2 2 1 7 5
Output
3

*/

#include <bits/stdc++.h>
using namespace std;

int Res(vector<int>&A,int N)
{
	if(N < 2)
		return 0;
	vector<int>Rem(4,0);
	for(int i=0;i<N;i++)
		Rem[A[i]%4]++;
	
	int ans = 0;
	if(Rem[0] > 1)
	 ans = (Rem[0] * (Rem[0]-1)) / 2;
	ans += Rem[1] * Rem[3];
	if(Rem[2] > 1)
	ans += (Rem[2] * (Rem[2]-1) )/ 2;
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