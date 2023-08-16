// Find All Duplicates in an Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& v) {
        int n = v.size();
        vector<int> ans;
        for(int i{};i<n;i++){
            int num = abs(v[i]);
            num--;
            int corrNum = v[num];
            if(corrNum < 0) ans.push_back(num+1);
            v[num] = -v[num];
        }
        return ans;
    }
};