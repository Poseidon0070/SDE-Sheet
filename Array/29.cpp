// Max Value of Equation
// https://leetcode.com/problems/max-value-of-equation/
class tri{
public:
    int a,b,c;
    tri(int x,int y,int z){
        this->a = x;
        this->b = y;
        this->c = z;
    }
};
class X{
public:
    bool operator()(tri &p,tri &q){
        return p.a < q.a;
    }
};
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& v, int k) {
        map<int,vector<int>> mp;
        int n = v.size();
        for(int i{};i<n;i++){
            mp[v[i][0]].push_back(v[i][1]);
        }
        for(auto &i:mp){
            sort(i.second.begin(),i.second.end());
        }
        int dist = 0;
        priority_queue<tri,vector<tri>,X> pq;
        int ans = INT_MIN;
        for(auto &i:mp){
            if(i.second.size() >= 2){
                int m = i.second.size();
                ans = max(ans, i.second[m-1]+i.second[m-2]);
            }
            while(!pq.empty() && (i.first-pq.top().c) > k){
                pq.pop();
            }
            if(!pq.empty()){
                cout << pq.top().a << " " << pq.top().b << " " << pq.top().c << "\n";
                ans = max(ans, pq.top().b+(i.first-pq.top().c)+i.second.back());
            }
            pq.push(tri(i.second.back()-i.first,i.second.back(),i.first));
        }
        return ans;
    }
};