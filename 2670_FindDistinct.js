
// /**
//  * @param {number[]} nums
//  * @return {number[]}
// **/

var distinctDifferenceArray = function(nums) 
{
  
   const result = [];
   const n = nums.length;
   const prefix = [];
   const suffix = [];
   const prefixset = new Set();
   const suffixset = new Set();

   for(let i = 0;i < n;i++)
   {
      prefixset.add(nums[i]);
      prefix.push(prefixset.size);
      suffix.push(suffixset.size);
      suffixset.add(nums[n-i-1]);
   }
   for(let i = 0;i < n;i++)
   {
      result.push(prefix[i] - suffix[n-i-1]);
   }
   return result;
};

