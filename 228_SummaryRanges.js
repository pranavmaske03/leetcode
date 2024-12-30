/**
 * @param {number[]} nums
 * @return {string[]}
 */
var summaryRanges = function(nums) 
{
    let result = [];
    let start = 0;
    let flag = true;
    for(let i = 0; i < nums.length; i++)
    {
        if(flag) 
        {
            start = nums[i];
            flag = false;
        }
        if(nums[i]+1 != nums[i+1]) {
            let end = nums[i];
            if(start == end)
            {
                result.push(String(start));
            } else {
                result.push(String(start+"->"+end))
            }
            flag = true;
        }
    }   
    return result; 
};

let main = function()
{
    
}