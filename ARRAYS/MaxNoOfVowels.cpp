/*
Given a string S and an integer K, print the maximum number of vowel letters in any substring of S with length K.

Vowel letters in English are a, e, i, o, and u.

Input Format

First-line will contain T, number of test cases.
Then Each test case contains string S and an integer K.
Output Format

For each test case, print the maximum number of vowel letter in any substring of S with length K on a separate line.
Sample Input 1

3
abciiidef 3
aeiou 2
leetcode 3
Sample Output 1

3
2
2
Explanation

For S=abciiidef and K=3 The substring "iii" contains 3 vowel letters.
Constraints

1≤T≤10
1≤s.length≤10
5
s consists of lowercase English letters
1≤k≤s.length

*/

#include <bits/stdc++.h>
using namespace std;
bool isVowel(char C)
{
	return (C=='a' or C=='e' or C == 'i' or C=='o' or C=='u');
}
int Res(string S, int K)
{
	int vowel_count = 0;
	for(int i=0;i<K;i++)
	{
		if(isVowel(S[i]))
		{
			vowel_count++;
		}
	}
	int ans = vowel_count;
	for(int i=K;i<S.length();i++)
	{
		
		if(isVowel(S[i]))
		{
			vowel_count++;
		}
		if(isVowel(S[i-K]))
		{
			vowel_count--;
		}
		ans = max(ans,vowel_count);
	}
	return ans;
}
int main() {
    // your code goes here
	int N;
	cin>>N;
	vector<pair<string,int>>A;
	while(N--)
	{
		string S; int K;
		cin>>S>>K;
		A.push_back({S,K});
	}
	for(int i=0;i<A.size();i++)
	{
		cout<<Res(A[i].first,A[i].second)<<endl;
	}
    return 0;
}