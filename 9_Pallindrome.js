
var isPalindrome = function(x) {   

    x = x.toString();
    let reverse = x.split('').reverse().join('');
    return reverse == x;
};

let main = function() {

    let num = 121;
    console.log(isPalindrome(num))
}

main()