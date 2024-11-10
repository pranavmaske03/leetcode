

var search = function(nums, target) {
    
    return nums.indexOf(target);
};


let main = function() {

    let nums = [4,5,6,7,0,1,2], target = 9;
    let result = search(nums,target);
    
    console.log(result);
}

main();