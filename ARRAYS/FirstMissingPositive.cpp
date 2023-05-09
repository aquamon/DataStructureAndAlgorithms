/*

Given an unsorted integer array nums, print the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space(Apart from input array size) 
for each testcases.

Input Format

First-line will contain T, number of test cases.
Each test cases contains an integer N, the size of the array and N space-separated integers describing 
elements of the array.
Output Format

Print the smallest missing positive integer for each test cases in new line.
Input 1:

3
3
1 2 0
4
3 4 -1 1
5
7 8 9 11 12
Output 1:

3
2
1
Constraints:
1<=T<=5
1<=nums.length<=10^5
−2^31<=nums[i]<=2^31−1

*/


#include <bits/stdc++.h>

using namespace std;
int Res(vector<long long>&A,int N)
{
	A.push_back(-1);
	
	for(int i=0;i<=N;i++)
	{
		
		while(A[i] >= 0 and A[i] <= N and i != A[i])
		{
			if(A[i] == A[A[i]])
				break;
			swap(A[i],A[A[i]]);
			
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		
		if(A[i] == i) 
			continue;
		else
			return i;
		
			
	}
	
}
int main() {
    // your code goes here
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		vector<long long int>A(N,0);
		for(long long  i=0;i<N;i++)
			cin>>A[i];
		cout<<Res(A,N)<<endl;
	}
    return 0;
}