

/**
 * @param {string} s
 * @param {number[]} shifts
 * @return {string}
 */
var shiftingLetters = function(s, shifts) 
{
    for(let i = shifts.length-2; i >= 0; i--) {
        shifts[i] += shifts[i+1];
    }
    
    let str = s.split('');
    for(let i = 0; i < s.length; i++) {

        let code = s[i].charCodeAt(0); 
        str[i] = String.fromCharCode((shifts[i]+code));
    }
    return str.join('');
};

let main = function() {
    let s = "ruu";
    let  shifts = [26,9,17];

    console.log(shiftingLetters(s,shifts))
}

main();