class DSU{
public:
    int n;
    vector<int> par;
    vector<int> rank;


    DSU(int n){
        this->n = n;
        par.resize(n);
        rank.resize(n);
        for(int i{};i<n;i++){
            par[i] = i;
            rank[i] = 1;
        }
    }


    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }


    void merge(int x,int y){
        int rep_x = find(x);
        int rep_y = find(y);
        if(rep_x == rep_y) return ;
        if(rank[rep_x] > rank[rep_y]){
            par[rep_y] = rep_x;
        }else if(rank[rep_x] < rank[rep_y]){
            par[rep_x] = rep_y;
        }else{
            par[rep_y] = rep_x;
            rank[rep_x]++;
        }
    }
};