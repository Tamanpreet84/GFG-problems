class Solution {
  public:
    vector<int> topoSort(int v, vector<vector<int>>& edges) {
        vector<vector<int>>adj(v);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
        }
        
        vector<int> indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto x: adj[i]) indegree[x]++;
        }
        
        queue<int>q;
        
        for(int i=0;i<v;i++){
            if(indegree[i]==0)q.push(i);
        }
        
        vector<int>ans;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            ans.push_back(f);
            for(int n:adj[f]){
                
                indegree[n]--;
                
                if(indegree[n]==0) q.push(n);
            }
        }
        return ans;
    }
};