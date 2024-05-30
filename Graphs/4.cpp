vector<pair<int,int>> mov = {{0,1},{1,0},{0,-1},{-1,0}};
void bfs(int i,int j,int n,int m,int s,int pre,vector<vector<int>> &vis,vector<vector<int>> &image){
    queue<pair<int,int>> q;
    q.push({i,j});
    vis[i][j] = 1;
    while(!q.empty()){
        pair<int,int> f = q.front();
        q.pop();
        image[f.first][f.second] = s;
        for(int k{};k<4;k++){
            int nr = f.first+mov[k].first;
            int nc = f.second+mov[k].second;
            if(nr >= 0 && nc >= 0 && nr < n && nc < m && vis[nr][nc] == 0 && image[nr][nc] == pre){
                q.push({nr,nc});
                vis[nr][nc] = 1;
            }
        }
    }
}
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        bfs(sr,sc,n,m,color,image[sr][sc],vis,image);
        return image;
    }
};