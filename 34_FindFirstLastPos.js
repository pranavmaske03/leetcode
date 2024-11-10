
var searchRange = function(nums, target) {
  
    let result = [];
    
    if(nums.includes(target)) {
        result.push(nums.indexOf(target));
        for(var i = nums.indexOf(target); i < nums.length; i++) {
            if(nums[i+1] != target) {
                result.push(i);
                return result;
            }
        }
    } else {
        return [-1,-1];
    }
};

let main = function() {

    let  nums = [5,7,7,8,8,10], target = 5;

    result = searchRange(nums,target);
    console.log(result);
}

main();