

/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) 
{
    let triangle = [];
  
    for(let i = 0;i < numRows;i++) {
        let row = Array(i+1).fill(1);

        for(let j = 1;j < i;j++) {
            row[j] = triangle[i-1][j-1] + triangle[i - 1][j];
        }
        triangle.push(row);
    }  
    return triangle;
}

let main = function() {

    console.log(generate(3));
}

main();

  