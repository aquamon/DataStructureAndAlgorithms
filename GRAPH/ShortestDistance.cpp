// https://www.hackerrank.com/challenges/ctci-bfs-shortest-reach/copy-from/324187617
#include<bits/stdc++.h>
using namespace std;

void BFS(int S,vector<vector<int>>&adj,int N)
{
    queue<pair<int,int>>Q;
    vector<bool> isVis(N+1,false);
    vector<int>ans(N+1,0);
    
    Q.push({S,0});
    ans[S] = 0;
    isVis[S] = true;
  
    
    while(!Q.empty())
    {
        pair<int,int> X = Q.front();
        Q.pop();
        
        for(auto i:adj[X.first])
        {
            if(!isVis[i])
            {
                isVis[i] = true;
                ans[i] = X.second*6 + 6;
                Q.push({i,X.second+1});
            }
        }
    }
    
    for(int i=1;i<N+1;i++)
    {
        
        if(i != S)
        {
            if(ans[i] == 0)
                cout<<-1<<" ";
            else
                cout<<ans[i]<<" ";
        }
    }
    cout<<endl;
}

    void BFS(int S,vector<vector<int>>&adj,int N)
    {
        queue<int>Q;
        vector<bool> isVis(N+1,false);
        vector<int>ans(N+1,0);
        
        Q.push(S);
        ans[S] = 0;
        isVis[S] = true;
    
        
        while(!Q.empty())
        {
            int X = Q.front();
            Q.pop();
            
            for(int i=0;i<adj[X].size();i++)
            {
                
                if(!isVis[adj[X][i]])
                {
                    isVis[adj[X][i]] = true;
                    ans[adj[X][i]] = ans[X]+6;
                    Q.push(adj[X][i]);
                }
            }
        }
        
        for(int i=1;i<N+1;i++)
        {
            
            if(i != S)
            {
                if(ans[i] == 0)
                    cout<<-1<<" ";
                else
                    cout<<ans[i]<<" ";
            }
        }
        cout<<endl;
    }
int main()
{
    int Q;
    cin>>Q;
    while(Q--)
    {
        int N,M;
        cin>>N>>M;
        vector<vector<int>>adj(N+1);
        while(M--)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int src;
        cin>>src;
        
        BFS(src,adj,N);
    }
}
