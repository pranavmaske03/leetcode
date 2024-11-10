
let twoSum = function(arr,target) {

    let result = [];
    for(let i = 0; i < arr.length; i++) {

        for(let j = i+1; j < arr.length; j++) {
            
            if(arr[i] + arr[j] == target) {
                result.push(i);
                result.push(j);
                return result;
            }
        }
    }
    return null;
}

var twoSum1 = function(nums, target) {

    let map = {}
    for(let i = 0 ; i < nums.length ; i++){
        let diff = target-nums[i]
        if(diff in map){
            return [map[diff] , i]
        }
        map[nums[i]] = i 
    }
};

let main = function() {

    let arr = [1,2,3,4,5];
    let target = 8;

    let result = twoSum1(arr,target)
    console.log(result);
}

main();