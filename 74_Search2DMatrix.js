
var searchMatrix = function(matrix, target) 
{
    for(let i = 0; i < matrix.length; i++)    
    {
        for(j = 0; j < matrix[i].length; j++)
        {
            if(matrix[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
};

let main = function()
{
    let matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]];
    console.log(searchMatrix(matrix,3));
}

main();