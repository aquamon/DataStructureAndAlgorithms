/*
Given an array arr of n positive integers and a number k. One can apply a swap operation on the array any number of 
times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] . 
Find the minimum number of swaps required to bring all the numbers less than or equal to k together, i.e. make 
them a contiguous subarray.

Input Format

First line contains 2 integers n and k. Second line contains n array elements.

Example 1

Input

5 3

2 1 5 6 3

Output

1

Explanation

To bring elements 2, 1, 3 together, swap index 2 with 4 (0-based indexing),
 i.e. element arr[2] = 5 with arr[4] = 3 such that final array will be- arr[] = {2, 1, 3, 6, 5}

*/



#include <bits/stdc++.h>
using namespace std;
int Swap(vector<int>&A, int N,int K)
{
	int win_size = 0;
	for(int i=0;i<N;i++)
	{
		if(A[i]<=K)
			win_size++;
	}
	if(win_size == 0 or win_size == 1 or win_size == N or N == 1)
		return 0;
	
	int valid_elements = 0;
	for(int i=0;i<win_size;i++)
	{
		if(A[i]<=K)
			valid_elements++;
	}
	int curr = valid_elements;
	for(int i=win_size;i<N;i++)
	{
		if(A[i] <= K)
			valid_elements++;
		if(A[i-win_size] <= K)
			valid_elements--;
		curr = max(curr,valid_elements);
	}
	return win_size-curr;
}
int main() {
    // your code goes here
	int N,K;
	cin>>N>>K;
	vector<int>A(N,0);
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
	}
	cout<<Swap(A,N,K);
    return 0;
}