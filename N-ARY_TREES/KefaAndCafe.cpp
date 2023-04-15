
//https://codeforces.com/problemset/problem/580/C

#include<bits/stdc++.h>
using namespace std;

void getPaths(int &count,vector<vector<int>>&adjList,int curr,int ans,int root,int parent,vector<int>&arr,int M)
{
    if(adjList[root].size() == 1)
    {
        if(arr[root] == 1)
        {
            curr += 1;
            ans = max(ans,curr);
        }
        if(ans <= M)
        {
            count++;
            return;
        }
        
    }

    for(int j=0;j<adjList[root].size();j++)
    {
        if(adjList[root][j] != parent)
        {
            if(arr[root] == 1)
            {
                getPaths(count,adjList,curr+1,max(ans,curr+1),adjList[root][j],root,arr,M);
            }
            else
            {
                getPaths(count,adjList,0,ans,adjList[root][j],root,arr,M);
            }
        }
    }
}
int main()
{
    int N,M;
    cin>>N>>M;
    vector<int>arr(N+1);
    for(int i=1;i<=N;i++)
        cin>>arr[i];
    
    vector<vector<int>>adjList(N+1);
    for(int i=0;i<N-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    adjList[1].push_back(0);

    int count = 0;

    getPaths(count,adjList,0,0,1,0,arr,M);

    cout<<count;

}