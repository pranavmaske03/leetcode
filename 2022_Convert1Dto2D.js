
var construct2DArray = function(original, m, n) 
{
    let result = [];
    if(m*n != original.length) return result;

    for(let i = 0,k = 0; i < m; i++)
    {
        let  row = [];
        for(let j = 0; j < n; j++)
        {
            row.push(original[k++]);
        }
        result.push(row);
    }
    return result;
};

let main = function()
{
    let arr = [1,2,3,4];

    let result = construct2DArray(arr,2,2);
    console.log(result);
}

main();