#include <bits/stdc++.h>
using namespace std;
#define int long long

class SegmentTree{
public:
    int n;
    vector<int> v;
    struct node{
        int prop;
        int peaks;
        node(){
            this->prop = 0;
        } 
        node(int x){
            this->prop = x;
        }
    };
    vector<node> seg;

    SegmentTree(int n){
        this->n = n;
        this->seg.resize(4*n);
    }
    SegmentTree(int n,vector<int> v){
        this->n = n;
        this->seg.resize(4*n);
        this->v = v;
    }

    node merge(node a, node b){
        return node(a.prop+b.prop);
    }
    void build(int id,int l,int r){
        if(l == r){
            // cout << v[l] << "\n";
            // cout << isPeak(l,v[l]) << "\n";
            seg[id] = node(isPeak(l,v[l]));
            return ;
        }
        int mid = (l+r) >> 1;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        seg[id] = merge(seg[2*id],seg[2*id+1]);
    }
    void update(int id, int l, int r, int pos, int u){
        if(pos < l || pos > r) return ;
        if(l == r){
            this->v[l] = u;
            seg[id] = node(isPeak(l,u));
            return ;
        }
        int mid = (l+r) >> 1;
        update(2*id,l,mid,pos,u);
        update(2*id+1,mid+1,r,pos,u);
        seg[id] = merge(seg[2*id],seg[2*id+1]);
    }
    node query(int id,int l,int r,int lq,int rq){
        if(lq > r || rq < l){
            return node();
        }
        if(lq <= l && rq >= r){
            return seg[id];
        }
        int mid = ((l+r) >> 1);
        return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
    }
    int isPeak(int x,int val){
        return ((x != 0 && x != n-1 && val > v[x-1] && val > v[x+1]) ? 1 : 0);
    }
};

signed main()
{
    int n,q; cin >> n >> q;
    vector<int> v(n);
    for(auto &temp:v) cin >> temp;
    SegmentTree seg(n,v);
    seg.build(1,0,n-1);
    // for (auto &i:seg.seg){
    //     cout << i.prop << " ";
    // }cout << "\n";
    for(int i{};i<q;i++){
        int type; 
        cin >> type;
        if(type == 2){
            int pos,u; cin >> pos >> u;
            seg.update(1,0,n-1,pos,u);
            if(pos-1 >= 0) seg.update(1,0,n-1,pos-1,seg.v[pos-1]);
            if(pos+1 < n) seg.update(1,0,n-1,pos+1,seg.v[pos+1]);
            // for (auto &i:seg.seg){
            //     cout << i.prop << " ";
            // }cout << "\n";
        }else{
            int l,r; cin >> l >> r;
            l++; r--;
            if(l > r) {
                cout << 0 << " ";
                continue;
            }
            cout << seg.query(1,0,n-1,l,r).prop << " ";
        }
    }
    return 0;
}