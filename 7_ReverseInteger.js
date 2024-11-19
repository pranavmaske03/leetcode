

var reverse = function(x) {
    
    let result = 0; 
    if(x < 0) {
        x = -x;
        x = x.toString();
        result = Number(x.split('').reverse().join(''));
        result = -result;
    } else {
        x = x.toString();
        result = Number(x.split('').reverse().join(''));
    }
    if(result < -2147483648 || result > 2147483647) {
        return 0;
    } else {
        return result;
    }
};

let main = function() {

    let num = -12223;
    console.log(reverse(num))
}

main()
