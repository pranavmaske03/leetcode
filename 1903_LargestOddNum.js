

/**
 * @param {string} num
 * @return {string}
 */
var largestOddNumber = function(num) 
{
    let arr = num.split('');
    let i = 0;
    for(i = arr.length-1; i >= 0; i--) {
        if(Number(arr[i]) % 2) {
            arr.length = i+1;
            break;
        }
    }
    return i === -1 ? "" : arr.join('');
};

let main = function() {

    largestOddNumber("234345");
}

main();