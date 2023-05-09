/*

You are given two numbers A and B.

Print two integers 
X and Y where X=GCD(A,B) and Y=LCM(A,B).

Input Format
Input consists of two space separated integers 
A and B.

Output Format
Print two Integers 
X and Y.

Constraints
1≤A,B≤10^9

*/


#include <bits/stdc++.h>
using namespace std;
long long gcd(long long A,long long B)
{
	long long MAX = max(A,B);
	long long MIN = min(A,B);
	
	if(MIN == 1)
		return MAX;
	
	while(MAX%MIN != 0)
	{
		long long temp = MIN;
		MIN = MAX%MIN;
		MAX = temp;
	}
	return MIN;
}
long long int lcm(long long A,long long B)
{
	long long MAX = max(A,B);
	long long MIN = min(A,B);
	
	if(MIN == 1)
		return MAX;
	
	return (A*B)/gcd(A,B);
}
int main() {
    // your code goes here
	long long A,B;
	cin>>A>>B;
	cout<<gcd(A,B)<<" "<<lcm(A,B);
    return 0;
}