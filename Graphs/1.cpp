class Solution {
  public:
    vector<int> bfsOfGraph(int n, vector<int> v[]) {
        queue<int> q;
        vector<int> ans;
        vector<int> vis(n);
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            ans.push_back(f);
            for(int j:v[f]){
                if(!vis[j]){
                    vis[j] = 1;
                    q.push(j);
                }
            }
        }
        return ans;
    }
};