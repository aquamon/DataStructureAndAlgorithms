/*
You are given an N∗N
 2D matrix, rotate the matrix by 90 degrees (clockwise).

You have to rotate the Matrix, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.


Sample Input 0

3

1 2 3

4 5 6

7 8 9

Sample Output 0

7 4 1

8 5 2

9 6 3


*/




#include <bits/stdc++.h>
using namespace std;
void swap(int &X,int &Y)
{
	int temp = X;
	X = Y;
	Y = temp;
	return;
}
void ReverseRow(vector<vector<int>> &A,int N)
{
	for(int i=0;i<N;i++)
	{
		reverse(A[i].begin(),A[i].end());
	}
}
void Transpose(vector<vector<int>> &A,int N)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(i==j)
				continue;
			else
				{
				swap(A[i][j],A[j][i]);
			}
		}
	}
}
void Rotate(vector<vector<int>> &A,int N)
{
	Transpose(A,N);
	ReverseRow(A,N);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main() {
    // your code goes here
	int N;
	cin>>N;
	vector<vector<int>>A(N,vector<int>(N,0));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>A[i][j];
		}
	}
	Rotate(A,N);
    return 0;
}