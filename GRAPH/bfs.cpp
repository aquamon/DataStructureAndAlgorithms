class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    //v is the total no. of nodes here.
    //so we assume source as node - '0'
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int>Q;
        vector<bool>isVisited(V,false);
        Q.push(0);
        isVisited[0] = true;
        vector<int>ans;
        while(!Q.empty())
        {
            int X = Q.front();
            Q.pop();
            
            ans.push_back(X);
            
           
            for(auto i:adj[X])
            {
              if(!isVisited[i])
              {
                  isVisited[i] = true;
                  Q.push(i);
              }
            }
            
        }
        return ans;
    }


    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int>Q;
        vector<bool>isVisited(V,false);
        Q.push(0);
        isVisited[0] = true;
        vector<int>ans;
        while(!Q.empty())
        {
            int X = Q.front();
            Q.pop();
            
            ans.push_back(X);
            
           
            for(int i=0;i<adj[X].size();i++)
            {
              if(!isVisited[adj[X][i]])
              {
                  isVisited[adj[X][i]] = true;
                  Q.push(adj[X][i]);
              }
            }
            
        }
        return ans;
    }
};