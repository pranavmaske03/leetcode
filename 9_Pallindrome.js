
var isPalindrome = function(x) {   

    x = x.toString();
    let reverse = x.split('').reverse().join('');
    return reverse == x;
};

var isPalindrome1 = function (x) {
    if (x < 0 || (x % 10 === 0 && x !== 0)) return false;

    let reversedHalf = 0;
    while (x > reversedHalf) {
        reversedHalf = reversedHalf * 10 + (x % 10);
        x = Math.floor(x / 10);
    }
    return x === reversedHalf || x === Math.floor(reversedHalf / 10);
};

let main = function() {

    let num = 121;
    console.log(isPalindrome(num))
}

main()