// https://www.hackerrank.com/contests/kilobyte-uz-contest1/challenges/trains-and-platforms/problem

//This solution is using merge process 
#include<bits/stdc++.h>
using namespace std;

int Solve(vector<int>&A,vector<int>&B,int N)
{
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    int i=0,j=0,cnt=0,ans=0;
    
    while(i<N and j<N)
    {
        if(A[i] < B[j])
        {
            cnt++;
            i++;
        }
        else
        {
            cnt--;
            j++;
        }
        ans = max(ans,cnt);
    }
    cnt += (N-i);
    ans = max(ans,cnt);
    return ans;

}
int main()
{
    int N;
    cin>>N;
    vector<int>A(N,0);
    vector<int>B(N,0);
    for(int i=0;i<N;i++)
    {
        cin>>A[i]>>B[i];
    }
    
    cout<<Solve(A,B,N);
}