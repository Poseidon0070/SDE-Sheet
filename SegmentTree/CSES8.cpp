#include <bits/stdc++.h>
using namespace std;
#define int long long

class SegmentTree{
public:
    int n;
    vector<int> v;
    struct node{
        int prop;
        int sz;
        node(){
            this->prop = 0;
            this->sz = 0;
        } 
        node(int x,int sz){
            this->prop = x;
            this->sz = sz;
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
        return node(a.prop+b.prop,a.sz+b.sz);
    }

    void build(int id,int l,int r){
        if(l == r){
            seg[id] = node(v[l],1);
            return ;
        }
        int mid = (l+r) >> 1;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        seg[id] = merge(seg[2*id],seg[2*id+1]);
    }
    // void update(int id, int l, int r, int pos, int u){
    //     if(pos < l || pos > r) return ;
    //     if(l == r){
    //         seg[id] = merge(node(seg[id].prop),node(u));
    //         return ;
    //     }
    //     int mid = (l+r) >> 1;
    //     update(2*id,l,mid,pos,u);
    //     update(2*id+1,mid+1,r,pos,u);
    //     seg[id] = merge(seg[2*id],seg[2*id+1]);
    // }
    int query(int id,int l,int r,int pos){
        if(l == r){
            seg[id].prop = 0;
            seg[id].sz = 0;
            return v[l];
        }
        int mid = (l+r) >> 1;
        int ans;
        if(seg[2*id].sz >= pos){
            ans = query(2*id,l,mid,pos);
        }else{
            ans = query(2*id+1,mid+1,r,pos-seg[2*id].sz);
        }
        seg[id] = merge(seg[2*id],seg[2*id+1]);
        return ans;
    }
};

signed main()
{
    int n,q; cin >> n;
    vector<int> v(n);
    for(auto &temp:v) cin >> temp;
    SegmentTree seg(n,v);
    seg.build(1,0,n-1);
    // for(int i{};i<4*n;i++){
    //     cout << seg.seg[i].prop << "-" << seg.seg[i].sz << " ";
    // }cout << "\n";
    for(int i{};i<n;i++){
        int pos; cin >> pos;
        cout << seg.query(1,0,n-1,pos) << " ";
    }
    return 0;
}