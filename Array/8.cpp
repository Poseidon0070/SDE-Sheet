// Set Matrix Zeroes
// https://leetcode.com/problems/set-matrix-zeroes/description/
class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        bool row0{},col0{};
        for(int i{};i<n;i++) if(v[i][0] == 0) row0 = 1;
        for(int i{};i<m;i++) if(v[0][i] == 0) col0 = 1;
        for(int i{1};i<n;i++){
            for(int j{1};j<m;j++){
                if(v[i][j] == 0){
                    v[0][j] = 0;
                    v[i][0] = 0;
                }
            }
        }
        for(int i{1};i<n;i++){
            if(v[i][0] == 0){
                for(int j{1};j<m;j++) v[i][j] = 0;
            }
        }
        for(int i{1};i<m;i++){
            if(v[0][i] == 0){
                for(int j{1};j<n;j++) v[j][i] = 0;
            }
        }
        if(row0) for(int i{};i<n;i++) v[i][0] = 0;
        if(col0) for(int i{};i<m;i++) v[0][i] = 0;
    }
};