// Sort Colors
// https://leetcode.com/problems/sort-colors/solutions/3464652/beats-100-c-java-python-javascript-two-pointer-dutch-national-flag-algorithm/
class Solution {
public:
    void sortColors(vector<int>& v) {
        int n = v.size();
        int low = 0;
        int high = n-1;
        int mid = 0;
        while(mid <= high){
            if(v[mid] == 0){
                swap(v[low],v[mid]);
                low++; mid++;
            }else if(v[mid] == 2){
                swap(v[high],v[mid]);
                high--; 
            }else{
                mid++;
            }
        }
    }
};