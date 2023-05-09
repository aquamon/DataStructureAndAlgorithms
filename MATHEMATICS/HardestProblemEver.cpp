/*
A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing
 the order of the remaining elements. For example, the sequence 
 [A,B,D] is a subsequence of [A,B,C,D,E,F]
 obtained after removal of elements 
[C,E,F]. The relation of one sequence being the subsequence of another is a preorder.

There is an array A consisting of N integers. 
Tourist challenges Petr to solve a problem for all possible non-empty subsequences of this array. 
As we all know that an array of size N can have (2N−1)
 number of non empty subsequences. Tourist thought that it would be difficult for 
 him to check Petr output for all possible subsequences so he designed a technique to check Petr output.
  Tourist asked Petr to give him just the value of bitwise OR of all the answers obtained after 
  solving each subsequence.

There is a function Divisors
 which is defined as below:

Divisors(long long int subsequence[])
{
    int count[];//array initialised to 0.
    for(i=0;i<subsequence.length;i++)
    {
        number=subsequence[i];
        for(j=2;j<=number;j++)
        {
            if(number%j==0)
            {
                count[j]++;
                if(count[j]==subsequence.length)
                    return 0;
            }
        }
    }
    return 1;
}
All the 
(2N−1)
 subsequences are passed in the function 
solve :
solve(long long int subsequence[])
{
    return Divisors(subsequence);
}
Petr asks for your help to compute the 
bitwise
 
OR
 of all the answers generated from every subsequence.

Input Format

First line contains 
T testcases.

Then T lines follow each containing a value N (size of array).

Then N integers containing the array elements.

Constraints

1 ≤ T ≤ 10000
1≤ N ≤ 100
1 ≤ A[i] ≤ 10^9
Output Format

Print 
T lines containing the answer
Sample Input 0:

1
2
2 3

Sample Output 0:

1

Explanation 0 :
Divisors(2)=0 
Divisors(3)=0
Divisors(2,3)=1

0 OR 0 OR 1 = 1


*/

#include <bits/stdc++.h>
using namespace std;
int gcd(int A,int B)
{
	if(min(A,B) == 1)
		return 1;
	
	int MAX = max(A,B);
	int MIN = min(A,B);
	
	while(MAX%MIN != 0)
	{
		int tmp = MIN;
		MIN = MAX%MIN;
		MAX = tmp;
	}
	return MIN;
}
int Res(vector<int>&A, int N)
{
	if(N < 2)
		return 0;
	int GCD = gcd(A[0],A[1]);
	for(int i=2;i<N;i++)
	{
		GCD = gcd(GCD,A[i]);
	}
	if(GCD == 1)
		return 1;
	return 0;
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