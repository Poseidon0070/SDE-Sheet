
#include <bits/stdc++.h>
#define int long long
using namespace std;

class segmentTree{
public:
    struct node{
        int sum;
        node(){
            this->sum = 0;
        }
    };
    vector<node> seg;
    vector<int> v;
    segmentTree(int n){
        seg.resize(4*n);
    }
    segmentTree(int n,vector<int> v){
        seg.resize(4*n);
        this->v = v;
    }
    node merge(node a, node b){
        node result;
        result.sum = a.sum+b.sum;
        return result;
    }
    void build(int ind,int l,int r){
        if(l == r){
            seg[ind] = node();
            return ;
        }
        int mid = (l+r) >> 1;
        build(2*ind,l,mid);
        build(2*ind+1,mid+1,r);
        seg[ind] = merge(seg[2*ind],seg[2*ind+1]);
    }
    void update(int ind, int l, int r,int pos, int u){
        if(pos < l || pos > r){
            return ;
        }
        if(l == r){
            seg[ind].sum += u;
            return ;
        }
        int mid = (l+r) >> 1;
        update(2*ind,l,mid,pos,u);
        update(2*ind+1,mid+1,r,pos,u);
        seg[ind] = merge(seg[2*ind],seg[2*ind+1]);
    }
    node query(int ind, int l, int r, int lq, int rq, int k){
        if(lq > r || l > rq){
            return node();
        }
        if(lq <= l && r <= rq){
            return seg[ind];
        }
        int mid = (l+r) >> 1;
        node left = query(2*ind,l,mid,lq,rq,k);
        node right = query(2*ind+1,mid+1,r,lq,rq,k);
        return merge(left, right);
    }
};

signed main()
{
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    for(auto &temp:v) cin >> temp;
    segmentTree seg(n);
    for(int i{};i<q;i++){
        int type; 
        cin >> type;
        if(type == 1){
            int l,r,u; cin >> l >> r >> u;
            l--, r--;
            seg.update(1,0,n-1,l,u);
            if(r+1<n) seg.update(1,0,n-1,r+1,-u);
        }else{
            int k; cin >> k;
            k--;
            cout << seg.query(1,0,n-1,0,k,k).sum+v[k] << "\n";
        }
    }
    return 0;
}