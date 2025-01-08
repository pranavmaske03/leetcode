

var groupAnagrams = function(strs) 
{
    const map = new Map();

    for(let i = 0; i < strs.length; i++)
    {
        let key = strs[i].split('').sort().join('');

        if(map.has(key)) {
            map.get(key).push(strs[i]);
        } else {
            map.set(key,[strs[i]]);
        }
    }
    console.log(map);
    const result = Array.from(map.values());
    return result;
};

var groupAnagrams1 = function(strs) 
{
    let result = {};

    for(let i = 0; i < strs.length; i++) 
    {
        let key = strs[i].split('').sort().join('');
        
        if(!result[key]) 
        {
            result[key] = [];
        }
        result[key].push(strs[i]);
    }
    return Object.values(result);
};

let main = function()
{
    let strs = ["eat","tea","tan","ate","nat","bat"];

    let result = groupAnagrams(strs);

    console.log(result);
}

main();