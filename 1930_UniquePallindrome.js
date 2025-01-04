

/**
 * @param {string} s
 * @return {number}
 */

// using set 
var countPalindromicSubsequence = function(s) 
{
    let ans = 0;
    let letterIndex = new Set();     // map the unique character in the string s
    for(let char of s) 
    {   
        letterIndex.add(char);
    }
    console.log(letterIndex)

    for(let char of letterIndex) {
        let i = s.indexOf(char);           // get the first index of the character in the string ;
        let j = s.lastIndexOf(char);        // get the last charcter of the string in the string;

        let unique = new Set();             // map the unique character in between the first and last index of the character in the string;
        for (let k = i + 1; k < j; k++) {
            unique.add(s[k]);               // add the character to the set as set only store uniques
        }
        console.log(unique);
        ans += unique.size;             // add the size of the set to the ans we get count of the pallindromes;
    }
    return ans;
};

// another solution using array 

let countPalindromicSubsequence1 = function(s) 
{
    let first = new Array(26).fill(-1);
    let last = new Array(26).fill(-1);
    
    for (let i = 0; i < s.length; i++) {
        let curr = s[i].charCodeAt(0);

        if (first[curr - 97] == - 1) {
            first[curr - 97] = i;
        }  
        last[curr - 97] = i;
    }  
    console.log(first);
    let ans = 0;
    for (let i = 0; i < 26; i++) {
        if (first[i] == -1) {
            continue;
        }  
        let between = new Set();
        for (let j = first[i] + 1; j < last[i]; j++) {
            between.add(s[j]);
        } 
        ans += between.size;
    }
    
    return ans;
}



let main = function() 
{
    let s = "bbcbaba";
    console.log(countPalindromicSubsequence1(s));
}
main();