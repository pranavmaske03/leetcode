

/**
 * @param {number[]} nums
 * @return {number}
 */
var triangleNumber = function(nums) 
{
        nums = nums.sort((a,b) => a-b);
        let n = nums.length;
        let res = 0;
        for(let k = n - 1; k >= 2; k--) {
            // check on the left of k, how many pairs will have sum less than nums[k]
            let i = 0;
            let j = k - 1;
            while(i < j) {
                if(nums[i] + nums[j] > nums[k]) {
                    res += j - i; // all the pairs {i from i to j - 1, j} can make triangle
                    j--;
                } else {
                    i++;
                }
            }
        }
        
        return res;
};

let main = function() {

    let nums = [2,2,3,4];

    console.log(triangleNumber(nums));
}

main();