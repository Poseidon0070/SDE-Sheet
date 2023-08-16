// Subarray Sums Divisible by K
// https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    int subarraysDivByK(vector<int>& v, int k) {
        int n = v.size();
        map<int,int> mp;
        long long s = 0;
        int ans{};
        for(int i{};i<n;i++){
            s += v[i];
            int mod = ((s%k)+k)%k;
            if(mod == 0) ans++;
            cout << mod << " ";
            ans += mp[mod];
            mp[mod]++;
        }
        return ans;
    }
};