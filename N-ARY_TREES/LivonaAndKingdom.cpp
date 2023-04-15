//https://codeforces.com/problemset/problem/1337/C

#include<bits/stdc++.h>
using namespace std;
pair<int,int>  traverse(vector<vector<int>>&adjList,int root,int parent,vector<pair<int,int>>&Happy,int depth)
{
    if(adjList[root].size() == 1)
    {
        Happy[root] = {depth,0};
        return {depth,1};
    }
    
    Happy[root].first = depth;
    for(int j=0;j<adjList[root].size();j++)
    {
        if(adjList[root][j] != parent)
        {
            pair<int,int> P =  traverse(adjList,adjList[root][j],root,Happy,depth+1);
            Happy[root].second += P.second;
        }
    }

   return {depth , 1 + Happy[root].second};


}
int main()
{
    int N,K;
    cin>>N>>K;
    
    vector<vector<int>>adjList(N+1);

    for(int i=0;i<N-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    adjList[1].push_back(0);

    vector<pair<int,int>>Happiness(N+1);

    traverse(adjList,1,0,Happiness,0);

    vector<int>ANS;
    for(int i=1;i<=N;i++)
    {
        // cout<<Happiness[i].first <<" "<<Happiness[i].second<<endl;
        ANS.push_back(Happiness[i].first - Happiness[i].second);
    }

    sort(ANS.rbegin(),ANS.rend());

    long long int happiness_total = 0;
    for(int i=0;i<K;i++)
        happiness_total += (long long int)ANS[i];
    
    cout<<happiness_total;


}