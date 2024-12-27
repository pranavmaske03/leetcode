

var groupAnagrams = function(strs) 
{
    let result = [];
    let anagram = [];

    for(let i = 0; i < strs.length; i++)
    {
        anagram[i] = strs[i].split('').sort().join('');
    }

    const map = new Map();

    for(let i = 0; i < anagram.length; i++)
    {
        if(map.has(anagram[i])) {
            map.get(anagram[i]).push(i);
        } else {
            map.set(anagram[i],[i]);
        }
    }

    map.forEach((values) => {
        let row = [];
        values.forEach(value => {
            row.push(strs[value]);
        });
        result.push(row);
    });
    return result;    
};

let main = function()
{
    let strs = ["eat","tea","tan","ate","nat","bat"];

    let result = groupAnagrams(strs);

    console.log(result);
}

main();