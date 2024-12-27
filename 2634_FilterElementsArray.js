
// /**
//  * @param {number[]} arr
//  * @param {Function} fn
//  * @return {number[]}
//  */

var filter = function(arr, fn) 
{
    let result = [];
    let i = 0;
    arr.forEach(function(element) {
        let ret = fn(element,i++);
        if(ret) result.push(element);
    });
    return result;    
};