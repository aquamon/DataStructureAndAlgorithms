/*

Given a m x n matrix mat, Print all elements of the matrix mat in spiral order.

Spiral Order of 3 x 3 matrix can found like this.



Input Format

The first line contains two space-separated integers m and n.
Next m lines of input contains n space-separated integers describing the element of matrix mat.
Output Format

Print the spiral order of matrix mat.
Input 1:

3 3
1 2 3
4 5 6
7 8 9
Output 1:

1 2 3 6 9 8 7 4 5
Constraints:

1<=m,n<=10
−100<=mat[i][j]<=100

*/



#include <bits/stdc++.h>
using namespace std;

void Print(vector<vector<int>> &A,int M, int N,int row,int col)
{
	
	if(row >= M or col >= N)
		return;
	
	for(int i=row;i<N;i++)
		cout<<A[row][i]<<" ";
	for(int i=row+1;i<M;i++)
		cout<<A[i][N-1]<<" ";
	if((M-1) != row)
		for(int i=N-2;i>=col;i--)
			cout<<A[M-1][i]<<" ";
	if((N-1) != col)
		for(int i=M-2;i>row;i--)
			cout<<A[i][col]<<" ";
	Print(A,M-1,N-1,row+1,col+1);
	
}
int main() {
    // your code goes here
	int M;int N;
	cin>>M>>N;
	vector<vector<int>>A(M,vector<int>(N,0));
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			cin>>A[i][j];
	
	Print(A,M,N,0,0);
			return 0;
	
}