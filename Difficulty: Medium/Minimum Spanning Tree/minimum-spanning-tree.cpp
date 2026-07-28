class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<bool>vi(V,0);
        int sum=0;
        pq.push({0,0});
        
        vector<vector<pair<int,int>>>adj(V);
        
        for(int i=0;i<edges.size();i++){
            int s=edges[i][0];
            int e=edges[i][1];
            int w=edges[i][2];
            
            adj[s].push_back({e,w});
            adj[e].push_back({s,w});
        }
        
        
        
        
        while(!pq.empty()){
            auto f=pq.top();
            pq.pop();
            int w=f.first;
            int node=f.second;
          
            if(vi[node]) continue;
            
            vi[node]=1;
              sum+=w;
            
            
            for(auto it :adj[node]){
                int x=it.first;
                int x_weight=it.second;
                if(!vi[x]){
                    pq.push({x_weight,x});
                }
            }
     
        }
        
       return sum; 
    }
};
