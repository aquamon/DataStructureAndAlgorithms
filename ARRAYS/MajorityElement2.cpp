/*

Given an integer array nums of size N, find all elements that appear more than ⌊ N/3 ⌋ times.

You must implement an algorithm that runs in O(N) time and uses constant extra space(Apart from input array size)
 for each testcases. and ⌊ N/3 ⌋ means floor value of N/3.

Input Format

First-line will contain T, number of test cases.
Each test cases contains an integer N, the size of the array and N space-separated integers describing 
elements of the array.
Output Format

Print all elements that appear more than ⌊ N/3 ⌋ times in sorted order for each test cases in new line.
If no such element is found print -1 in that case.
Input 1:

3
3
3 2 3
1
1
2
1 2
Output 1:

3
1
1 2
Constraints:

1<=T<=5
1<=N<=5∗10^4
−10^9<=nums[i]<=10^9

*/



#include <bits/stdc++.h>
using namespace std;
void Res(vector<long long int> &A,long long int N)
{
	long long int C1 = LONG_LONG_MAX, vote1 = 0, C2 = LONG_LONG_MAX, vote2 = 0;
	for(long long int i=0;i<N;i++)
	{
		if(A[i] == C1)
		{
			vote1++;
		}
		else if(A[i] == C2)
		{
			vote2++;
		}
		else if(vote1 == 0)
		{
			C1 = A[i];
			vote1++;
		}
		else if(vote2 == 0)
		{
			C2 = A[i];
			vote2++;
		}
		else
		{
			vote1--;
			vote2--;
		}
	}
	long long int cnt1 = 0, cnt2 = 0;
	for(long long int i=0;i<N;i++)
	{
		if(A[i] == C1)
			cnt1++;
		else if(A[i]==C2)
			cnt2++;
	}
	
	vector<long long int>ans;
	if(cnt1 > N/3)
	{
		ans.push_back(C1);
	}
	 if(cnt2 > N/3)
	 {
		 ans.push_back(C2);
	 }
	if(ans.size() < 1)	
	cout<<-1;
	else
	{
		sort(ans.begin(),ans.end());
		for(int X:ans)
			cout<<X<<" ";
	}
	
	cout<<endl;
}
int main() {
    // your code goes here
	long long int T;
	cin>>T;
	while(T--)
	{
		long long int N;
		cin>>N;
		vector<long long int >A(N,0);
		for(long long int i=0;i<N;i++)
			cin>>A[i];
		Res(A,N);
	}
    return 0;
}