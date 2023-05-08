/*
Given an integer array nums, print the maximum difference between two successive elements in its sorted form. 
If the array contains less than two elements, print 0.

You must write an algorithm that runs in linear time and uses linear extra space.

Input Format

First-line will contain T, number of test cases.
Each test cases contains an integer N, the size of the array and N space-separated integers describing elements of the 
array.
Output Format

Print the maximum difference between two successive elements in its sorted form for each test cases in new line.
Input 1:

2
4
3 6 9 1
3
2 6 1
Output 1:

3
4
Constraints:

1<=T<=5
1<=nums.length<=10^5
0<=nums[i]<=10^9
*/

#include <bits/stdc++.h>
using namespace std;
int Res(vector<int>&A,int N)
{
	if(N<2)
		return 0;
	int MIN = INT_MAX;
	int MAX = INT_MIN;
	for(int i=0;i<N;i++)
	{
		MIN = min(MIN,A[i]);
		MAX = max(MAX,A[i]);
	}
	
	if(MIN == MAX)
		return 0;
	int gap = (MAX-MIN)/(N-1);
	
	if((MAX-MIN)%(N-1) != 0)
		gap++;
	
	vector<int>arrMax(N,INT_MIN);
	vector<int>arrMin(N,INT_MAX);
	
	for(int i=0;i<N;i++)
	{
		int bucket = ((A[i]-MIN)/gap)%N;
		arrMax[bucket] = max(arrMax[bucket],A[i]);
		arrMin[bucket] = min(arrMin[bucket],A[i]);
	}
	int ans = INT_MIN;
	int prev = INT_MIN;
	for(int i=0;i<N;i++)
	{
		if(arrMin[i] == INT_MAX)
			continue;
		if(prev == INT_MIN)
			prev = arrMax[i];
		else
		{
			ans = max(ans,(arrMin[i]-prev));
			prev = arrMax[i];
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