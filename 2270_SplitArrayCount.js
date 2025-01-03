

/**
 * @param {number[]} nums
 * @return {number}
 */
var waysToSplitArray = function(nums) 
{
    let splitCount = 0;
    const prefixSum = new Array(nums.length);

    prefixSum[0] = nums[0];
    for(let i = 1; i < nums.length; i++) {
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }
    for(let i = 0; i < prefixSum.length-1; i++) {
        const leftSum = prefixSum[i];
        const rightSum = prefixSum.at(-1) - prefixSum[i];
        
        if(leftSum >= rightSum) splitCount++;
    }
    return splitCount;
};

function main() {
    let nums = [2,3,1,0];

    console.log(waysToSplitArray(nums));
}

main();