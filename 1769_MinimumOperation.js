
/**
 * @param {string} boxes
 * @return {number[]}
 */
var minOperations = function(boxes) 
{
    let prefix = new Array(boxes.length).fill(0);
    let suffix = new Array(boxes.length).fill(0);

    // calculate the prefix sum of the 1;
    let temp = 0,cnt = 0;
    for(let i = 0; i < boxes.length; i++) {
        temp += cnt;
        prefix[i] = temp;
        if(boxes[i] == '1') cnt++;
    }
    // calculate the suffix sum of the 1;
    temp = 0,cnt = 0
    for(let i = boxes.length-1; i >= 0; i--) {
        temp += cnt;
        suffix[i] = temp;
        if(boxes[i] == '1') cnt++;
    }

    // calculate the total operations by adding suffix sum and prefix sum of the element;
    let ans = [];
    for(let i = 0; i < boxes.length; i++) {
        if(i == 0) {
            ans.push(suffix[i]);
        } else if(i == boxes.length-1) {
            ans.push(prefix[i]);
        } else {
            ans.push(prefix[i]+suffix[i]);
        } 
    }
    return ans;
};

let main = function() 
{
    let str = "001011"
    console.log(minOperations(str));
}

main();