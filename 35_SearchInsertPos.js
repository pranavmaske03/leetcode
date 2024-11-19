

var searchInsert = function(nums, target) {
  
    let iPos = 0;
    if(nums.includes(target)) {
        return nums.indexOf(target);
    }
    for(var i = 0; i < nums.length; i++) {

        if(nums[i] > target) {
            iPos = i;
            break;
        }
    }
    if(i === nums.length) { 
        iPos = nums.length;
    }
    return iPos;
};


let main = function()
{
    let arr = [1,3,5,6];
    let target = 2;

    let result = searchInsert(arr,target)
    console.log(result);
}

main();