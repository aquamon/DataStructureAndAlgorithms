/*
Given a 2D matrix matrix, handle multiple queries of the following type: 
Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (x1, y1) and 
lower right corner (x2, y2) for every query.

Input Format

First line contains n and m (dimensions of matrix). Next n lines contains m elements for the matrix. 
Third line contains q denoting number of queries. Next q lines contains x1,y1,x2,y2 where (x1,y1) is the upper 
left corner of defined matrix and (x2,y2) lower right corner.

Output Format

Print q lines each denoting sum of the defined rectangle.

Example 1;

Input

3 3

1 2 3

4 5 6

7 8 9

2

0 0 1 1

1 0 2 2

Output

12

39

Explanation For first query elements we got are 1+2+4+5 = 12 For second query elements are 4+5+6+7+8+9=39

Constraints

1 <= m*n <= 10^6
-1000 <= matrix[i][j] <= 1000
0 <= x1 <= x2 < n
0 <= y1 <= y2 < m
Number of queries will not exceed 10^5.

*/

#include <bits/stdc++.h>
using namespace std;
void modify(vector<vector<int>>&A,int N,int M)
{
	for(int i=0;i<N;i++)
	{
		for(int j=1;j<M;j++)
		{
			A[i][j] += A[i][j-1];
		}
	}
	for(int i=0;i<M;i++)
	{
		for(int j=1;j<N;j++)
		{
			A[j][i] += A[j-1][i];
		}
	}
}
int Res(vector<vector<int>>&A,int N,int M, int x1,int y1,int x2, int y2)
{
	
	
	
	
	int ans = 0;
	ans += A[x2][y2];
	if( (x1-1) >= 0)
	{
		ans -= A[x1-1][y2];
	}
	if( (y1-1) >= 0)
	{
		ans -= A[x2][y1-1];
	}
	if((x1-1) >= 0 && (y1-1) >= 0)
	{
		ans += A[x1-1][y1-1];
	}
	return ans;
}
int main() {
    // your code goes here
	int N,M;
	cin>>N>>M;
	vector<vector<int>>A(N,vector<int>(M,0));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			cin>>A[i][j];
		}
	}
	modify(A,N,M);
	int Q;
	cin>>Q;
	vector<pair<pair<int,int>,pair<int,int>>>q;
	while(Q--)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		pair<pair<int,int>,pair<int,int>> P ;
		P.first.first = x1;
		P.first.second = y1;
		P.second.first = x2;
		P.second.second = y2;
		q.push_back(P);
	}
	for(int i=0;i<q.size();i++)
	{
		int x1,y1,x2,y2;
		x1 = q[i].first.first ;
		y1 = q[i].first.second ;
		x2 = q[i].second.first;
		y2 = q[i].second.second ;
		cout<<Res(A,N,M,x1,y1,x2,y2);
		if(i<q.size()-1)
			cout<<endl;
	}
    return 0;
}