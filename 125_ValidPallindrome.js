

var isPalindrome = function(s) {
    s = s.replace(/[^a-zA-Z0-9]/g, '');
    s = s. toLowerCase();

    let first = 0;
    let last = s.length-1;

    while(first < last)
    {
        if(s[first] != s[last])
        {
            return false;
        }
        first++;
        last--;
    }
    return true;
};

let main = function()
{
    let s = "0P";
    let result = isPalindrome(s);
    console.log(result);
}

main();