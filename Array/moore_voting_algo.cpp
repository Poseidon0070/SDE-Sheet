var majorityElement = function(nums) {
    let elm, cnt = 0;
    let n = nums.length;
    for(let i=0;i<n;i++){
        if(cnt == 0){
            cnt = 1;
            elm = nums[i];
        }else if(elm == nums[i]){
            cnt++;
        }else{
            cnt--;
        }
    }
    return elm;
};