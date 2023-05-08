/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Input: prices = [3,3,5,0,0,3,1,4]

Output: 6

Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Input: prices = [1,2,3,4,5]

Output: 4

Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.

Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging 

multiple transactions at the same time. You must sell before buying again.


*/

#include <bits/stdc++.h>

using namespace std;
int Res(vector<int>&A, int N)
{
	if(N<2)
		return 0;
	vector<int> SMax(N,0);
	SMax[N-1] = A[N-1];
	for(int i=N-2;i>=0;i--)
	{
		SMax[i] = max(SMax[i+1],A[i]);
	}
	
	int max_till_now = 0;
	int ans = 0;
	int PMin = A[0];
	for(int i=1;i<N;i++)
	{
		max_till_now = max(max_till_now,A[i]-PMin);
		ans = max(ans ,(max_till_now + SMax[i]-A[i]));
		PMin = min(PMin,A[i]);
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