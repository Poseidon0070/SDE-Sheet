class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int s,vector<int> &vis,vector<int> adj[],vector<int> &ans){
        vis[s] = 1;
        ans.push_back(s);
        for(auto &j:adj[s]){
            if(vis[j] == 0){
                dfs(j,vis,adj,ans);
            }
        }
    }
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        vector<int> ans;
        vector<int> vis(n);
        dfs(0,vis,adj,ans);
        return ans;
    }
};