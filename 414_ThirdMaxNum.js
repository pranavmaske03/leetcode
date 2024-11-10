
function compare(a, b)
{
  if (a > b) return 1; 
  if (a == b) return 0;
  if (a < b) return -1;
}

var thirdMax = function(nums) {
    
    let max1 = 0;
    nums = nums.sort(compare);
    let c = 0;

    max1 = nums[nums.length-1];
    for(let i = nums.length-1; i >= 0; i--)
    {
        if(max1 > nums[i])
        {
            max1 = nums[i];

            c++;
            if(c == 2) break;
        }
    }
    if(nums.length < 3 || c < 2)  {
        return nums[nums.length-1];
    }

    return max1;
};

let main = function()
{
    let num = [3,2,1];
    console.log(thirdMax(num));
}

main();