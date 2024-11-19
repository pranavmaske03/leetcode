

var sortColors = function(nums) {
    
    let min_index = 0,i = 0,j = 0;

    for(i = 0; i < nums.length-1; i++)
    {
        min_index = i;
        for(j = i+1; j < nums.length; j++)
        {
            if(nums[j] < nums[min_index])
            {
                min_index = j;
            }
        }
        let temp = nums[i];
        nums[i] = nums[min_index];
        nums[min_index] = temp;
    }
    return nums;
};

let main = function()
{
    let arr = [2,0,2,1,1,0];
    console.log(sortColors(arr));
}

main();