

var lengthOfLongestSubstring = function(s) {
    
    let result = [];
    let max = 0;

    s = s.split('');
    console.log(s);
    s.forEach(element => {
        if(!result.includes(element))
        {
            result.push(element);
        } else {
            if(max < result.length) max = result.length;
            result.length = 0;
        }
    });
    return max;
};

let main = function() {
    let str = "abcdef";

    let result = lengthOfLongestSubstring(str);
    console.log(result);
};

main();