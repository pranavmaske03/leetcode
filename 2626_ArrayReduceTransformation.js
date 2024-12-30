

// /**
//  * @param {number[]} nums
//  * @param {Function} fn
//  * @param {number} init
//  * @return {number}
//  */

var reduce = function(nums, fn, init) 
{
    
    let result = init;
    nums.forEach((element) => {
        result = fn(result,element);
    });
    return result;
};

let main = function() 
{
    let nums = [1,2,3,4]
    let fn = function sum(accum, curr) { return accum + curr; }
    let init = 0   

    console.log(reduce(nums,fn,init));
}

main();