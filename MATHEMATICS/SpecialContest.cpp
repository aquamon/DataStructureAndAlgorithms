/*

Bob and Alice are participating in a contest. There are N problems in this contest;
 each problem has a unique problem code between 1 and N inclusive. 
 Bob and Alice decided to split the problems to solve between them ― Bob should solve the problems
  whose problem codes are divisible by A but not divisible by B, and Alice should solve the problems
   whose problem codes are divisible by   B but not divisible by A
 (they decided to not solve the problems whose codes are divisible by both A and B).

To win, it is necessary to solve at least K problems. 
You have to tell Bob whether they are going to win or lose.

Input Format

The first line of the input contains a single integer T
 denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains four space-separated integers N,A,B and K.
Constraints

1 ≤ T ≤ 15
1 ≤ K ≤ N ≤ 10^18
1 ≤ A, B ≤ 10^9
Output Format

For each test case, print a single line containing the string 
"Win"
 if they can solve at least K problems or 
"Lose"
 otherwise (without quotes).
Sample Input

1
6 2 3 3

Sample Output

Win

Explanation
Bob is solving the problems with codes 
2 and 4
, Alice is solving the problem with code 
3. Nobody is solving problem 6, since 6
 is divisible by both 2 and 3. Therefore, they can solve 3
 problems and win.

*/


#include <bits/stdc++.h>
using namespace std;
long long lcm(long long A,long long B)
{
	int MAX = max(A,B);
	int MIN = min(A,B);
	
	if(MIN == 1)
		return 1;
	else 
		return A*B/__gcd(A,B);
}
void Res(long long N,long long A,long long B,long long K)
{
	if((N/A + N/B - 2 * (N/lcm(A,B))) >= K)
		cout<<"Win";
	else
		cout<<"Lose";
}
int main() {
    // your code goes here
	int T;
	cin>>T;
	while(T--)
	{
		long long int N,A,B,K;
		cin>>N>>A>>B>>K;
		Res(N,A,B,K);
		cout<<endl;
	}
    return 0;
}