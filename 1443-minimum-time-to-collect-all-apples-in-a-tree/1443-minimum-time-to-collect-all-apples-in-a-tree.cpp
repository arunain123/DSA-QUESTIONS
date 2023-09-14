class Solution {
public:
    // { hasapple,sum}
    pair<int,int> dfs(vector<vector<int>>& adj,int node,vector<bool>& hasApple,vector<int>& vis){
        if(adj[node].size()==0){
            if(hasApple[node]==false) return {0,0};
            return {1,0};
        }
        vis[node]=1;
        int sum=0;
        bool flag=hasApple[node];
        for(auto v:adj[node]){
            if(vis[v]==1) continue;
            pair<int,int> temp=dfs(adj,v,hasApple,vis);
            flag=(flag || temp.first);
            sum+=temp.second;
            if(temp.first)sum+=1;
                
        }
        
//         pair<int,int> r={0,0};
        
//         pair<int,int> l=dfs(adj,adj[node][0],hasApple);
//         if(adj[node].size()==2)  r=dfs(adj,adj[node][1],hasApple);
        
//         sum=l.second+r.second;
//         if(l.first) sum+=1;
//         if(r.first) sum+=1;
        
        
        return {flag, sum};
        
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
         vector<int> vis(n,0);
         pair<int,int> a=dfs(adj,0,hasApple,vis);
        return a.second*2;
    }
};