

/**
 * @param {string} s
 * @param {number[]} shifts
 * @return {string}
 */
var shiftingLetters = function(s, shifts) 
{
    let charArray = ['a', 'b', 'c', 'd', 'e', 'f','g', 'h', 'i', 'j', 'k', 'l','m', 'n', 'o', 'p', 'q', 'r','s', 't', 'u', 'v', 'w', 'x','y', 'z'];

     for(let i = shifts.length-2; i >= 0; i--) {
        shifts[i] += shifts[i+1];
    }
    
    s = s.split('');
    for(let i = 0; i < s.length; i++) {
        let index = charArray.indexOf(s[i]);
        let charShift = index + shifts[i];
        charShift %= 26;
        s[i] = charArray[charShift];
    }
    return s.join('');
};

let main = function() {
    let s = "ruu";
    let  shifts = [26,9,17];

    console.log(shiftingLetters(s,shifts))
}

main();