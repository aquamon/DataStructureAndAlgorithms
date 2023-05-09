/*

Given an array 
A of N positive integers. Print true
 if and only if you can split the entire array into groups of integers, where:

Each group has exactly X number of integers where X ≥ 2
All the integers in each group are equal
Example: 
[1,1,1,2,2,2]
 can be divided into 
2
 groups of 
3
 integers each [1,1,1] and [2,2,2]

Input Format

The first line of input contains a positive integer 
T
 denoting number of testcases.
The first line of each testcase contains a single integer 
N.
The second line of each testcase contains 
N
 space-separated integers 
A[1],A[2],...A[N]
 array numbers.
Constraints

1 ≤ T ≤ 10
1 ≤ N ≤ 10^4
0 ≤ A[i] < 10^4
Output Format

Print 
true
 if its possible to split the array according to given problem statement otherwise 
false.
Sample Input 1:

[1,2,3,4,4,3,2,1]

Sample Output 1:

true

Sample Input 2:

[1,1,1,2,2,2,3,3]

Sample Output 2:

false

Explanation

Sample Input 1: Possible partition [1,1],[2,2],[3,3],[4,4]
Sample Input 2: No possible partition

*/



#include <bits/stdc++.h>
using namespace std;
int GCD(int A,int B)
{
	int MIN = min(A,B);
	int MAX = max(A,B);
	
	if(MIN <= 1)
		return MIN;
	
	while(MAX % MIN != 0)
	{
		int temp = MIN;
		MIN = MAX%MIN;
		MAX = temp;
	}
	return MIN;
		
}

/**
	We needed GCD because
	for [1 1 2 2 3 3 3 3]
	we can group them as [1 1] [2 2] [3 3] [3 3]
	if we had just used highest frequency as K
	then this would result in false.
*/
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
		map<int,int>M;
		for(int i=0;i<N;i++)
		{
			M[A[i]]++;
		}
		int K = INT_MIN;
		for(auto it=M.begin();it != M.end();it++)
		{
			
			K = max(K,it->second);
		}
		
		int gcd = M.begin()->second;
		auto it=M.begin();
		it++;
		for(;it != M.end();it++)
		{
			gcd = GCD(gcd,it->second);
			
		}
		if(gcd == 1)
			cout<<"false"<<endl;
		else
			cout<<"true"<<endl;
		
	}
    return 0;
}