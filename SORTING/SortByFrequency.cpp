/**
 *
 * Given an integer array nums, sort the array according to frequency of elements. 
 * That is elements that have higher frequency come first. 
 * If frequencies of two elements are same, then smaller number comes first.
 * 
 * 1 <= T <= 70
 * 1 <= N <= 130
 * 1 <= nums[i] <= 60
 * 
 * IN : 
 * 2
 * 5
 * 5 5 4 6 4 
 * 5
 * 9 9 9 2 5
 * OP : 
 * 4 4 5 5 6
 * 9 9 9 2 5
 * 
*/
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> X,pair<int,int> Y)
{
	if(X.second != Y.second)
	{
		return X.second > Y.second;
	}
	if(X.first != Y.first)
	{
		return X.first < Y.first;
	}
	return false;
}
int main() {
    // your code goes here
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int Freq[61] = {0};
		vector<int>A(N,0);
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			
		}
		for(int i=0;i<N;i++)
		{
			Freq[A[i]]++;
		}
		vector<pair<int,int>>VEC;
		for(int i=0;i<N;i++)
		{
			VEC.push_back({A[i],Freq[A[i]]});
		}
			
		// }
		sort(VEC.begin(),VEC.end(),cmp);
		for(int i=0;i<VEC.size();i++)
			cout<<VEC[i].first<<" ";
		cout<<endl;
	}
    return 0;
}