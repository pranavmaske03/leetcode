

var removeDuplicates = function(nums) {
    
    let i = 0,j = 2;
    for(i = 2; i < nums.length; i++)
    {
        if(nums[i] != nums[j-2])
        {
            nums[j++] = nums[i];
        }
    }
    return j;
};

let main = function()
{
    let nums = [1,1,1,2,2,3]
    console.log(removeDuplicates(nums));
}

main();