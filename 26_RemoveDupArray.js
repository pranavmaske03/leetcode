

var removeDuplicates = function(nums) {

    let startIndex = 1;

    for(let i = 1; i < nums.length; i++) {
        if (nums[i] !== nums[i - 1]) {
            nums[startIndex] = nums[i]
            startIndex++
        }
    }
    return startIndex;
};

let main = function() {

    let arr = [1,1,1,2,2,2,4,4,5,6,7,7,8,8,9,9,9];
    let result = removeDuplicates(arr)
    console.log(result);
}

main();