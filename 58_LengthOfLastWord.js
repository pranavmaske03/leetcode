

var lengthOfLastWord = function(s) {
    
    s = s.trim();
    s = s.split(' ');
    let result = s[s.length - 1];
    return result.length;
};

let main = function() {

    let str = "   fly me   to   the moon  ";
    let result = lengthOfLastWord(str);

    console.log(result);
}

main();