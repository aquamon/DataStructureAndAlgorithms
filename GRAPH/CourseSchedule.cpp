// https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>indegree(V,0);
	    vector<int>ans;
	    
	    for(int i=0;i<V;i++)
	    {
	        for(int j=0;j<adj[i].size();j++)
	        {
	            indegree[adj[i][j]]++;
	        }
	    }
	    queue<int>Q;
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i] == 0)
	            Q.push(i);
	    }
	    
	    while(!Q.empty())
	    {
	        int X = Q.front();
	        Q.pop();
	        ans.push_back(X);
	        
	        for(int i=0;i<adj[X].size();i++)
	        {
	            indegree[adj[X][i]]--;
	            if(indegree[adj[X][i]] == 0)
	                Q.push(adj[X][i]);
	        }
	    }
	    
	    return ans;
	}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];

				for(int i=0;i<prerequisites.size();i++)
				{
					// indegree[prerequisites[i][1]]++;
					adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
				}

				vector<int>ans = topoSort(numCourses,adj);
				if(ans.size() != numCourses)
					ans.clear();
				return ans;
    }
};