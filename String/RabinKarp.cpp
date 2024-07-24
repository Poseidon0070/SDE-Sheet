    int M = 101;
    int pr = 256;
    int strStr(string &s, string &p) {
        int n = s.size();
        int m = p.size();
        if(m > n) return -1;
        int a = 1;
        for(int i{};i<m-1;i++){
            a = (a * pr) % M;
        }
        int hs = 0;
        int hp = 0;
        for(int i{};i<m;i++){
            hs = (hs*pr+s[i])%M;
            hp = (hp*pr+p[i])%M;
        }
        vector<int> ans;
        for(int i{};i<=n-m;i++){
            cout << i << " " << hs << " " << hp << "\n";
            if(hs == hp){
                bool flg = 1;
                for(int j{};j<m;j++){
                    if(p[j] != s[i+j]){
                        flg = 0;
                        break;
                    }
                }
                if(flg){
                    ans.push_back(i);
                }
            }
            if(i < n-m){
                hs = ((((hs-(s[i]*a)%M)*pr)%M)+s[i+m])%M;
                if(hs < 0){
                    hs += M;
                }
            }
        }
        if(!ans.size()) return -1;
        return ans[0];
    }