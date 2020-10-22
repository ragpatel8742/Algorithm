void dfs(vector<pair<int,bool>> adj[],vector<bool>& vis,int root, int& ans){
        vis[root] = true;
        for(auto x : adj[root]){
            if(!vis[x.first]){
                if(x.second) ans++;
                dfs(adj,vis,x.first,ans);
            }
        }
    }
    
int minReorder(int n, vector<vector<int>>& connections) {
    vector<pair<int,bool>> adj[n];
    for(auto x : connections){
        int u = x[0];
        int v = x[1];
        adj[u].push_back({v,true});
        adj[v].push_back({u,false});
    }
    vector<bool> vis(n,false);
    int ans = 0;
    dfs(adj,vis,0,ans);
    return ans;
}