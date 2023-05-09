/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.

NOTE : Solve the problem in linear time and in O(1) space?

Input Format

First line of input contains an integer 
N
, the size of the array
Second-line contains 
N
 space-separated integers describing elements of the array
Output Format

Print the element which occurs more than N/2 times .
Constraints:

1≤ N≤ 100
1 ≤nums[i] ≤ 100
Sample Input 0

5

1 2 1 2 1

Sample Output 0

1

*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    // your code goes here
	int N;
	cin>>N;
	vector<int>A(N,0);
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
	}
	int candidate = -1 , vote = 0;
	for(int i=0;i<N;i++)
	{
		if(vote == 0)
		{
			candidate = A[i];
			vote = 1;
		}
		else
		{
			if(A[i] == candidate)
				vote++;
			else
				vote--;
		}
		
	}
	cout<<candidate;
    return 0;
}