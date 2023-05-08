/*
Given two strings s1 and s2, print True if s2 contains a permutation of s1, or False otherwise.

In other words, print True if one of s1’s permutations is the substring of s2.

Input Format

First-line will contain T,number of test cases.
Then Each test case contains string s1 and string s2.
Output Format

For each test case, print True if s2 contains a permutation of s1 or False otherwise.
Sample Input 1

2
ab
eidbaooo
ab
eidboaoo
Sample Output 1

True
False
Explanation

For s1=ab and s2=eidbaooo,s2 contains one permutation of s1 ("ba").
*/

#include <bits/stdc++.h>
#define MOD 100000000009
using namespace std;
bool check(string X,string Y)
{
	// unsigned long long int ascii_val_x = 0;
	// unsigned long long int ascii_val_y = 0;
	// for(int i=0;i<X.length();i++)
	// {
	// 	ascii_val_x = ((ascii_val_x%MOD) + ((int)X[i]%MOD))%MOD;
	// 	ascii_val_y = ((ascii_val_y%MOD) + ((int)Y[i]%MOD))%MOD;
	// }
	// return (ascii_val_x%MOD == ascii_val_y%MOD);
	//This will not work because different strings can have same sum
	
	
	//sort(X.begin(),X.end());
	//sort(Y.begin(),Y.end());
	//TLE
	
	int buffer[26] = {0};
	for(int i=0;i<X.length();i++)
	{
		buffer[X[i] - 'a']++;
		buffer[Y[i] - 'a']--;
	}
	for(int i=0;i<26;i++)
	{
		if(buffer[i] > 0)
			return false;
	}
	
	return true;
}
bool Res(string S1,string S2)
{
	if(S1.length() > S2.length())
		return false;
	int K = S1.length();
	
	for(int i=0;i<S2.length() - K + 1;i++)
	{
		if(check(S2.substr(i,K),S1))
			return true;
	}
	return false;
}
int main() {
    // your code goes here
	int T;
	cin>>T;
	vector<pair<string,string>>A;
	while(T--)
	{
		string S1,S2;
		cin>>S1>>S2;
		A.push_back({S1,S2});
	}
	for(int i=0;i<A.size();i++)
	{
		Res(A[i].first,A[i].second)?cout<<"True": cout<<"False";
		cout<<endl;
	}
    return 0;
}