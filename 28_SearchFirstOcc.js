

var strStr = function(haystack, needle) {
      
    return haystack.indexOf(needle);
};

let main = function()
{
    let str = "leetcode";
    let substr = "leet";

    let result = strStr(str,substr);
    console.log(result);
}

main();