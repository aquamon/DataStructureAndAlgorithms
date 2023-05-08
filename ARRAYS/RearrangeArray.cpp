/*
Given an array arr of size N where every element is in the range from 0 to N-1. Rearrange the given array so that arr[i] = j is changed to arr[j] = i.

You must write an algorithm that runs in linear time and uses linear extra space.

Input Format

First-line will contain an integer N, size of array arr.
Second-line will contain N space-separated integers describing elements of the array.
Output Format

Print the given array arr so that arr[i] = j is changed to arr[j] = i.
Input 1:

4
1 3 0 2
Output 1:

2 0 3 1
Input 2:

4
3 2 1 0
Output 2:

3 2 1 0

Constraints:

1<=N<=10^5
0<=arr[i]<=N−1
*/ 


#include <bits/stdc++.h>
using namespace std;
int main() {
    // your code goes here
	long long N;
	cin>>N;
	vector<long long>A(N,0);
	for(long long i=0;i<N;i++)
		cin>>A[i];
	
	for(long long  i=0;i<N;i++)
	{
		// if(A[i] >= 0)
		// {
		// 	int idx = A[i] , val = i;
		// 	while(idx != i)
		// 	{
		// 		int temp = A[idx];
		// 		A[idx] = -1*(val+1);
		// 		val = idx;
		// 		idx = temp;
		// 	}
		// 	A[idx] = -(val+1);
		// }
		long long  old_val = A[i]%N;
		A[old_val] = N*i + A[old_val];
		
	}
	for(long long i=0;i<N;i++)
	{
		// cout<<(-1*A[i])-1<<" ";
		cout<<A[i]/N<<" ";
	}
		
    return 0;
}