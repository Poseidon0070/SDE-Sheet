vector<pair<int,int>> mov = {{0,1},{1,0},{0,-1},{-1,0}};
void bfs(int i,int j,int n,int m,vector<vector<int>> &vis,vector<vector<char>> &grid){
    queue<pair<int,int>> q;
    q.push({i,j});
    vis[i][j] = 1;
    while(!q.empty()){
        pair<int,int> f = q.front();
        q.pop();
        for(int k{};k<4;k++){
            int nr = f.first+mov[k].first;
            int nc = f.second+mov[k].second;
            if(nr >= 0 && nc >= 0 && nr < n && nc < m && vis[nr][nc] == 0 && grid[nr][nc] == '1'){
                q.push({nr,nc});
                vis[nr][nc] = 1;
            }
        }
    }
}
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c{};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i{};i<n;i++){
            for(int j{};j<m;j++){
                if(vis[i][j] == 0 && grid[i][j] == '1'){
                    c++;
                    bfs(i,j,n,m,vis,grid);
                }
            }
        }
        return c;
    }
};