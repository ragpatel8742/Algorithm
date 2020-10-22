class Solution {
public:
    set<int> vis;
    vector<int> disc;
    vector<int> low;
    int time;
    vector<vector<int>> ret;
    void dfs(int node,int par,vector<int> adj[]){
        if(vis.count(node))
            return;
        vis.insert(node);
        disc[node] = low[node] = time;
        time++;
        for(int x : adj[node]){
            if(x == par)
                continue;
            if(!vis.count(x)){
                dfs(x,node,adj);
                low[node] = min(low[node],low[x]);
                if(disc[node] < low[x])
                    ret.push_back({node,x});
            }
            else {
                low[node] = min(low[node],disc[x]);
            }
        }
        
    }    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    disc.resize(n + 1);
      low.resize(n + 1);
      time = 0;
      vector<int> graph[n+1];
      for (int i = 0; i < connections.size(); i++) {
         int u = connections[i][0];
         int w = connections[i][1];
         graph[u].push_back(w);
         graph[w].push_back(u);
      }
      dfs(0, -1, graph);
      return ret;
    }
};