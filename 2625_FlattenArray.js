
/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) 
{
    let result = [];
    if(n == 0) return arr;
    while(n--)
    {
        for(let val of arr) {
            if(val.length != undefined) {
                result.push(...val);
            } else {
                result.push(val);
            }
        }
        arr = result;
        result = [];
    }
    return arr;
};

let main = function() {
    flat();
}

main();