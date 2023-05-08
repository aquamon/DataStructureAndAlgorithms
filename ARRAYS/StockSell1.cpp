/**
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * You want to maximize your profit by choosing a single day to buy one stock and choosing a different day 
 * in the future to sell that stock.
 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 * 
 * 6
 * 7 1 5 3 6 4
 * 
 * 5
 * 
 * Buy on day 2 (price = 1) and sell on day 5 (price = 6), 
 * profit = 6-1 = 5. Note that buying on day 2 and selling on day 1 is not 
 * allowed because you must buy before you sell.
 */


#include <bits/stdc++.h>
using namespace std;
int res(vector<int>&A,int N)
{
	if(N<2)
		return 0;
	int PMin = A[0];
	vector<int>SMax(N,0);
	SMax[N-1] = A[N-1];
	for(int i=N-2;i>=0;i--)
	{
		SMax[i] = max(SMax[i+1],A[i]);
	}
	
	int ans = 0;
	for(int i=0;i<N;i++)
	{
		PMin = min(PMin,A[i]);
		ans = max(ans,(SMax[i] - PMin));
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
	cout<<res(A,N);
    return 0;
}