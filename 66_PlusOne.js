
var plusOne = function(digits) 
{
    let flag = false;

    for(let i = digits.length-1; i >= 0; i++)
    {
        if(digits[i] == 9)
        {
            digits[i] = 0;
            if(i == 0) flag = true;
            continue;
        }
        else
        {
            digits[i]++;
            break;
        }
    }
    if(flag == true)
    {
        digits[0] = 1;
        digits.push(0);
    }
    return digits;
};

function main()
{   
    let arr = [6,1,4,5,3,9,0,1,9,5,1,8,6,7,0,5,5,4,3];

    console.log(plusOne(arr));
}

main();