
var addBinary = function(a, b) 
{
    const aBin = `0b${a}`
    const bBin = `0b${b}`
    const sum = BigInt(aBin) + BigInt(bBin)
    return sum.toString(2)
};

let main = function()
{
    let str1 = "11";
    let str2 = "1";

    console.log(addBinary(str1,str2));
}

main();