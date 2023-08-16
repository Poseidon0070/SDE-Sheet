//Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/description/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums[0];
        int f = nums[0];
        while(true){
            s = nums[s];
            f = nums[nums[f]];
            if(s == f) {
                break;
            }
        }
        f = nums[0];
        while(f != s){
            f = nums[f];
            s = nums[s];
        }
        return f;
    }
};

// 1 3 4 2 2 
// 1 -> 3 -> 2 -> 4 -> 2 -> 4 -> 2 .....