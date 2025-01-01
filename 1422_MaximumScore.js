
/**
 * @param {string} s
 * @return {number}
 */


var maxScore = function(s) 
{
    s = s.split('');

    let zeros = 0,maxSum = 0;
    let ones = s.reduce((total,element) => (element == 1 ? total+1 : total),0);
    
    for(let i = 0; i < s.length-1; i++) {
        if(s[i] == '1') {
            ones--;
        } else {
            zeros++;
        }
        maxSum = Math.max(maxSum,zeros+ones);
    }
    return maxSum;
};


let main = function() {

    console.log(maxScore("00111"));
}

main();