
var removeElement = function(nums, val) {
    
    for(var i = 0,j = 0; i < nums.length; i++)
    {
        if(nums[i] != val)
        {
            nums[j++] = nums[i];
        }
    }
    return j;
};

let main = function() {

    let arr = [1,1,1,2,2,2,4,4,5,6,7,7,8,8,9,9,9];
    let result = removeElement(arr,2)
    console.log(result);
}

main();