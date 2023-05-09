/*
You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1].

You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... } subjected to the following rule:

The first element in s[k] starts with the selection of the element nums[k] of index = k.

The next element in s[k] should be nums[nums[k]], and then nums[nums[nums[k]]], and so on.

We stop adding right before a duplicate element occurs in s[k].

Find_the longest length of a set_ s[k].

Input Format

First line of input contains an integer 
N
, the size of the array
Second-line contains 
N
 space-separated integers describing elements of the array
Output Format

Print the longest length of the set.
Constraints:1 ≤N ≤ 10^5
0≤ nums[i] ≤ N−1
Sample Input 0

6

4 1 5 3 0 2

Sample Output 0

2

Explanation One if the longest set is {nums[0] , nums[4]}.

*/

#include <bits/stdc++.h>
using namespace std;
int Res(vector<int>&A,int N)
{
	if(N==1)
		return 1;
		
	int ans = INT_MIN;
	for(int i=0;i<N;i++)
	{
		
		
		if(A[i] >= 0)
		{
			int cycle = 1;
			int idx = A[i] , val = i;
			while(idx != i)
			{
				int temp = A[idx];
				A[idx] = -1*(val+1);
				val = idx;
				idx = temp;
				cycle++;
			}
			A[idx] = -(val+1);
			ans = max(ans,cycle);
		}
			
	}
	return ans;
}
int main() {
    // your code goes here
	int N;
	cin>>N;
	vector<int>A(N,0);
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
	}
	cout<<Res(A,N);
    return 0;
}