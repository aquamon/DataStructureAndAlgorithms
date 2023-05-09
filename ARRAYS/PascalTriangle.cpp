/*

Given an integer numRows, print the first numRows of Pascal’s triangle.

In Pascal’s triangle, each number is the sum of the two numbers directly above it as shown:



Input Format

A single-line will contain an integer numRows.
Output Format

print the first numRows of Pascal’s triangle.
Input 1:

3
Output 1:

1
1 1
1 2 1
Constraints:

1<=numRows<=30

*/



#include <bits/stdc++.h>
using namespace std;
int main() {
    // your code goes here
	int N;
	cin>>N;
	vector<vector<int>>A(N,vector<int>(N,0));
	for(int i=0;i<N;i++)
	{
		A[i][0] = 1;
		A[i][i] = 1;
		
		for(int j=1;j<i;j++)
		{
			if(i>0)
				A[i][j] = A[i-1][j-1] + A[i-1][j];
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=i;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	
    return 0;
}