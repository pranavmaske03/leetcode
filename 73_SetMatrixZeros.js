
var setZeroes = function(matrix) {

    for(let i = 0; i < matrix.length; i++)
    {
        for(let j = 0; j < matrix[i].length; j++)
        {
            if(matrix[i][j] == 0)
            {
                for(let k = 0; k < matrix.length; k++)
                {
                    if(matrix[k][j] != 0)
                    {
                        matrix[k][j] = -99999;
                    }
                }
                for(let k = 0; k < matrix[i].length; k++)
                {
                    if(matrix[i][k] != 0)
                    {
                        matrix[i][k] = -99999;
                    }
                }
            }
        }
    }
    for(i = 0; i < matrix.length; i++)
    {
        for(j = 0; j < matrix[i].length; j++)
        {
            if(matrix[i][j] == -99999)
            {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
};

let main = function()
{
    let matrix = [[0,1]];

    console.log(setZeroes(matrix));
}

main();