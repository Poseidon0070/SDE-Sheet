// Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int k{1};
        int n = v.size();
        int i{1},j{1};
        while(i < n){
            if(v[i] != v[i-1]){
                k++;
                v[j++] = v[i];
            }
            i++;
        }
        return k;
    }
};