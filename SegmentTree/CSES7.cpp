#include <bits/stdc++.h>
using namespace std;
#define int long long

class SegmentTree{
public:
    int n;
    vector<int> v;
    struct node{
        int prop;
        int ind;
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
        this->seg.resize(4*n,-1);
    }
    SegmentTree(int n,vector<int> v){
        this->n = n;
        this->seg.resize(4*n,-1);
        this->v = v;
    }

    node merge(node a, node b){
        return node(max(a.prop,b.prop));
    }
    void build(int id,int l,int r){
        if(l == r){
            seg[id] = node(v[l]);
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
            seg[id] = node(u);
            return ;
        }
        int mid = (l+r) >> 1;
        update(2*id,l,mid,pos,u);
        update(2*id+1,mid+1,r,pos,u);
        seg[id] = merge(seg[2*id],seg[2*id+1]);
    }
    int query(int id,int l,int r,int k){
        if(l == r){
            seg[id].prop -= k;
            v[l] -= k;
            return l+1;
        }
        int mid = (l+r) >> 1;
        int ans = 0;
        if(seg[2*id].prop >= k){
            ans = query(2*id,l,mid,k);
        }else if(seg[2*id+1].prop >= k){
            ans = query(2*id+1,mid+1,r,k);
        } 
        seg[id] = merge(seg[2*id], seg[2*id+1]);
        return ans;
    }
};

signed main()
{
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    for(auto &temp:v) cin >> temp;
    SegmentTree seg(n,v);
    seg.build(1,0,n-1);
    // cout << seg.seg[1].prop << "\n";
    // for (auto &i:seg.seg){
    //     cout << i.prop << " ";
    // }cout << "\n";
    for(int i{};i<q;i++){
        int x; cin >> x;
        if(seg.seg[1].prop < x) {
            cout << 0 << " ";
            continue;
        }
        cout << seg.query(1,0,n-1,x) << " ";
    }
    return 0;
}